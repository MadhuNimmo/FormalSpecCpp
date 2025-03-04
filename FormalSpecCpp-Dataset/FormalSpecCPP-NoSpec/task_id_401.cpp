#include <vector>


std::vector<std::vector<int>> IndexWiseAddition(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {

    std::vector<std::vector<int>> result;
    result.reserve(a.size());

    // Main loop to compute the result
    for (size_t i = 0; i < a.size(); ++i) {
        std::vector<int> subResult;
        subResult.reserve(a[i].size());

        // Inner loop to compute subResult
        for (size_t j = 0; j < a[i].size(); ++j) {
            subResult.push_back(a[i][j] + b[i][j]);
        }

        result.push_back(subResult);
    }

    return result;
}
