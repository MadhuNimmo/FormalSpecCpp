#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> BitwiseXOR(const std::vector<int>& a, const std::vector<int>& b) {
    // Preconditions
    REQUIRE(a.size() == b.size());

    std::vector<int> result;
    result.reserve(a.size()); // Reserve space to avoid reallocations

    size_t i = 0;
    while (i < a.size()) {
        // Loop invariants
        assert(i <= a.size()); // Ensures i does not exceed the size of a
        assert(result.size() == i); // Ensures the size of result is equal to i

        for (size_t k = 0; k < i; ++k) {
            assert(result[k] == (a[k] ^ b[k])); // Ensures each element up to i is correctly XORed
        }

        result.push_back(a[i] ^ b[i]);
        i++;
    }

    // Postconditions
    ENSURE(result.size() == a.size());
    for (size_t i = 0; i < result.size(); ++i) {
        ENSURE(result[i] == (a[i] ^ b[i]));
    }

    return result;
}