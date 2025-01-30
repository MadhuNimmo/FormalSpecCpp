#include <vector>


void SwapFirstAndLast(std::vector<int>& a) {

    int old_first = a[0];
    int old_last = a[a.size() - 1];

    // Swapping the first and last elements
    int tmp = a[0];
    a[0] = a[a.size() - 1];
    a[a.size() - 1] = tmp;

    for (size_t k = 1; k < a.size() - 1; ++k) {
    }
}
