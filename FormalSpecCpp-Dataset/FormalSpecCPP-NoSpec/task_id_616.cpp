#include <vector>


std::vector<int> ElementWiseModulo(const std::vector<int>& a, const std::vector<int>& b) {

    std::vector<int> result(a.size());

    // Loop to calculate element-wise modulo
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] % b[i];
    }

    return result;
}
