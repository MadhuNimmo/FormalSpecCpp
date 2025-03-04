#include <vector>

int LastPosition(const std::vector<int>& arr, int elem) {

    int pos = -1;
    for (size_t i = 0; i < arr.size(); ++i) {

        // Update pos when the element matches
        if (arr[i] == elem) {
            pos = static_cast<int>(i);
        }
    }

    return pos;
}
