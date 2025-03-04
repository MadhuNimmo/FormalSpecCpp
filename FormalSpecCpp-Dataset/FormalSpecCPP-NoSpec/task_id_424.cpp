#include <vector>
#include <string>


std::vector<char> ExtractRearChars(const std::vector<std::string>& l) {

    std::vector<char> rearChars;
    rearChars.reserve(l.size()); // Reserve space to avoid reallocations

    size_t i = 0;
    while (i < l.size()) {
        // Main operation: Append the last character of the current string in l to rearChars
        rearChars.push_back(l[i][l[i].size() - 1]);
        ++i;
    }

    return rearChars;
}
