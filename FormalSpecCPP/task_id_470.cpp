#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> PairwiseAddition(const std::vector<int>& a) {
    // Preconditions
    REQUIRE(a.size() > 0); // Ensure the length of the array is at least 2 for pairwise addition

    std::vector<int> result;
    
    // Loop through the array to calculate pairwise sums of consecutive elements
    for (size_t i = 0; i < a.size() - 1; ++i) {
        result.push_back(a[i] + a[i + 1]);
    }

    // Postconditions
    ENSURE(result.size() == a.size() - 1); // Ensure the result array has one less element than the input array
    for (size_t i = 0; i < result.size(); ++i) {
        ENSURE(result[i] == a[i] + a[i + 1]); // Ensure each element of the result is the sum of consecutive elements
    }

    return result;
}
