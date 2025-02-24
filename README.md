# FormalSpecCpp: A Dataset for C++ Formal Specifications 

[![DOI](https://img.shields.io/badge/DOI-10.48550/arXiv.2502.15217-blue)](https://doi.org/10.48550/arXiv.2502.15217)
[![License: CC BY 4.0](https://img.shields.io/badge/license-CC%20BY%204.0-blue.svg)](LICENSE)

**FormalSpecCpp** is a benchmark designed to evaluate **formal specification inference tools** for C++. It provides **105 C++ programs** with **formal preconditions and postconditions**, along with **associated test cases**. This dataset is the **first comprehensive benchmark for C++ specification inference**.

**📢 This benchmark was published in MSR 2025!** 🎉

## 🚀 Why Use This Benchmark?
- Standardized dataset for evaluating **C++ formal specifications**.
- Facilitates **automated verification and testing** of C++ programs.

## 📊 Dataset Statistics
- **105 C++ programs** with **formal preconditions & postconditions**.
- **Generated from Dafny programs** using GPT-4-turbo.
- **Automatically translated and manually verified test cases** for validation.

### 🛠️ Dataset Structure

| Directory | Purpose |
|------|---------|
| **FormalSpecCpp-Dataset** | Main dataset containing translated C++ programs and test cases. |
| ├── **FormalSpecCpp/** | C++ programs with formal specifications. |
| ├── **FormalSpecCpp-Tests/** | Corresponding test cases for the translated programs. |
| └── **FormalSpecCpp-NoSpec/** | C++ programs without formal specifications. |
| **FormalSpecCpp-Scripts** | Contains the scripts and LLM pipelines used to generate the dataset. |

### 📥 Download the Dataset (Alternative)
- [Hugging Face](https://huggingface.co/datasets/###)

### 📌 Use Cases
- **LLM Benchmarking**: Evaluate AI-based program verification.
- **Testing Specification Inference**: Compare formal verification tools.
- **C++ Education**: Teaching contract-based programming.

### 🧪 Running Tests
To run the test cases for the dataset, use the run_tests.py script located in the FormalSpecCpp-Scripts directory.
You need to specify the appropriate test and include directories:

To run tests on code with formal specifications, use:
```bash
python FormalSpecCpp-Scripts/run_tests.py --test_dir FormalSpecCpp-Dataset/FormalSpecCPP-Tests --include_dir FormalSpecCpp-Dataset/FormalSpecCPP
```

To run tests on code without formal specifications, use:
```bash
python FormalSpecCpp-Scripts/run_tests.py --test_dir FormalSpecCpp-Dataset/FormalSpecCPP-Tests --include_dir FormalSpecCpp-Dataset/FormalSpecCPP-NoSpec
```

## Citation
If you use FormalSpecCpp in your work, kindly cite our paper:
```
@misc{chakraborty2025formalspeccppdatasetcformal,
      title={FormalSpecCpp: A Dataset of C++ Formal Specifications created using LLMs}, 
      author={Madhurima Chakraborty and Peter Pirkelbauer and Qing Yi},
      year={2025},
      eprint={2502.15217},
      archivePrefix={arXiv},
      primaryClass={cs.SE},
      url={https://arxiv.org/abs/2502.15217}, 
}
```

## License
- **Dataset (C++ Programs + Test Cases) and Code:** Licensed under **[CC-BY 4.0](https://creativecommons.org/licenses/by/4.0/)**.
By using this dataset, you agree to **cite our work** and follow the license terms.
