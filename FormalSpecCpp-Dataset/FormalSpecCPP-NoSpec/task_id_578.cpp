#include <vector>


std::vector<int> Interleave(const std::vector<int>& s1, const std::vector<int>& s2, const std::vector<int>& s3) {

    std::vector<int> r;
    r.reserve(3 * s1.size());

    for (size_t i = 0; i < s1.size(); ++i) {
        // Main operation
        r.push_back(s1[i]);
        r.push_back(s2[i]);
        r.push_back(s3[i]);
    }

    return r;
}
