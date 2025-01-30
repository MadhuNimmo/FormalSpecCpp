#include <vector>


std::vector<int> AddLists(const std::vector<int>& a, const std::vector<int>& b) {

    std::vector<int> result;
    result.reserve(a.size()); // Reserve space to avoid reallocations

    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t k = 0; k < i; ++k) {
        }

        // Main operation
        result.push_back(a[i] + b[i]);
    }

    for (size_t i = 0; i < result.size(); ++i) {
    }

    return result;
}
