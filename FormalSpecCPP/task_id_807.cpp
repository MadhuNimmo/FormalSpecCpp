#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Helper function to check if a number is odd
bool IsOdd(int x) {
    return x % 2 != 0;
}

// Function to find the first odd number in an array
int FindFirstOdd(const std::vector<int>& a) {
    REQUIRE(!a.empty()); // Precondition: the array should not be empty

    bool found = false;
    size_t index = 0;

    while (index < a.size()) {
        // Loop invariants
        assert(index <= a.size()); // invariant: index is within the bounds of the array
        if (!found) {
            for (size_t i = 0; i < index; ++i) {
                assert(!IsOdd(a[i])); // invariant: no odd number found before the current index
            }
        }
        if (found) {
            assert(IsOdd(a[index - 1])); // invariant: the found element is odd
            for (size_t i = 0; i < index - 1; ++i) {
                assert(!IsOdd(a[i])); // invariant: no odd number before the found index
            }
        }

        if (IsOdd(a[index])) {
            found = true;
            break; // Exit the loop as we found the odd number
        }
        index++;
    }

    // Postconditions
    if (!found) {
        for (size_t i = 0; i < a.size(); ++i) {
            ENSURE(!IsOdd(a[i])); // Ensure no odd number in the entire array if none found
        }
    }
    if (found) {
        ENSURE(index < a.size() && IsOdd(a[index])); // Ensure the found index is valid and the number is odd
        for (size_t i = 0; i < index; ++i) {
            ENSURE(!IsOdd(a[i])); // Ensure no odd number before the found index
        }
    }
    if (found) {
        return a[index];
    }else{
        return -1;
    }
}