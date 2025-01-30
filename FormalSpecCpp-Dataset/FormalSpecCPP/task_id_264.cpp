#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Function to convert human years to dog years
unsigned int DogYears(unsigned int humanYears) {
    // Precondition: humanYears must be non-negative
    REQUIRE(humanYears >= 0);

    unsigned dogYears;

    // If the dog is 2 years or younger, each year is worth 10.5 dog years
    if (humanYears <= 2) {
        dogYears = humanYears * 10.5;
    } else {
        // First 2 years are 10.5 dog years each
        dogYears = 2 * 10.5;
        // Each additional year after that is worth 4 dog years
        dogYears += (humanYears - 2) * 4;
    }

    // Postcondition: Ensure that the calculation is correct based on the logic
    ENSURE(humanYears <= 2 ? dogYears == humanYears * 10.5 :
            dogYears == (2 * 10.5) + (humanYears - 2) * 4);

    return dogYears;
}