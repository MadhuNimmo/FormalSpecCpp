#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::pair<std::vector<int>, std::vector<int>> SplitArray(const std::vector<int>& arr, size_t L) {
    // Preconditions
    REQUIRE(L <= arr.size());

    // Splitting the array
    std::vector<int> firstPart(arr.begin(), arr.begin() + L);
    std::vector<int> secondPart(arr.begin() + L, arr.end());

    // Postconditions
    ENSURE(firstPart.size() == L);
    ENSURE(secondPart.size() == arr.size() - L);

    // Ensuring the concatenation of firstPart and secondPart equals the original array
    std::vector<int> concatenated(firstPart);
    concatenated.insert(concatenated.end(), secondPart.begin(), secondPart.end());
    ENSURE(concatenated == arr);

    return {firstPart, secondPart};
}