#include <cassert>
#include <vector>
#include <algorithm> // For std::swap

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Function to reverse the entire vector
void Reverse(std::vector<int>& a) {
    // Preconditions
    REQUIRE(!a.empty()); // Ensure the vector is not empty

    size_t l = a.size();
    size_t i = 0;

    while (i < l / 2) {  // We want to swap until the midpoint
        std::swap(a[i], a[l - 1 - i]); // Swap the elements
        ++i;
    }

    // Postcondition: Verify the vector is reversed
    for (size_t k = 0; k < a.size(); ++k) {
        ENSURE(a[k] == a[a.size() - 1 - k]); // Check if the vector is reversed
    }
}

// Function to reverse the first k elements of a vector
std::vector<int> ReverseUptoK(std::vector<int>& s, unsigned int k) {
    // Preconditions
    REQUIRE(2 <= k && k <= s.size()); // Ensure k is within valid range

    unsigned int l = k - 1;  // The last index of the first k elements
    unsigned int i = 0;
    std::vector<int> original = s;

    while (i < (l + 1) / 2) {  // We want to swap until the midpoint of the first k elements
        std::swap(s[i], s[l - i]); // Swap the elements within the first k elements
        ++i;
    }

    // Postconditions: Verify the first k elements are reversed
    for (unsigned int i = 0; i < k; ++i) {
        ENSURE(s[i] == original[k - 1 - i]);
    }
    
    // Ensure that elements beyond k are unchanged
    for (unsigned int i = k; i < s.size(); ++i) {
        ENSURE(s[i] == original[i]);
    }

    return s;
}
