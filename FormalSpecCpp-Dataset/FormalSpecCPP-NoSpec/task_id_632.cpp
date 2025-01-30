#include <vector>
#include <algorithm>


void swap(std::vector<int>& arr, size_t i, size_t j) {

    // Perform the swap between elements at indices i and j
    int tmp = arr[i];
    int tmp2 = arr[j];
    arr[i] = arr[j];
    arr[j] = tmp;

}


void MoveZeroesToEnd(std::vector<int>& arr) {
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

    for (size_t idx1 = 0; idx1 < arr.size(); ++idx1) {
        if (arr[idx1] == 0) {
            for (size_t idx2 = idx1 + 1; idx2 < arr.size(); ++idx2) {
            }
        }
    }
}
