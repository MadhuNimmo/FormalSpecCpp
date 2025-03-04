#include <vector>

int MinSecondValueFirst(const std::vector<std::vector<int>>& s) {

    size_t minSecondIndex = 0;

    // Loop through the array of sequences
    for (size_t i = 1; i < s.size(); ++i) {

        // Update minSecondIndex if a new smaller second element is found
        if (s[i][1] < s[minSecondIndex][1]) {
            minSecondIndex = i;
        }
    }

    int firstOfMinSecond = s[minSecondIndex][0];

    return firstOfMinSecond;
}
