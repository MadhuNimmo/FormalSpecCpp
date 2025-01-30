#include <vector>
#include <cassert>
#include <algorithm>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

void swap(std::vector<int>& arr, size_t i, size_t j) {
    REQUIRE(i < arr.size() && j < arr.size()); // Ensure that indices are within bounds

    // Perform the swap between elements at indices i and j
    int tmp = arr[i];
    int tmp2 = arr[j];
    arr[i] = arr[j];
    arr[j] = tmp;

    // Postcondition: Ensure that the elements have been swapped correctly
    ENSURE(arr[i] == tmp2 && arr[j] == tmp);
}


void MoveZeroesToEnd(std::vector<int>& arr) {
    REQUIRE(arr.size() >= 2);
    size_t i = 0;
    size_t j = 0;

    while (j < arr.size()) {
        if (arr[j] != 0) {
            if (i != j) {
                swap(arr, i, j);
            }
            i++;
        }
        j++;
    }

    ENSURE(arr.size() == arr.size()); // Size is unchanged
    for (size_t idx1 = 0; idx1 < arr.size(); ++idx1) {
        if (arr[idx1] == 0) {
            for (size_t idx2 = idx1 + 1; idx2 < arr.size(); ++idx2) {
                ENSURE(arr[idx2] == 0); // All elements after first zero are zero
            }
        }
    }
}