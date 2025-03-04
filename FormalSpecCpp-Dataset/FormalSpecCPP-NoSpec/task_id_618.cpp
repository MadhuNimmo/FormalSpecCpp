#include <vector>


std::vector<double> ElementWiseDivide(const std::vector<int>& a, const std::vector<int>& b) {

    std::vector<double> result;
    result.reserve(a.size());

    for (size_t i = 0; i < a.size(); ++i) {
        result.push_back(static_cast<double>(a[i]) / b[i]);
    }

    return result;
}
