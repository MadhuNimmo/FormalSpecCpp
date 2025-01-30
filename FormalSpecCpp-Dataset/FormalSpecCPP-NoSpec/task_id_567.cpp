#include <vector>


bool IsSorted(const std::vector<int>& a) {

    bool sorted = true;

    // Loop through the array to check if it is sorted
    for (size_t i = 0; i < a.size() - 1; ++i) {


        // Check if the current element is greater than the next element
        if (a[i] > a[i + 1]) {
            sorted = false;
            break;
        }
    }

    return sorted;
}
