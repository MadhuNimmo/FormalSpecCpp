#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool IsMonthWith30Days(unsigned int month) {
    // Precondition: month should be between 1 and 12
    REQUIRE(month >= 1 && month <= 12);

    bool result = (month == 4 || month == 6 || month == 9 || month == 11);

    // Postcondition: result is true if and only if month is April, June, September, or November
    ENSURE(result == (month == 4 || month == 6 || month == 9 || month == 11));

    return result;
}