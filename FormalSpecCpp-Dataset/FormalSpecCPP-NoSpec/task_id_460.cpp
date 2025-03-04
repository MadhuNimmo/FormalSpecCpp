#include <vector>


std::vector<int> GetFirstElements(const std::vector<std::vector<int>>& lst) {

    std::vector<int> result;
    result.reserve(lst.size()); // Reserve space to avoid reallocations

    for (size_t i = 0; i < lst.size(); ++i) {
        result.push_back(lst[i][0]);
    }

    return result;
}
