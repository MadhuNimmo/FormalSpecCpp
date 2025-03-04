#include <vector>

// Function to recursively sum elements from 'start' to 'end' in an array
int sumTo(const std::vector<int>& a, int start, int end) {

    if (start == end) {
        return 0;
    } else {
        return sumTo(a, start, end - 1) + a[end - 1];
    }
}

// Method to compute the sum of elements in the range [start, end) in an array
int SumInRange(const std::vector<int>& a, int start, int end) {

    int sum = 0;
    for (int i = start; i < end; ++i) {

        sum += a[i];
    }

    return sum;
}
