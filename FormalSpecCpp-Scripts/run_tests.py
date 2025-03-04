import subprocess
import os
import argparse
import sys
from pathlib import Path

def compile_and_run_cpp(test_dir, include_dir):
    successful_runs = 0
    failed_runs = 0
    error_counts = {
        'CompilationError': 0,
        'LinkerError': 0,
        'AssertionError': 0,
        'OtherError': 0
    }
    
    # Save the original directory to return to it later
    original_dir = os.getcwd()
    
    try:
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
                    error_output = str(e)
                    if 'command not found' in error_output:
                        error_counts['CompilationError'] += 1
                        print(f"Compilation failed for {file}.")
                    elif 'undefined reference' in error_output:
                        error_counts['LinkerError'] += 1
                        print(f"Linker error in {file}.")
                    elif 'assertion failed' in error_output:
                        error_counts['AssertionError'] += 1
                        print(f"Assertion failed in {file}.")
                    else:
                        error_counts['OtherError'] += 1
                        print(f"Other error for {file}: {e}")
    finally:
        # Return to the original directory
        os.chdir(original_dir)
    
    # Reporting the results
    print("\nTest Summary:")
    print(f"Total tests: {successful_runs + failed_runs}")
    print(f"Successful runs: {successful_runs}")
    print(f"Failed runs: {failed_runs}")
    print(f"Errors:")
    for error_type, count in error_counts.items():
        print(f"  {error_type}: {count}")

def find_project_root():
    """
    Find the project root directory by looking for specific marker files/directories.
    This allows the script to work regardless of where it's called from.
    """
    # Start from the current working directory
    current_dir = Path.cwd()
    
    # Look up the directory tree for a maximum of 5 levels
    for _ in range(5):
        # Check if this directory has the expected subdirectories
        if (current_dir / "FormalSpecCpp-Dataset").exists() and (current_dir / "FormalSpecCpp-Scripts").exists():
            return current_dir
        
        # Move up one directory
        parent_dir = current_dir.parent
        if parent_dir == current_dir:  # Reached the root of the filesystem
            break
        current_dir = parent_dir
    
    # If we couldn't find the project root, return None
    return None

def main():
    # Parse command line arguments
    parser = argparse.ArgumentParser(description='Compile and run all .cpp test files in a directory.')
    parser.add_argument('--test_dir', type=str, help='Path to the directory containing the .cpp test files')
    parser.add_argument('--include_dir', type=str, help='Path to the include directory for header files')
    args = parser.parse_args()
    
    # Find the project root directory
    project_root = find_project_root()
    
    if project_root is None:
        print("Error: Could not find the project root directory.")
        print("Please run this script from within the FormalSpecCpp project directory structure.")
        sys.exit(1)
    
    # Convert relative paths to absolute paths, relative to project root
    if args.test_dir:
        test_dir = Path(args.test_dir)
        if not test_dir.is_absolute():
            test_dir = project_root / test_dir
    else:
        # Default test directory
        test_dir = project_root / "FormalSpecCpp-Dataset" / "FormalSpecCPP-Tests"
    
    if args.include_dir:
        include_dir = Path(args.include_dir)
        if not include_dir.is_absolute():
            include_dir = project_root / include_dir
    else:
        # Default include directory
        include_dir = project_root / "FormalSpecCpp-Dataset" / "FormalSpecCPP"
    
    # Convert to string for subprocess
    test_dir_str = str(test_dir)
    include_dir_str = str(include_dir)
    
    # Check if the directories exist
    if not test_dir.is_dir():
        print(f"Error: The test directory {test_dir_str} does not exist.")
        sys.exit(1)
    
    if not include_dir.is_dir():
        print(f"Error: The include directory {include_dir_str} does not exist.")
        sys.exit(1)
    
    print(f"Using test directory: {test_dir_str}")
    print(f"Using include directory: {include_dir_str}")
    
    # Compile and run tests in the directory
    compile_and_run_cpp(test_dir_str, include_dir_str)

if __name__ == "__main__":
    main()