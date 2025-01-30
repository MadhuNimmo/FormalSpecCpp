#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

// Function to calculate loss based on cost price and selling price
unsigned int CalculateLoss(unsigned int sellingPrice, unsigned int costPrice) {
    // Preconditions
    REQUIRE(costPrice >= 0 && sellingPrice >= 0);

    unsigned int loss;
    if (costPrice > sellingPrice) {
        loss = costPrice - sellingPrice;
    } else {
        loss = 0;
    }

    // Postconditions
    ENSURE((costPrice > sellingPrice && loss == costPrice - sellingPrice) || (costPrice <= sellingPrice && loss == 0));

    return loss;
}