#include <vector>

double FindMedian(const std::vector<int>& a, const std::vector<int>& b) {

    // Merge the two sorted arrays
    std::vector<int> merged;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            merged.push_back(a[i]);
            ++i;
        } else {
            merged.push_back(b[j]);
            ++j;
        }
    }

    // If there are any remaining elements in a
    while (i < a.size()) {
        merged.push_back(a[i]);
        ++i;
    }

    // If there are any remaining elements in b
    while (j < b.size()) {
        merged.push_back(b[j]);
        ++j;
    }

    // Find the median of the merged array
    size_t total_size = merged.size();
    double median;
    if (total_size % 2 == 0) {
        median = (merged[total_size / 2 - 1] + merged[total_size / 2]) / 2.0;
    } else {
        median = merged[total_size / 2];
    }


    return median;
}
