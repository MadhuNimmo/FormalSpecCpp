#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool MonthHas31Days(unsigned int month) {
    // Precondition: month should be between 1 and 12
    REQUIRE(month >= 1 && month <= 12);

    // Check if the month has 31 days
    bool result = (month == 1 || month == 3 || month == 5 || month == 7 ||
                   month == 8 || month == 10 || month == 12);

    // Postcondition: result should be true if and only if month is one of {1, 3, 5, 7, 8, 10, 12}
    ENSURE(result == (month == 1 || month == 3 || month == 5 || month == 7 ||
                      month == 8 || month == 10 || month == 12));

    return result;
}