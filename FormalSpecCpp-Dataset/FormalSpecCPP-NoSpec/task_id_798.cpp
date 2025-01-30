#include <vector>


// Function to compute the sum of elements up to the nth index
int sumTo(const std::vector<int>& a, size_t n) {

    if (n == 0) {
        return 0;
    } else {
        return sumTo(a, n - 1) + a[n - 1];
    }
}

// Method to compute the sum of all elements in the array
int ArraySum(const std::vector<int>& a) {
    int result = 0;
    size_t length = a.size();

    for (size_t i = 0; i < length; ++i) {

        result += a[i];
    }

    return result;
}
