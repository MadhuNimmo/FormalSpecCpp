#include <vector>


std::vector<int> SplitAndAppend(const std::vector<int>& l, size_t n) {

    std::vector<int> firstPart(l.begin(), l.begin() + n);
    std::vector<int> secondPart(l.begin() + n, l.end());
    std::vector<int> r(secondPart.begin(), secondPart.end());
    r.insert(r.end(), firstPart.begin(), firstPart.end());

    for (size_t i = 0; i < l.size(); ++i) {
    }

    return r;
}
