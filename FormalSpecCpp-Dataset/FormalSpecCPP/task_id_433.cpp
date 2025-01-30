#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool IsGreater(const std::vector<int>& a, int n) {
    // Precondition
    REQUIRE(!a.empty());

    bool result = true;
    size_t i = 0;

    while (i < a.size()) {
        // Loop invariants
        assert(i <= a.size());
        if (result) {
            for (size_t k = 0; k < i; ++k) {
                assert(n > a[k]);
            }
        } else {
            bool exists = false;
            for (size_t k = 0; k < i; ++k) {
                if (n <= a[k]) {
                    exists = true;
                    break;
                }
            }
            assert(exists);
        }

        if (n <= a[i]) {
            result = false;
            break;
        }
        i++;
    }

    // Postconditions
    if (result) {
        for (size_t j = 0; j < a.size(); ++j) {
            ENSURE(n > a[j]);
        }
    } else {
        bool exists = false;
        for (size_t j = 0; j < a.size(); ++j) {
            if (n <= a[j]) {
                exists = true;
                break;
            }
        }
        ENSURE(exists);
    }

    return result;
}