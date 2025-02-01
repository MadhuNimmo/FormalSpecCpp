import subprocess
import os
import argparse

# Function to compile and run each .cpp file in the specified directory
def compile_and_run_cpp(test_dir, include_dir):
    successful_runs = 0
    failed_runs = 0
    error_counts = {
        'CompilationError': 0,
        'LinkerError': 0,
        'AssertionError': 0,
        'OtherError': 0
    }

    # Change to the test directory
    os.chdir(test_dir)

    # Iterate over all .cpp files in the directory
    for file in os.listdir(test_dir):
        if file.endswith('.cpp'):
            # Get the base name of the file (without .cpp extension)
            base_name = os.path.splitext(file)[0]
            
            # Compile the file
            print(f"Compiling {file}...")
            compile_command = ['g++', f'-I{include_dir}', '-std=c++11', '-w', file, '-o', base_name]
            try:
                subprocess.run(compile_command, check=True)
                print(f"Running {base_name}...")
                # Run the compiled file
                subprocess.run(['./' + base_name], check=True)
                print("--------------------------------------------------")
                successful_runs += 1
            except subprocess.CalledProcessError as e:
                failed_runs += 1
                # Check the type of error
                if 'command not found' in str(e):
                    error_counts['CompilationError'] += 1
                    print(f"Compilation failed for {file}.")
                elif 'undefined reference' in str(e):
                    error_counts['LinkerError'] += 1
                    print(f"Linker error in {file}.")
                elif 'assertion failed' in str(e):
                    error_counts['AssertionError'] += 1
                    print(f"Assertion failed in {file}.")
                else:
                    error_counts['OtherError'] += 1
                    print(f"Other error for {file}: {e}")
    
    # Reporting the results
    print("\nTest Summary:")
    print(f"Total tests: {successful_runs + failed_runs}")
    print(f"Successful runs: {successful_runs}")
    print(f"Failed runs: {failed_runs}")
    print(f"Errors:")
    for error_type, count in error_counts.items():
        print(f"  {error_type}: {count}")

def main():
    # Parse command line arguments
    parser = argparse.ArgumentParser(description='Compile and run all .cpp test files in a directory.')
    parser.add_argument('--test_dir', type=str, help='Path to the directory containing the .cpp test files')
    parser.add_argument('--include_dir', type=str, help='Path to the include directory for header files')
    args = parser.parse_args()

    script_dir = os.path.dirname(os.path.abspath(__file__))

    test_dir = os.path.abspath(os.path.join(script_dir, "../../", args.test_dir)) if not os.path.isabs(args.test_dir) else args.test_dir
    include_dir = os.path.abspath(os.path.join(script_dir, "../../", args.include_dir)) if not os.path.isabs(args.include_dir) else args.include_dir


    # Check if the directory exists
    if not os.path.isdir(test_dir):
        print(f"Error: The directory {test_dir} does not exist.")
        return

    # Compile and run tests in the directory
    compile_and_run_cpp(test_dir, include_dir)

if __name__ == "__main__":
    main()
