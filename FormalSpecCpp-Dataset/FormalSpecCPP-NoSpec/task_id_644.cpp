#include <vector>
#include <algorithm> // For std::swap

// Function to reverse the first k elements of a vector
std::vector<int> ReverseUptoK(std::vector<int>& s, unsigned int k) {

    unsigned int l = k - 1;  // The last index of the first k elements
    unsigned int i = 0;
    std::vector<int> original = s;

    while (i < (l + 1) / 2) {  // We want to swap until the midpoint of the first k elements
        std::swap(s[i], s[l - i]); // Swap the elements within the first k elements
        ++i;
    }
    return s;
}
