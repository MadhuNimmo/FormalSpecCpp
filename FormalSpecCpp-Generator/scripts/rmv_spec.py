import os
import re

# Define paths
source_dir = "/Users/madhurimachakraborty/Documents/GitHub/FormalSpecCpp/FormalSpecCpp-Dataset/FormalSpecCPP"  # Replace with actual path
destination_dir = "/Users/madhurimachakraborty/Documents/GitHub/FormalSpecCpp/FormalSpecCpp-Dataset/FormalSpecCPP-NoSpec"  # Replace with actual path

# Ensure the destination directory exists
os.makedirs(destination_dir, exist_ok=True)

# Define patterns for single-line removals
spec_patterns = [
    r'^\s*#define\s+REQUIRE\(.*\)',  # Remove REQUIRE macro definition
    r'^\s*#define\s+ENSURE\(.*\)',   # Remove ENSURE macro definition
    r'^\s*#include\s*<cassert>',     # Remove #include <cassert>
    r'^\s*REQUIRE\(.*\);',           # Remove REQUIRE(...) usage
    r'^\s*ENSURE\(.*\);',            # Remove ENSURE(...) single-line usage
    r'^\s*contract_assert\(.*\);',   # Remove contract_assert(...)
    r'^\s*assert\(.*\);',            # Remove standard assertions
    r'^\s*//.*(precondition|postcondition|loop invariant|Required macro definitions).*',  # Remove single-line comments
]

# Function to remove specifications and clean formatting
def clean_file(file_path, new_file_path):
    with open(file_path, "r") as infile:
        lines = infile.readlines()

    cleaned_lines = []
    inside_multiline_comment = False
    inside_ensure_or_assert = False  # Track if inside an ENSURE or assert block

    for line in lines:
        stripped_line = line.strip()

        # Handle multi-line block comments (/* ... */)
        if "/*" in stripped_line:
            inside_multiline_comment = True
        if "*/" in stripped_line:
            inside_multiline_comment = False
            continue  # Skip the closing line of the comment
        if inside_multiline_comment:
            continue

        # Handle multi-line ENSURE or assert blocks
        if re.match(r'^\s*(ENSURE|assert)\(.*', stripped_line):
            inside_ensure_or_assert = True
        if inside_ensure_or_assert:
            if ");" in stripped_line:  # End of the ENSURE or assert block
                inside_ensure_or_assert = False
            continue  # Skip all lines inside the block

        # Remove single-line matches
        if not any(re.search(pattern, line, re.IGNORECASE) for pattern in spec_patterns):
            cleaned_lines.append(line.rstrip())  # Strip trailing whitespace

    # Remove leading and trailing blank lines
    while cleaned_lines and cleaned_lines[0] == "":
        cleaned_lines.pop(0)
    while cleaned_lines and cleaned_lines[-1] == "":
        cleaned_lines.pop()

    # Write cleaned content to the new file
    with open(new_file_path, "w") as outfile:
        outfile.write("\n".join(cleaned_lines) + "\n")  # Ensure a single newline at EOF

# Process each C++ file in the source directory
for filename in os.listdir(source_dir):
    if filename.endswith(".cpp") or filename.endswith(".h"):  # Adjust for headers if needed
        src_file = os.path.join(source_dir, filename)
        dest_file = os.path.join(destination_dir, filename)
        
        clean_file(src_file, dest_file)

print(f"Processed {len(os.listdir(destination_dir))} files. Clean versions are in {destination_dir}.")
