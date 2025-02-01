import os
import json
import re
import argparse
from openai import OpenAI

# OpenAI client initialization
client = OpenAI()

# Constants for token pricing
PRICE_PER_1K_INPUT_TOKENS = 0.01  # Price per 1000 input tokens
PRICE_PER_1K_OUTPUT_TOKENS = 0.03  # Price per 1000 output tokens

# Define the test function format
test_function_format = """
{headers}  // Required headers for the function

void {function_name}() {{
    // Test case 1
    {function_call_1}
    assert({assert_1});

    // Test case 2
    {function_call_2}
    assert({assert_2});

    // Test case 3
    {function_call_3}
    assert({assert_3});
}}

int main() {{
    {function_name}();
    return 0;
}}
"""

# Read JSON data from the file
def read_json(file_path):
    with open(file_path, 'r') as json_file:
        return json.load(json_file)

# Extract the function name from the C++ file
def extract_function_name(file_path):
    with open(file_path, 'r') as cpp_file:
        cpp_code = cpp_file.read()
        
        # Regular expression to match function definitions (handles any return type and parameters)
        # This will match any return type, including void, int, etc., followed by function name and parameters.
        pattern = r'^\b(.+)\s+(.+)\s*\((.*)\)(\s*)\{'

        # Find all matches for function definitions
        function_names = re.findall(pattern, cpp_code, re.MULTILINE)
        if function_names:
            # Return the last function name in the list
            return function_names[-1][1]
        else:
            print(f"No function names found in file: {file_path}")
            return None

# Use OpenAI API to convert Dafny test case to C++
def convert_test_case_to_cpp(test_case, function_name):
    prompt = f"""
    Convert the following Dafny test case into a C++ test function to test the function {function_name} in the following format:
    {test_function_format}
    The test cases are as follows:
    {test_case}

    The C++ function should include only the test logic. Assume the function {function_name} is already defined in a separate file and will be included in the test file.
    """
    
    max_retries = 5
    for attempt in range(max_retries):
        # API call format for `chat.completions.create`
        response = client.chat.completions.create(
            model="gpt-4-turbo",
            messages=[
                {"role": "system", "content": "You are an expert AI assistant that converts Dafny to C++ programs."},
                {"role": "user", "content": prompt}
            ],
            max_tokens=500,
            temperature=0
        )
        
        # Extract the C++ test code from the response
        response_text = response.choices[0].message.content.strip()
        input_tokens = response.usage.total_tokens  # Track total tokens used for the request
        output_tokens = response.usage.completion_tokens  # Tokens used for the completion response
        extracted_code = extract_code(response_text)
        
        if extracted_code:
            return extracted_code, input_tokens, output_tokens
        else:
            print(f"Attempt {attempt + 1} failed. Retrying...")

    print("Failed to convert test case to C++ after multiple attempts.")
    return None, 0, 0

def extract_code(response_text: str) -> str:
    # Use regex to find the content between triple backticks
    code_match = re.search(rf"```cpp(.*?)```", response_text, re.DOTALL)
    
    if code_match:
        try:
            code_block = code_match.group(1).strip()
            return code_block
        except Exception as e:
            print(f"Incomplete code extraction: {e}")
            return None
    else:
        print("No code block found or incomplete code.")
        return None

# Write the generated C++ test code to a file
def write_cpp_test_file(output_dir, file_name, cpp_test_code, input_dir):
    # Create the test file path using the function name
    test_file_name = file_name.replace('.cpp', '_test.cpp')
    test_file_path = os.path.join(output_dir, test_file_name)
    # Write the C++ test code to the file with the #include statement for the existing C++ file
    if cpp_test_code is not None:
        with open(test_file_path, 'w') as test_file:
            include_statement = f'#include "{file_name}"\n\n'
            test_file.write(include_statement)
            test_file.write(cpp_test_code)

    print(f"Generated C++ test file: {test_file_path}")

def check_file_in_directory(directory_path, file_name):
    file_path = os.path.join(directory_path, file_name)
    return os.path.isfile(file_path)

# Main function to read JSON and generate C++ test files
def main(json_file_path, output_dir, input_dir):
    # Read JSON data
    tasks = read_json(json_file_path)
    # Ensure the output directory exists
    os.makedirs(output_dir, exist_ok=True)

    # Initialize cost calculation
    total_input_tokens = 0
    total_output_tokens = 0
    total_cost = 0

    # Process each task and generate the corresponding C++ test file
    for task_id, task_data in tasks.items():
        file_name = f"task_id_{task_id}.cpp"
        task_file_path = os.path.join(input_dir, file_name)

        # Only proceed if the corresponding C++ file exists in the input directory
        if check_file_in_directory(input_dir, file_name):
            print(f"Generating test for: {file_name}")
            
            # Extract function name from the C++ file
            function_name = extract_function_name(task_file_path)
            if function_name:
                # Generate the C++ test code from the test cases
                test_cases = task_data['test_cases']
                cpp_test_code, input_tokens, output_tokens = convert_test_case_to_cpp(test_cases, function_name)
                
                # Write the C++ test code to a file
                write_cpp_test_file(output_dir, file_name, cpp_test_code, input_dir)
                
                # Update the token counts
                total_input_tokens += input_tokens
                total_output_tokens += output_tokens
                
                # Calculate the cost
                input_cost = (input_tokens / 1000) * PRICE_PER_1K_INPUT_TOKENS
                output_cost = (output_tokens / 1000) * PRICE_PER_1K_OUTPUT_TOKENS
                total_cost += input_cost + output_cost

    print(f"Total input tokens: {total_input_tokens}")
    print(f"Total output tokens: {total_output_tokens}")
    print(f"Total translation cost: ${total_cost:.4f}")

# Run the main function
if __name__ == "__main__":
    # Set up argument parser
    parser = argparse.ArgumentParser(description="Generate C++ test files from Dafny test cases.")
    parser.add_argument('json_file_path', type=str, help="Path to the input JSON file containing test cases.")
    parser.add_argument('--output', type=str, help="Directory where the C++ test files will be saved.")
    parser.add_argument('--input', type=str, help="Directory where the original C++ files are located.")
    
    args = parser.parse_args()

    # Run the main function with the provided arguments
    main(args.json_file_path, args.output, args.input)
