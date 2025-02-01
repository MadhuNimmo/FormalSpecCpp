
import os
import re
import subprocess
import ssl
import urllib3
import sys
import argparse
import time
import json
from tqdm import tqdm
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import numpy as np
from openai import OpenAI

# Disable SSL verification and warnings
ssl._create_default_https_context = ssl._create_unverified_context
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

class CostTracker:
    PRICE_PER_1K_INPUT_TOKENS = 0.01
    PRICE_PER_1K_OUTPUT_TOKENS = 0.03

    def __init__(self):
        self.conversions = []
        self.total_input_tokens = 0
        self.total_output_tokens = 0

    def add_conversion(self, file_name, input_tokens, output_tokens, success, attempts, 
                      conversion_time, code_metrics, compilation_errors):
        input_cost = (input_tokens / 1000) * self.PRICE_PER_1K_INPUT_TOKENS
        output_cost = (output_tokens / 1000) * self.PRICE_PER_1K_OUTPUT_TOKENS
        
        self.total_input_tokens += input_tokens
        self.total_output_tokens += output_tokens
        
        self.conversions.append({
            'file_name': file_name,
            'input_tokens': input_tokens,
            'output_tokens': output_tokens,
            'total_cost': input_cost + output_cost,
            'success': success,
            'attempts': attempts,
            'conversion_time': conversion_time,
            'code_metrics': code_metrics,
            'errors': compilation_errors  # New field for tracking errors
        })

    def get_statistics(self):
        if not self.conversions:
            return {}

        df = pd.DataFrame(self.conversions)
        total_conversions = len(df)
        successful_conversions = len(df[df['success']])
        total_attempts = df['attempts'].sum()
        total_cost = df['total_cost'].sum()
        
        return {
            'total_cost': total_cost,
            'total_conversions': total_conversions,
            'successful_conversions': successful_conversions,
            'success_rate': successful_conversions / total_conversions,
            'total_attempts': total_attempts,
            'average_attempts': total_attempts / total_conversions,
            'total_tokens': self.total_input_tokens + self.total_output_tokens
        }

def calculate_code_metrics(code):
    """Calculate basic code metrics."""
    lines = code.splitlines()
    return {
        'total_lines': len(lines),
        'non_empty_lines': len([l for l in lines if l.strip()]),
        'character_count': len(code),
        'function_count': len(re.findall(r'\b(function|method)\b', code))
    }

def extract_code(response_text):
    """Extract code from the API response."""
    code_match = re.search(r"```cpp(.*?)```", response_text, re.DOTALL)
    if code_match:
        return code_match.group(1).strip()
    print("No code block found or incomplete code.")
    return None

def convert_dafny(dafny_code, client):
    """Convert Dafny code to C++ using OpenAI API."""
    prompt = f"""Convert the following program in Dafny to C++. {dafny_code}  
Steps: 
1. Convert the Dafny program along with the assertions to C++. 
2. Identify the conditions under which the C++ program may fail. 
3. Determine the appropriate C++ integer types based on the following guidelines:
   - Use signed integer types (e.g., `int`, `long`) for variables that may take on negative values.
   - Use unsigned integer types (e.g., `unsigned int`, `size_t`) for variables constrained to non-negative values, as indicated by preconditions or invariants.
4.Add appropriate assumptions by using the REQUIRE macro specifically for preconditions, the assert macro specifically for loop invariants, and the ENSURE macro specifically for postconditions in the code to ensure that the program is correct.
5. Only output the final code; do not generate a main function. 
6. You must include the macro definitions for `REQUIRE` and `ENSURE` as follows: 

// Required macro definitions 
#define REQUIRE(cond) assert(cond) 
#define ENSURE(cond) assert(cond) 

// Your converted code here with the appropriate integer types, preconditions, invariants, and postconditions.
"""

    response = client.chat.completions.create(
        model="gpt-4-turbo",
        messages=[
            {"role": "system", "content": "You are an expert AI assistant that converts Dafny to C++ programs."},
            {"role": "user", "content": prompt}
        ],
        temperature=0,
        max_tokens=2000
    )
    
    return extract_code(response.choices[0].message.content.strip()), response

def compile_code(file_path):
    """Compile the generated C++ code."""
    result = subprocess.run(
        ["g++", "-std=c++11", "-c", file_path],
        capture_output=True,
        text=True
    )
    return result.returncode == 0, result.stderr

def save_code(code, output_directory, file_name):
    """Save the generated code to a file."""
    os.makedirs(output_directory, exist_ok=True)
    file_path = os.path.join(output_directory, file_name)
    with open(file_path, "w") as file:
        file.write(code)
    return file_path

def parse_compilation_errors(error_message):
    """Parse compilation errors into a single concatenated string without file directory details."""
    if not error_message:
        return ""
    
    errors = []
    for line in error_message.split('\n'):
        if line.strip():
            # Remove file paths at the start of the line
            cleaned_error = re.sub(r'^[^:]+:\d+:\d+:\s*', '', line).strip()
            errors.append(cleaned_error)
    
    # Join all error lines into a single string, separated by a newline and space for readability
    return ['\n'.join(errors)]

def process_single_file(file_path, output_directory, cost_tracker, client):
    """Process a single Dafny file."""
    print(f"Processing file: {file_path}")
    file_name = os.path.basename(file_path)
    
    if not contains_keywords(file_path, ["ensures", "requires"]):
        print(f"Skipping {file_name}: missing required keywords.")
        return
    
    with open(file_path, 'r') as file:
        dafny_code = file.read()
    
    # Calculate initial metrics
    dafny_metrics = calculate_code_metrics(dafny_code)
    
    start_time = time.time()
    attempts = 1
    max_attempts = 10
    compiled = False
    all_errors = []  # Initialize error list
    
    try:
        # Initial conversion
        code, response = convert_dafny(dafny_code, client)
        if not code:
            raise ValueError("Failed to extract code from API response")
        
        output_file_name = file_name.replace('.dfy', '.cpp')
        output_file_path = save_code(code, output_directory, output_file_name)
        
        # Compilation attempts
        while attempts <= max_attempts and not compiled:
            compiled, error_message = compile_code(output_file_path)
            if compiled:
                print(f"Successfully compiled {output_file_name} on attempt {attempts}")
            else:
                parsed_error_message = parse_compilation_errors(error_message)
                all_errors.extend(parsed_error_message)
                print(f"Compilation failed for {output_file_name} on attempt {attempts}")
                attempts += 1
                
                if attempts <= max_attempts:
                    fix_prompt = f"""The following code failed to compile:
{code}

Error messages:
{error_message}

Please fix the errors and provide the corrected code."""
                    
                    fixed_response = client.chat.completions.create(
                        model="gpt-4-turbo",
                        messages=[
                            {"role": "system", "content": "You are a helpful assistant."},
                            {"role": "user", "content": fix_prompt}
                        ]
                    )
                    
                    fixed_code = extract_code(fixed_response.choices[0].message.content.strip())
                    if fixed_code:
                        code = fixed_code  # Update the code variable
                        output_file_path = save_code(fixed_code, output_directory, output_file_name)
        
        # Record metrics
        cpp_metrics = calculate_code_metrics(code)
        conversion_time = time.time() - start_time
        
        cost_tracker.add_conversion(
            file_name=file_name,
            input_tokens=response.usage.prompt_tokens,
            output_tokens=response.usage.completion_tokens,
            success=compiled,
            attempts=attempts,
            conversion_time=conversion_time,
            code_metrics={
                'dafny': dafny_metrics,
                'cpp': cpp_metrics
            },
            compilation_errors=all_errors  # Add the compilation errors list
        )
        
    except Exception as e:
        print(f"Error processing {file_path}: {str(e)}")
        return

def generate_visualizations(cost_tracker, output_dir):
    """Generate analysis visualizations."""
    os.makedirs(output_dir, exist_ok=True)
    
    if not cost_tracker.conversions:
        print("No data to generate visualizations.")
        return
    
    # Convert list of dictionaries to DataFrame with flattened structure
    df = pd.json_normalize(
        cost_tracker.conversions,
        sep='_',
        max_level=2
    )
    
    # Calculate statistics
    total_conversions = len(df)
    successful_conversions = len(df[df['success'] == True])
    success_rate = successful_conversions / total_conversions if total_conversions > 0 else 0
    total_attempts = df['attempts'].sum()
    average_attempts = total_attempts / total_conversions if total_conversions > 0 else 0
    total_cost = df['total_cost'].sum()
    
    # Attempts Analysis
    plt.figure(figsize=(12, 6), dpi=120)
    
    # Create attempt count distribution for successful and failed conversions
    successful_attempts = df[df['success'] == True]['attempts'].value_counts().sort_index()
    failed_attempts = df[df['success'] == False]['attempts'].value_counts().sort_index()
    
    # Ensure we have all attempts from 1 to 10 represented
    all_attempts = range(1, 11)
    successful_attempts = successful_attempts.reindex(all_attempts, fill_value=0)
    failed_attempts = failed_attempts.reindex(all_attempts, fill_value=0)
    
    # Create the stacked bar plot
    plt.bar(all_attempts, successful_attempts.values, label='Successful', color='lightgreen', alpha=0.7)
    plt.bar(all_attempts, failed_attempts.values, bottom=successful_attempts.values, 
            label='Failed', color='lightcoral', alpha=0.7)
    
    plt.xlabel('Number of Attempts')
    plt.ylabel('Number of Programs')
    plt.title('Distribution of Conversion Attempts')
    plt.xticks(all_attempts)
    plt.legend()
    plt.grid(True, axis='y', linestyle='--', alpha=0.7)
    
    # Add value labels on the bars
    for i in all_attempts:
        successful = successful_attempts[i]
        failed = failed_attempts[i]
        if successful > 0:
            plt.text(i, successful/2, str(int(successful)), 
                    ha='center', va='center')
        if failed > 0:
            plt.text(i, successful + failed/2, str(int(failed)), 
                    ha='center', va='center')
    
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, 'attempts_distribution.png'))
    plt.close()
    
    # Code Metrics Comparison
    plt.figure(figsize=(12, 6), dpi=120)
    metrics_comparison = {
        'Dafny Lines': df['code_metrics_dafny_total_lines'].tolist(),
        'C++ Lines': df['code_metrics_cpp_total_lines'].tolist()
    }
    pd.DataFrame(metrics_comparison).boxplot()
    plt.title('Code Size Comparison')
    plt.ylabel('Number of Lines')
    plt.savefig(os.path.join(output_dir, 'code_metrics.png'))
    plt.close()
    
    # Generate detailed summary report
    with open(os.path.join(output_dir, 'analysis_report.md'), 'w') as f:
        f.write("# Conversion Analysis Report\n\n")
        
        f.write("## Overall Statistics\n")
        f.write(f"- Total files processed: {total_conversions}\n")
        f.write(f"- Successful conversions: {successful_conversions} ({success_rate*100:.1f}%)\n")
        f.write(f"- Total attempts across all files: {total_attempts}\n")
        f.write(f"- Average attempts per file: {average_attempts:.2f}\n")
        f.write(f"- Total cost: ${total_cost:.2f}\n")
        f.write(f"- Average cost per file: ${(total_cost/total_conversions):.2f}\n\n")
        
        f.write("## Attempt Distribution\n")
        f.write("Number of programs resolved at each attempt:\n")
        for attempt in all_attempts:
            successful = successful_attempts[attempt]
            failed = failed_attempts[attempt]
            if successful > 0 or failed > 0:
                f.write(f"- Attempt {attempt}:\n")
                f.write(f"  - Successful: {int(successful)}\n")
                f.write(f"  - Failed: {int(failed)}\n")
        
        f.write("\n## Code Metrics\n")
        avg_dafny_lines = df['code_metrics_dafny_total_lines'].mean()
        avg_cpp_lines = df['code_metrics_cpp_total_lines'].mean()
        max_dafny_lines = df['code_metrics_dafny_total_lines'].max()
        max_cpp_lines = df['code_metrics_cpp_total_lines'].max()
        
        f.write(f"- Average Dafny lines: {avg_dafny_lines:.1f}\n")
        f.write(f"- Average C++ lines: {avg_cpp_lines:.1f}\n")
        f.write(f"- Maximum Dafny lines: {max_dafny_lines}\n")
        f.write(f"- Maximum C++ lines: {max_cpp_lines}\n")
        f.write(f"- Average size increase: {((avg_cpp_lines/avg_dafny_lines)-1)*100:.1f}%\n")
        
        # Add detailed cost breakdown
        f.write("\n## Cost Breakdown\n")
        f.write("Cost per number of attempts:\n")
        for attempt in all_attempts:
            attempt_costs = df[df['attempts'] == attempt]['total_cost']
            if not attempt_costs.empty:
                f.write(f"- {attempt} attempt(s):\n")
                f.write(f"  - Number of files: {len(attempt_costs)}\n")
                f.write(f"  - Total cost: ${attempt_costs.sum():.2f}\n")
                f.write(f"  - Average cost: ${attempt_costs.mean():.2f}\n")
        
        # Add error analysis
        f.write("\n## Compilation Error Analysis\n")
        if 'errors' in df.columns:
            error_list = []
            for errors in df['errors']:
                if errors:  # Check if errors is not None/empty
                    error_list.extend(errors)
            
            if error_list:
                error_counts = pd.Series(error_list).value_counts()
                f.write("\nMost common compilation errors:\n")
                for error, count in error_counts.items():
                    f.write(f"- {error}: {count} occurrences\n")
            else:
                f.write("\nNo compilation errors recorded.\n")

def contains_keywords(file_path, keywords):
    """Check if file contains all specified keywords."""
    with open(file_path, 'r') as file:
        content = file.read()
        return all(keyword in content for keyword in keywords)

def main():
    parser = argparse.ArgumentParser(description="Convert Dafny files to C++ with analysis.")
    parser.add_argument("input_path", help="Path to input Dafny file or directory")
    parser.add_argument("--output", default="output", help="Output directory for converted files")
    parser.add_argument("--analysis", default="analysis", help="Directory for analysis results")
    
    args = parser.parse_args()
    
    # Initialize OpenAI client and cost tracker
    client = OpenAI()
    cost_tracker = CostTracker()
    
    # Process files
    if os.path.isfile(args.input_path):
        process_single_file(args.input_path, args.output, cost_tracker, client)
    elif os.path.isdir(args.input_path):
        files = [f for f in os.listdir(args.input_path) if f.endswith('.dfy')]
        for file in tqdm(files, desc="Processing files"):
            process_single_file(os.path.join(args.input_path, file), args.output, cost_tracker, client)
    else:
        print(f"Error: The path {args.input_path} does not exist.")
        sys.exit(1)
    
    # Generate analysis
    generate_visualizations(cost_tracker, args.analysis)
    
    # Save raw data
    with open(os.path.join(args.analysis, 'conversion_data.json'), 'w') as f:
        json.dump(cost_tracker.conversions, f, indent=2)
    
    print(f"\nAnalysis complete. Results saved in {args.analysis}")

if __name__ == "__main__":
    main()