#include <vector>


int FindSmallest(const std::vector<int>& s) {

    int min = s[0];

    // Loop through the array starting from the second element
    for (size_t i = 1; i < s.size(); ++i) {
        for (size_t k = 0; k < i; ++k) {
        }
        bool exists = false;
        for (size_t k = 0; k < i; ++k) {
            if (min == s[k]) {
                exists = true;
                break;
            }
        }

        // Update min if a smaller element is found
        if (s[i] < min) {
            min = s[i];
        }
    }

    for (size_t i = 0; i < s.size(); ++i) {
    }
    bool exists = false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (min == s[i]) {
            exists = true;
            break;
        }
    }

    return min;
}
