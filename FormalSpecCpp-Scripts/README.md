# FormalSpecCPP

This repository contains the script to convert Dafny code to C++ code using OpenAI's GPT-4turbo model, compiles the generated code, and handles any compilation errors by iteratively refining the code using the AI model. It also, contains the script to generate the associated testcases and run the tests on the programs.

## Requirements

- Python 3.9+
- A valid OpenAI API key
- GCC (g++) installed on your machine for C++ compilation

## Installation

1. **Clone or Download the Repository:**

   Download the repository or clone it using Git:

   ```bash
   git clone <repository_url>
   ```

2. **Set Up the OpenAI API Key:**

   Export your OpenAI API key as an environment variable:

   ```bash
   export OPENAI_API_KEY='your_openai_api_key'
   ```

   Replace `'your_openai_api_key'` with your actual API key.

3. **Installation Steps:**

  Create a Virtual Environment:

  ```bash
  python -m venv venv
  source venv/bin/activate  # For Linux/Mac
  venv\Scripts\activate     # For Windows
  ```

  Install the Required Libraries:

  ```bash
  pip install -r requirements.txt
  ```
## Usage

1. **Prepare Your Dafny Files:**

   The Dafny files used in this script are sourced from the [Mondego/dafny-synthesis](https://github.com/Mondego/dafny-synthesis) repository. Place your Dafny files (`.dfy` files) in a directory of your choice.

2. **Run the Script:**

   Execute the script using Python, the directory containing your Dafny files, the output directory and the analysis directory:

   ```bash
   python3 dfy2cpp.py /path/to/dafny/files/directory/ --output /path/to/program/output/directory/ --analysis /path/to/analysis/directory/
   ```
   Ideally, you should be using the file MBPP-DFY-153/src/ in the dafny-synthesis directory.

   ```bash
   python3 getTests.py /path/to/dafny/file/with/the/tests --output /path/to/test/output/directory/ --input /path/to/input/directory/
   ```
   Ideally, you should be using the file MBPP-san-DFY-228/mbpp-san-dfy-228-all-task-test.json in the dafny-synthesis directory.


3. **Run Tests on the Generated C++ Programs:**

   To execute the generated test cases and validate the C++ programs, use:

   ```bash
   python3 run_tests.py --test_dir /path/to/test/output/directory/ --include_dir /path/to/program/output/directory/
   ```

## Limitations

- The script requires a stable internet connection for API calls to OpenAI.
- It relies on the quality of the AI model's responses for generating and correcting code.
- The script assumes the Dafny files contain valid code with appropriate assertions.