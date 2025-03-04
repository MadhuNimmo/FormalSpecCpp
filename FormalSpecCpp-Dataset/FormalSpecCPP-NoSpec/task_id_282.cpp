#include <vector>


std::vector<int> ElementWiseSubtraction(const std::vector<int>& a, const std::vector<int>& b) {

    std::vector<int> result(a.size());

    // Loop to perform element-wise subtraction
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] - b[i];
    }

    return result;
}
