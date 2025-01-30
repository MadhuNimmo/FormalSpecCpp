#include <vector>


// Function to count the number of true values in a subarray
int countTo(const std::vector<bool>& a, size_t n) {

    if (n == 0) {
        return 0;
    } else {
        return countTo(a, n - 1) + (a[n - 1] ? 1 : 0);
    }
}

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
