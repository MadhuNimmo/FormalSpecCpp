#include <vector>

int FindFirstOccurrence(const std::vector<int>& arr, int target) {

    int index = -1;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            index = static_cast<int>(i);
            break;
        }
        if (arr[i] > target) {
            break;
        }
    }

    return index;
}
