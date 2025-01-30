#include <vector>
#include <algorithm>


std::vector<int> RemoveDuplicates(const std::vector<int>& a) {

    std::vector<int> result;
    size_t length = a.size();

    // Processing each element in the array
    for (size_t i = 0; i < length; ++i) {
        // Check if current element is not in result
        if (std::find(result.begin(), result.end(), a[i]) == result.end()) {
            result.push_back(a[i]);
        }
    }

    return result;
}
