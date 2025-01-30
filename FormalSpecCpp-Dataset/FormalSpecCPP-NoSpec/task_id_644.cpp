#include <vector>
#include <algorithm> // For std::swap


// Function to reverse the entire vector
void Reverse(std::vector<int>& a) {

    size_t l = a.size();
    size_t i = 0;

    while (i < l / 2) {  // We want to swap until the midpoint
        std::swap(a[i], a[l - 1 - i]); // Swap the elements
        ++i;
    }

    for (size_t k = 0; k < a.size(); ++k) {
    }
}

// Function to reverse the first k elements of a vector
std::vector<int> ReverseUptoK(std::vector<int>& s, unsigned int k) {

    unsigned int l = k - 1;  // The last index of the first k elements
    unsigned int i = 0;
    std::vector<int> original = s;

    while (i < (l + 1) / 2) {  // We want to swap until the midpoint of the first k elements
        std::swap(s[i], s[l - i]); // Swap the elements within the first k elements
        ++i;
    }

    for (unsigned int i = 0; i < k; ++i) {
    }

    // Ensure that elements beyond k are unchanged
    for (unsigned int i = k; i < s.size(); ++i) {
    }

    return s;
}
