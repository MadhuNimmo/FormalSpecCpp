#include <vector>


std::vector<int> BitwiseXOR(const std::vector<int>& a, const std::vector<int>& b) {

    std::vector<int> result;
    result.reserve(a.size()); // Reserve space to avoid reallocations

    size_t i = 0;
    while (i < a.size()) {
        result.push_back(a[i] ^ b[i]);
        i++;
    }

    return result;
}
