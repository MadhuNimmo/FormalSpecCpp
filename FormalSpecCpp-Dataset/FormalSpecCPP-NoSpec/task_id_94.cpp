#include <vector>


int MinSecondValueFirst(const std::vector<std::vector<int>>& s) {
    for (const auto& seq : s) {
    }

    size_t minSecondIndex = 0;

    // Loop through the array of sequences
    for (size_t i = 1; i < s.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
        }

        // Update minSecondIndex if a new smaller second element is found
        if (s[i][1] < s[minSecondIndex][1]) {
            minSecondIndex = i;
        }
    }

    int firstOfMinSecond = s[minSecondIndex][0];

    return firstOfMinSecond;
}
