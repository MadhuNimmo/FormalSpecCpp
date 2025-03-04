#include <vector>

// Method to count the number of true values in the entire array
int CountTrue(const std::vector<bool>& a) {

    int result = 0;
    for (size_t i = 0; i < a.size(); ++i) {

        if (a[i]) {
            result += 1;
        }
    }

    return result;
}
