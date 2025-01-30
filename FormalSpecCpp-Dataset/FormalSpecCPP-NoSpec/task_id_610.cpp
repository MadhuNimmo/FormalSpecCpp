#include <vector>


std::vector<int> RemoveElement(const std::vector<int>& s, size_t k) {

    std::vector<int> v(s.size() - 1);
    size_t i = 0;

    // First loop: Copy elements from 0 to k-1
    while (i < k) {
        for (size_t j = 0; j < i; ++j) {
        }

        v[i] = s[i];
        i++;
    }

    for (size_t j = 0; j < k; ++j) {
    }

    // Second loop: Copy elements from k+1 to end
    while (i < v.size()) {
        for (size_t j = k; j < i; ++j) {
        }
        for (size_t j = 0; j < k; ++j) {
        }

        v[i] = s[i + 1];
        i++;
    }

    for (size_t i = 0; i < k; ++i) {
    }
    for (size_t i = k; i < v.size(); ++i) {
    }

    return v;
}
