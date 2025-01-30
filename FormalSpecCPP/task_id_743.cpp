#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> RotateRight(const std::vector<int>& l, unsigned int n) {
    // Preconditions
    REQUIRE(n >= 0);

    size_t length = l.size();
    std::vector<int> rotated(length);

    // Loop to fill the rotated vector
    for (size_t i = 0; i < length; ++i) {
        // Loop invariants
        assert(i <= length); // Ensures loop does not exceed bounds
        assert(rotated.size() == length); // Ensures the size of rotated remains correct

        int index = (i - n + length) % length; // Calculate the new index considering rotation
        if (index < 0) {
            index += length; // Correct negative index
        }
        rotated[i] = l[index];

        // Loop invariant: Check rotated elements are correctly assigned
        for (size_t k = 0; k <= i; ++k) {
            int check_index = (k - n + length) % length;
            if (check_index < 0) {
                check_index += length;
            }
            assert(rotated[k] == l[check_index]);
        }
    }

    // Postconditions
    ENSURE(rotated.size() == l.size()); // Ensure the rotated vector has the same size as input
    for (size_t i = 0; i < length; ++i) {
        ENSURE(rotated[i] == l[(i - n + length) % length]); // Ensure each element is correctly rotated
    }

    return rotated;
}