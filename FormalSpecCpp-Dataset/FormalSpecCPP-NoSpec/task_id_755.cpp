#include <vector>
#include <algorithm>


// Helper function to find the minimum of two integers
int MinPair(const std::vector<int>& s) {
    int result = (s[0] <= s[1]) ? s[0] : s[1];
    return result;
}

// Recursive function to find the minimum element in a sequence
int min(const std::vector<int>& s) {
    if (s.size() == 2) {
        return MinPair(s);
    } else {
        std::vector<int> newVec = {s[0], min(std::vector<int>(s.begin() + 1, s.end()))};
        return MinPair(newVec);
    }
}

// Function to find the second smallest element in an array
int SecondSmallest(const std::vector<int>& s) {
    // Ensure there are at least two distinct values
    int minVal = *std::min_element(s.begin(), s.end());

    // Find the second smallest element distinct from the minimum
    int secondSmallest = std::numeric_limits<int>::max();
    for (int val : s) {
        if (val != minVal && val < secondSmallest) {
            secondSmallest = val;
        }
    }



    return secondSmallest;
}
