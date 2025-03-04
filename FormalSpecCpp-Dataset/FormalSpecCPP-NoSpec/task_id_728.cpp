#include <vector>


std::vector<int> AddLists(const std::vector<int>& a, const std::vector<int>& b) {

    std::vector<int> result;
    result.reserve(a.size()); // Reserve space to avoid reallocations

    for (size_t i = 0; i < a.size(); ++i) {
        result.push_back(a[i] + b[i]);
    }
    
    return result;
}
