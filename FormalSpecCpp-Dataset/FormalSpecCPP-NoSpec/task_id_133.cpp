#include <vector>

// Function to sum negative numbers up to index n in the array
int sumNegativesTo(const std::vector<int>& a, size_t n) {

    if (n == 0) {
        return 0;
    } else {
        int lastElement = a[n - 1];
        int sum = sumNegativesTo(a, n - 1);
        if (lastElement < 0) {
            return sum + lastElement;
        } else {
            return sum;
        }
    }
}

// Method to compute the sum of all negative numbers in the array
int SumOfNegatives(const std::vector<int>& a) {
    int result = 0;
    size_t length = a.size();

    for (size_t i = 0; i < length; ++i) {
        if (a[i] < 0) {
            result += a[i];
        }
    }

    return result;
}
