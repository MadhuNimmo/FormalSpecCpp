#include <vector>


std::vector<double> ElementWiseDivision(const std::vector<int>& a, const std::vector<int>& b) {

    std::vector<double> result;
    result.reserve(a.size());

    // Loop to perform element-wise division
    for (size_t i = 0; i < a.size(); ++i) {
        result.push_back(a[i] / b[i]);
    }

    return result;
}
