#include <vector>


std::vector<int> MultiplyElements(const std::vector<int>& a, const std::vector<int>& b) {

    std::vector<int> result;
    result.reserve(a.size()); // Reserve space to avoid reallocations

    // Loop to multiply elements
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t k = 0; k < i; ++k) {
        }

        result.push_back(a[i] * b[i]);
    }

    return result;
}
