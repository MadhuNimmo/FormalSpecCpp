#include <vector>


std::vector<int> AppendArrayToSeq(const std::vector<int>& s, const std::vector<int>& a) {

    std::vector<int> r = s; // Start with sequence s

    // Loop to append elements from array a to sequence r
    for (size_t i = 0; i < a.size(); ++i) {
        // Append current element from a to r
        r.push_back(a[i]);
    }

    return r;
}
