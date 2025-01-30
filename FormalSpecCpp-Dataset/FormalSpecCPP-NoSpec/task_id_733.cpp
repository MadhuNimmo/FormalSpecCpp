#include <vector>


int FindFirstOccurrence(const std::vector<int>& arr, int target) {

    int index = -1;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (index == -1) {
            for (size_t k = 0; k < i; ++k) {
            }
        }
        if (0 <= index && index < static_cast<int>(i)) {
        }

        if (arr[i] == target) {
            index = static_cast<int>(i);
            break;
        }
        if (arr[i] > target) {
            break;
        }
    }

    if (0 <= index && index < static_cast<int>(arr.size())) {
    }
    if (index == -1) {
        for (size_t i = 0; i < arr.size(); ++i) {
        }
    }

    return index;
}
