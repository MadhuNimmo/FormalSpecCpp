#include <vector>


std::vector<int> BitwiseXOR(const std::vector<int>& a, const std::vector<int>& b) {

    std::vector<int> result;
    result.reserve(a.size()); // Reserve space to avoid reallocations

    size_t i = 0;
    while (i < a.size()) {

        for (size_t k = 0; k < i; ++k) {
        }

        result.push_back(a[i] ^ b[i]);
        i++;
    }

    for (size_t i = 0; i < result.size(); ++i) {
    }

    return result;
}
