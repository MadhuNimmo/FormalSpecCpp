#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool IsBreakEven(unsigned int costPrice, unsigned int sellingPrice) {
    // Preconditions
    REQUIRE(costPrice >= 0);
    REQUIRE(sellingPrice >= 0);

    // Method body
    bool result = (costPrice == sellingPrice);

    // Postconditions
    ENSURE(result == (costPrice == sellingPrice));

    return result;
}