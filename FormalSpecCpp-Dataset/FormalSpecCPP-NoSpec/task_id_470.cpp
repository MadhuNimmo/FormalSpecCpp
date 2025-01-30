#include <vector>


std::vector<int> PairwiseAddition(const std::vector<int>& a) {

    std::vector<int> result;

    // Loop through the array to calculate pairwise sums of consecutive elements
    for (size_t i = 0; i < a.size() - 1; ++i) {
        result.push_back(a[i] + a[i + 1]);
    }

    for (size_t i = 0; i < result.size(); ++i) {
    }

    return result;
}
