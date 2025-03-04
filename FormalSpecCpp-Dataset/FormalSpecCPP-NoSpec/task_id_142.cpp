#include <vector>

int CountIdenticalPositions(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c) {

    size_t count = 0; // Using size_t as count will always be non-negative

    // Loop through the sequences and count identical positions
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == b[i] && b[i] == c[i]) {
            count++;
        }
    }


    return static_cast<int>(count); // Cast to int to match the function signature
}
