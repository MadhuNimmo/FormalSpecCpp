#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> GetFirstElements(const std::vector<std::vector<int>>& lst) {
    // Precondition: All sub-vectors must have at least one element
    for (size_t i = 0; i < lst.size(); ++i) {
        REQUIRE(lst[i].size() > 0);
    }

    std::vector<int> result;
    result.reserve(lst.size()); // Reserve space to avoid reallocations

    // Loop invariant setup
    for (size_t i = 0; i < lst.size(); ++i) {
        // Loop invariant: result.size() == i
        assert(result.size() == i);
        // Loop invariant: All previous elements are the first elements of their respective sub-vectors
        for (size_t j = 0; j < i; ++j) {
            assert(result[j] == lst[j][0]);
        }

        result.push_back(lst[i][0]);
    }

    // Postcondition: result size must be equal to lst size
    ENSURE(result.size() == lst.size());
    // Postcondition: Each element in result is the first element of the corresponding sub-vector in lst
    for (size_t i = 0; i < result.size(); ++i) {
        ENSURE(result[i] == lst[i][0]);
    }

    return result;
}