#include <vector>
#include <cmath>


// Function to calculate power of a base to an exponent
int Power(int base, unsigned int exponent) {

    if (exponent == 0) {
        return 1;
    } else {
        return base * Power(base, exponent - 1);
    }
}

// Method to apply the Power function to each element of a list
std::vector<int> PowerOfListElements(const std::vector<int>& l, unsigned int n) {

    std::vector<int> result;
    result.reserve(l.size()); // Reserve space to avoid reallocations

    for (size_t i = 0; i < l.size(); ++i) {

        // Check the power calculation for each element added so far
        for (size_t k = 0; k < i; ++k) {
        }

        result.push_back(Power(l[i], n));
    }

    for (size_t i = 0; i < l.size(); ++i) {
    }

    return result;
}
