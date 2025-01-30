#include <vector>


int MaxDifference(const std::vector<int>& a) {

    int minVal = a[0];
    int maxVal = a[0];

    // Loop through the array starting from the second element
    for (size_t i = 1; i < a.size(); ++i) {

        if (a[i] < minVal) {
            minVal = a[i];
        } else if (a[i] > maxVal) {
            maxVal = a[i];
        }
    }

    int diff = maxVal - minVal;

    return diff;
}
