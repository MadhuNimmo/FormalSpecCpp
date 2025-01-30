#include <vector>


std::vector<int> SubtractSequences(const std::vector<int>& a, const std::vector<int>& b) {

    std::vector<int> result;
    result.reserve(a.size()); // Reserve space to avoid reallocations

    // Loop to subtract elements
    for (size_t i = 0; i < a.size(); ++i) {

        // Subtract and add to result
        result.push_back(a[i] - b[i]);
    }

    for (size_t i = 0; i < result.size(); ++i) {
    }

    return result;
}
