#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool HasOnlyOneDistinctElement(const std::vector<int>& a) {
    // Precondition: the array must not be null (handled by reference in C++)
    REQUIRE(!a.empty()); // Adjusted to ensure the vector is not empty

    if (a.size() == 0) {
        return true;
    }

    int firstElement = a[0];
    bool result = true;

    for (size_t i = 1; i < a.size(); ++i) {
        // Loop invariant: all elements up to the current index i are equal to the first element
        assert(result ? std::all_of(a.begin(), a.begin() + i, [firstElement](int elem) { return elem == firstElement; }) : true);

        if (a[i] != firstElement) {
            result = false;
            break;
        }
    }

    // Postconditions
    if (result) {
        ENSURE(std::all_of(a.begin(), a.end(), [firstElement](int elem) { return elem == firstElement; }));
    } else {
        ENSURE(std::any_of(a.begin(), a.end(), [firstElement](int elem) { return elem != firstElement; }));
    }

    return result;
}