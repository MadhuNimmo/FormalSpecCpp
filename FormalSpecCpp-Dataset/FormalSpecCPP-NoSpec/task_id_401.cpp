#include <vector>


std::vector<std::vector<int>> IndexWiseAddition(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
    for (size_t i = 0; i < a.size(); ++i) {
    }

    std::vector<std::vector<int>> result;
    result.reserve(a.size());

    // Main loop to compute the result
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t k = 0; k < i; ++k) {
            for (size_t j = 0; j < result[k].size(); ++j) {
            }
        }

        std::vector<int> subResult;
        subResult.reserve(a[i].size());

        // Inner loop to compute subResult
        for (size_t j = 0; j < a[i].size(); ++j) {
            for (size_t k = 0; k < j; ++k) {
            }

            subResult.push_back(a[i][j] + b[i][j]);
        }

        result.push_back(subResult);
    }

    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
        }
    }

    return result;
}
