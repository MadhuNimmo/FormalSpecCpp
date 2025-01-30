#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Function to recursively sum elements from 'start' to 'end' in an array
int sumTo(const std::vector<int>& a, int start, int end) {
    REQUIRE(a.size() > 0); // Ensures the array is not null
    REQUIRE(0 <= start && start <= end && static_cast<size_t>(end) <= a.size()); // Preconditions

    if (start == end) {
        return 0;
    } else {
        return sumTo(a, start, end - 1) + a[end - 1];
    }
}

// Method to compute the sum of elements in the range [start, end) in an array
int SumInRange(const std::vector<int>& a, int start, int end) {
    REQUIRE(a.size() > 0); // Ensures the array is not null
    REQUIRE(0 <= start && start <= end && static_cast<size_t>(end) <= a.size()); // Preconditions

    int sum = 0;
    for (int i = start; i < end; ++i) {
        assert(start <= i && i <= end); // Loop invariant: i is within the bounds
        assert(sum == sumTo(a, start, i)); // Loop invariant: sum is correct up to i

        sum += a[i];
    }

    ENSURE(sum == sumTo(a, start, end)); // Postcondition: sum must be equal to sumTo result
    return sum;
}