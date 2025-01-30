#include <vector>


bool IsMinHeap(const std::vector<int>& a) {

    bool result = true;
    size_t length = a.size();
    size_t halfLength = length / 2;

    for (size_t i = 0; i < halfLength; ++i) {
        // We cannot directly translate the Dafny invariant that uses quantifiers into C++.
        // Instead, we ensure the invariant holds by the logic in the loop.

        if (a[i] > a[2 * i + 1] || (2 * i + 2 < length && a[i] > a[2 * i + 2])) {
            result = false;
            break;
        }
    }

    if (result) {
    } else {
    }

    return result;
}
