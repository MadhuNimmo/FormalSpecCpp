#include <vector>


std::vector<double> ElementWiseDivision(const std::vector<int>& a, const std::vector<int>& b) {
    for (size_t i = 0; i < b.size(); ++i) {
    }

    std::vector<double> result;
    result.reserve(a.size());

    // Loop to perform element-wise division
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t k = 0; k < i; ++k) {
        }

        result.push_back(a[i] / b[i]);
    }

    for (size_t i = 0; i < result.size(); ++i) {
    }

    return result;
}
