#include <vector>


bool IsSmaller(const std::vector<int>& a, const std::vector<int>& b) {

    bool result = true;
    size_t n = a.size(); // Using size_t for non-negative values, as sizes cannot be negative

    for (size_t i = 0; i < n; ++i) {
        // Ensures result is true if and only if all previous elements of a are greater than b
        // Ensures result is false if there exists any previous element of a that is not greater than b

        if (a[i] <= b[i]) {
            result = false;
            break;
        }
    }


    return result;
}
