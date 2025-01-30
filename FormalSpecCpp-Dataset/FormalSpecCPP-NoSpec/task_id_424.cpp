#include <vector>
#include <string>


std::vector<char> ExtractRearChars(const std::vector<std::string>& l) {
    for (const auto& s : l) {
    }

    std::vector<char> rearChars;
    rearChars.reserve(l.size()); // Reserve space to avoid reallocations

    size_t i = 0;
    while (i < l.size()) {
        for (size_t k = 0; k < i; ++k) {
        }

        // Main operation: Append the last character of the current string in l to rearChars
        rearChars.push_back(l[i][l[i].size() - 1]);
        ++i;
    }

    for (size_t j = 0; j < l.size(); ++j) {
    }

    return rearChars;
}
