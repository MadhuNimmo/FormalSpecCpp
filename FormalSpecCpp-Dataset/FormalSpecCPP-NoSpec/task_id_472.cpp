#include <vector>

bool ContainsConsecutiveNumbers(const std::vector<int>& a) {

    bool result = true;

    // Loop through the array to find consecutive numbers
    for (size_t i = 0; i < a.size() - 2; ++i) {  // Stop at a.size() - 2 to safely check a[i+2]

        // Check if the current element and the next two form a consecutive sequence
        if (a[i] + 1 != a[i + 1]) {
            result = false;
            break;
        }
    }


    return result;
}
