#include <vector>


int ElementAtIndexAfterRotation(const std::vector<int>& l, unsigned int n, size_t index) {

    // Calculation
    n = n % l.size();
    size_t adjusted_index = (index + l.size() - n) % l.size();
    int element = l[adjusted_index];


    return element;
}
