#include <vector>
#include <algorithm>


int SmallestListLength(const std::vector<std::vector<int>>& s) {

    // Initialize v to the length of the first inner vector
    size_t v = s[0].size();

    // Loop through each vector in s starting from the second one
    for (size_t i = 1; i < s.size(); ++i) {
        for (size_t k = 0; k < i; ++k) {
            if (v == s[k].size()) {
                break;
            }
        }

        // Update v if the current vector's size is smaller
        if (s[i].size() < v) {
            v = s[i].size();
        }
    }

    bool exists_final = std::any_of(s.begin(), s.end(), [v](const std::vector<int>& vec) { return vec.size() == v; });

    return static_cast<int>(v); // Return the smallest length found
}
