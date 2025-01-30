#include <cassert>
#include <vector>
#include <algorithm>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Helper function to find the minimum of two integers
int MinPair(const std::vector<int>& s) {
    REQUIRE(s.size() == 2);
    int result = (s[0] <= s[1]) ? s[0] : s[1];
    ENSURE((s[0] <= s[1] && result == s[0]) || (s[0] > s[1] && result == s[1]));
    return result;
}

// Recursive function to find the minimum element in a sequence
int min(const std::vector<int>& s) {
    REQUIRE(s.size() >= 2);
    if (s.size() == 2) {
        return MinPair(s);
    } else {
        std::vector<int> newVec = {s[0], min(std::vector<int>(s.begin() + 1, s.end()))};
        return MinPair(newVec);
    }
}

// Function to find the second smallest element in an array
int SecondSmallest(const std::vector<int>& s) {
    REQUIRE(s.size() >= 2);
    // Ensure there are at least two distinct values
    int minVal = *std::min_element(s.begin(), s.end());
    REQUIRE(std::count(s.begin(), s.end(), minVal) < s.size());  // Ensure there is a second smallest

    // Find the second smallest element distinct from the minimum
    int secondSmallest = std::numeric_limits<int>::max();
    for (int val : s) {
        if (val != minVal && val < secondSmallest) {
            secondSmallest = val;
        }
    }

    REQUIRE(secondSmallest != std::numeric_limits<int>::max());  // Ensure we found a second smallest value

    ENSURE([&]() {
        return std::count(s.begin(), s.end(), minVal) > 0 &&
               std::count(s.begin(), s.end(), secondSmallest) > 0;
    }());

    return secondSmallest;
}