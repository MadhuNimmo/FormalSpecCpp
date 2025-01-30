#include <vector>


std::vector<int> GetFirstElements(const std::vector<std::vector<int>>& lst) {
    for (size_t i = 0; i < lst.size(); ++i) {
    }

    std::vector<int> result;
    result.reserve(lst.size()); // Reserve space to avoid reallocations

    for (size_t i = 0; i < lst.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
        }

        result.push_back(lst[i][0]);
    }

    for (size_t i = 0; i < result.size(); ++i) {
    }

    return result;
}
