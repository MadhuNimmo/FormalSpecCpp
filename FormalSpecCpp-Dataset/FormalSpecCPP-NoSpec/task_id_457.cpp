#include <vector>
#include <algorithm>


std::vector<int> MinLengthSublist(const std::vector<std::vector<int>>& s) {

    std::vector<int> minSublist = s[0];
    size_t i;

    for (i = 1; i < s.size(); ++i) {
        if (s[i].size() < minSublist.size()) {
            minSublist = s[i];
        }
    }
    
    return minSublist;
}
