#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> ReplaceLastElement(const std::vector<int>& first, const std::vector<int>& second) {
    // Preconditions
    REQUIRE(first.size() > 0);

    std::vector<int> result;
    size_t first_size = first.size();
    size_t second_size = second.size();

    // Copy the first part of the 'first' vector except the last element
    result.insert(result.end(), first.begin(), first.end() - 1);

    // Append the entire 'second' vector
    result.insert(result.end(), second.begin(), second.end());

    // Postconditions
    ENSURE(result.size() == first_size - 1 + second_size);
    for (size_t i = 0; i < first_size - 1; ++i) {
        ENSURE(result[i] == first[i]);
    }
    for (size_t i = first_size - 1; i < result.size(); ++i) {
        ENSURE(result[i] == second[i - first_size + 1]);
    }

    return result;
}