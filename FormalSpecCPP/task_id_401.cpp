#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<std::vector<int>> IndexWiseAddition(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
    // Preconditions
    REQUIRE(a.size() > 0 && b.size() > 0);
    REQUIRE(a.size() == b.size());
    for (size_t i = 0; i < a.size(); ++i) {
        REQUIRE(a[i].size() == b[i].size());
    }

    std::vector<std::vector<int>> result;
    result.reserve(a.size());

    // Main loop to compute the result
    for (size_t i = 0; i < a.size(); ++i) {
        // Loop invariants
        assert(result.size() == i);
        for (size_t k = 0; k < i; ++k) {
            assert(result[k].size() == a[k].size());
            for (size_t j = 0; j < result[k].size(); ++j) {
                assert(result[k][j] == a[k][j] + b[k][j]);
            }
        }

        std::vector<int> subResult;
        subResult.reserve(a[i].size());

        // Inner loop to compute subResult
        for (size_t j = 0; j < a[i].size(); ++j) {
            // Inner loop invariants
            assert(subResult.size() == j);
            for (size_t k = 0; k < j; ++k) {
                assert(subResult[k] == a[i][k] + b[i][k]);
            }

            subResult.push_back(a[i][j] + b[i][j]);
        }

        result.push_back(subResult);
    }

    // Postconditions
    ENSURE(result.size() == a.size());
    for (size_t i = 0; i < result.size(); ++i) {
        ENSURE(result[i].size() == a[i].size());
        for (size_t j = 0; j < result[i].size(); ++j) {
            ENSURE(result[i][j] == a[i][j] + b[i][j]);
        }
    }

    return result;
}