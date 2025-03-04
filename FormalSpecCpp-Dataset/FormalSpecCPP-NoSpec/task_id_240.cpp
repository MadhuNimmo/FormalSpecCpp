#include <vector>


std::vector<int> ReplaceLastElement(const std::vector<int>& first, const std::vector<int>& second) {

    std::vector<int> result;
    size_t first_size = first.size();
    size_t second_size = second.size();

    // Copy the first part of the 'first' vector except the last element
    result.insert(result.end(), first.begin(), first.end() - 1);

    // Append the entire 'second' vector
    result.insert(result.end(), second.begin(), second.end());

    return result;
}
