#include <string>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool StartAndEndWithSameChar(const std::string& s) {
    // Precondition: The string must not be empty.
    REQUIRE(!s.empty());

    // Calculate the length of the string using size_t since it is non-negative.
    size_t length = s.length();

    // Check if the first and last character are the same.
    bool result = s[0] == s[length - 1];

    // Postcondition: Ensure that the result is true if and only if the first and last characters are the same.
    ENSURE(result == (s[0] == s[length - 1]));

    return result;
}