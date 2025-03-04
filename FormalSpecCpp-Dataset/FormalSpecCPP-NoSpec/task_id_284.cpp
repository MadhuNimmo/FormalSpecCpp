#include <vector>

bool AllElementsEqual(const std::vector<int>& a, int n) {

    bool result = true;
    size_t length = a.size(); // Using size_t for non-negative array size.

    for (size_t i = 0; i < length; ++i) {
        // The second invariant is implicitly maintained by the logic of the loop and break condition.

        if (a[i] != n) {
            result = false;
            break;
        }
    }

    if (result) {
        for (size_t i = 0; i < length; ++i) {
        }
    } else {
        bool exists_not_equal = false;
        for (size_t i = 0; i < length; ++i) {
            if (a[i] != n) {
                exists_not_equal = true;
                break;
            }
        }
    }

    return result;
}
