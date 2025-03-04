#include <vector>

std::pair<std::vector<int>, std::vector<int>> SplitArray(const std::vector<int>& arr, size_t L) {

    // Splitting the array
    std::vector<int> firstPart(arr.begin(), arr.begin() + L);
    std::vector<int> secondPart(arr.begin() + L, arr.end());


    // Ensuring the concatenation of firstPart and secondPart equals the original array
    std::vector<int> concatenated(firstPart);
    concatenated.insert(concatenated.end(), secondPart.begin(), secondPart.end());

    return {firstPart, secondPart};
}
