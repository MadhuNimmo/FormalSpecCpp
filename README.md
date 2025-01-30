# FormalSpecCpp: A Dataset for C++ Formal Specifications 

[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.#######.svg)](https://doi.org/10.5281/zenodo.#######)
[![GitHub stars](https://img.shields.io/github/stars/yourrepo.svg?style=social)](https://github.com/yourrepo/stargazers)
[![License: CC BY 4.0](https://img.shields.io/badge/license-CC%20BY%204.0-blue.svg)](LICENSE)

**FormalSpecCpp** is a benchmark designed to evaluate **formal specification inference tools** for C++. It provides **105 C++ programs** generated with **formal preconditions and postconditions**, along with **associated test cases**. This dataset is the **first comprehensive benchmark for C++ specification inference**.

**📢 This benchmark was published in MSR 2025!** 🎉

## 🚀 Why Use This Benchmark?
- Standardized dataset for evaluating **C++ formal specifications**.
- Facilitates **automated verification and testing** of C++ programs.

## 📜 Table of Contents
- [Overview](#overview)
- [Installation](#installation)
- [Dataset Details](#dataset-details)
- [Usage](#usage)
- [Benchmarking](#benchmarking)
- [Contributing](#contributing)
- [Citation](#citation)
- [License](#license)

---

## Dataset Details

### 📊 Dataset Statistics
- **105 C++ programs** with **formal preconditions & postconditions**.
- **Generated from Dafny programs** using GPT-4-turbo.
- **Automatically translated and manually verified test cases** for validation.

### 🛠️ Dataset Structure
```
FormalSpecCpp/
│── FormalSpecCPP/                    # Translated C++ programs
│── FormalSpecCPP-Tests/              # Associated test cases
│── FormalSpecCpp-Generator/          # Scripts for translation & testing
│── README.md
│── LICENSE
```

### 📥 Download the Dataset (Alternative)
- [Hugging Face](https://huggingface.co/datasets/###)

### 📌 Use Cases
- **LLM Benchmarking**: Evaluate AI-based program verification.
- **Testing Specification Inference**: Compare formal verification tools.
- **C++ Education**: Teaching contract-based programming.

---

## 🚀 Quick Start

### Installation
#### 🔹 **For Dataset Users**
```bash
pip install -r requirements.txt
```
#### 🔹 **For Contributors**
```bash
git clone <repository_url>
cd FormalSpecCpp
python -m venv venv
source venv/bin/activate   # Linux/Mac
venv\Scripts\activate      # Windows
pip install -r requirements.txt
```

### Running the Pipeline
```bash
make generate_benchmark  # Generates C++ programs
make run_tests           # Runs all test cases
```

---

## Repository Structure

Your benchmark can be **more reusable** if structured like a standard ML dataset repository. **Consider splitting** it into **two repositories**:

| Repo | Purpose |
|------|---------|
| **FormalSpecCpp-Dataset** | Contains the **C++ programs + test cases** only. |
| **FormalSpecCpp-Generator** | Contains the **scripts and LLM pipelines** used to generate the dataset. |

### 📌 New Structure
```
FormalSpecCpp-Dataset/
│── programs/
│── tests/
│── metadata.json       # Describes dataset contents
│── README.md
│── LICENSE (CC BY 4.0)

FormalSpecCpp-Generator/
│── scripts/
│── requirements.txt
│── dfy2cpp.py
│── getTests.py
│── run_tests.py
│── README.md
│── LICENSE (MIT)
```

---

## Citation
If you use FormalSpecCpp in your work, please cite our paper:
```
@inproceedings{chakraborty2024formalspeccpp,
  author    = {Madhurima Chakraborty and Peter Pirkelbauer and Qing Yi},
  title     = {FormalSpecCpp: A Dataset of C++ Formal Specifications Created Using LLMs},
  booktitle = {MSR 2025},
  year      = {2025}
}
```

## License
- **Dataset (C++ Programs + Test Cases):** Licensed under **[CC-BY 4.0](https://creativecommons.org/licenses/by/4.0/)**.
- **Code (Scripts for Benchmark Generation & Testing):** Licensed under **MIT License**.
By using this dataset, you agree to **cite our work** and follow the license terms.