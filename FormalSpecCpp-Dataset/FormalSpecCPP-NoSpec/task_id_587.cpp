#include <vector>


std::vector<int> ArrayToSeq(const std::vector<int>& a) {

    std::vector<int> s;
    size_t length = a.size();

    // Loop to convert array to sequence
    for (size_t i = 0; i < length; ++i) {
        s.push_back(a[i]);
    }

    return s;
}
