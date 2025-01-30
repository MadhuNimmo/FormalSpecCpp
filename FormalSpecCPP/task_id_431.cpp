#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool HasCommonElement(const std::vector<int>& a, const std::vector<int>& b) {
    // Preconditions
    REQUIRE(!a.empty() && !b.empty());

    bool result = false;
    size_t a_length = a.size();
    size_t b_length = b.size();

    for (size_t i = 0; i < a_length; ++i) {
        // Loop invariant: 0 <= i <= a_length
        // Loop invariant: !result implies all elements in a[0..i) are not in b[0..b_length)
        assert(i <= a_length);
        if (!result) {
            for (size_t k = 0; k < i; ++k) {
                for (size_t j = 0; j < b_length; ++j) {
                    assert(a[k] != b[j]);
                }
            }
        }

        for (size_t j = 0; j < b_length; ++j) {
            // Loop invariant: 0 <= j <= b_length
            // Loop invariant: !result implies a[i] is not in b[0..j)
            assert(j <= b_length);
            if (!result) {
                for (size_t k = 0; k < j; ++k) {
                    assert(a[i] != b[k]);
                }
            }

            if (a[i] == b[j]) {
                result = true;
                // Postcondition: result implies there exists some i, j such that a[i] == b[j]
                ENSURE(result && a[i] == b[j]);
                return result;
            }
        }
    }

    // Postcondition: !result implies all elements in a are not in b
    if (!result) {
        for (size_t i = 0; i < a_length; ++i) {
            for (size_t j = 0; j < b_length; ++j) {
                assert(a[i] != b[j]);
            }
        }
    }

    ENSURE(!result || [&]() {
        for (size_t i = 0; i < a_length; ++i) {
            for (size_t j = 0; j < b_length; ++j) {
                if (a[i] == b[j]) return true;
            }
        }
        return false;
    }());

    return result;
}