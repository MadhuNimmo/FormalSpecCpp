#include <string>


bool StartAndEndWithSameChar(const std::string& s) {

    // Calculate the length of the string using size_t since it is non-negative.
    size_t length = s.length();

    // Check if the first and last character are the same.
    bool result = s[0] == s[length - 1];


    return result;
}
