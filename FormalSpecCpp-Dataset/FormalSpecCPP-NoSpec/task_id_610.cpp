#include <vector>

std::vector<int> RemoveElement(const std::vector<int>& s, size_t k) {

    std::vector<int> v(s.size() - 1);
    size_t i = 0;

    // First loop: Copy elements from 0 to k-1
    while (i < k) {
        v[i] = s[i];
        i++;
    }

    // Second loop: Copy elements from k+1 to end
    while (i < v.size()) {
        v[i] = s[i + 1];
        i++;
    }
    return v;
}
