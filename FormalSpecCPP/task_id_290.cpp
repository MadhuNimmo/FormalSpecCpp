#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

std::vector<int> MaxLengthList(const std::vector<std::vector<int>>& lists) {
    // Precondition: lists must not be empty
    REQUIRE(lists.size() > 0);

    std::vector<int> maxList = lists[0];

    // Loop through each list starting from the second element
    for (size_t i = 1; i < lists.size(); ++i) {
        // Update maxList if the current list is longer
        if (lists[i].size() > maxList.size()) {
            maxList = lists[i];
        }

        // Loop invariants
        assert(i >= 1 && i <= lists.size()); // Ensures i is within the valid range
        for (size_t j = 0; j <= i; ++j) {
            assert(lists[j].size() <= maxList.size()); // All lists up to i have length <= maxList
        }
        assert(std::find(lists.begin(), lists.begin() + i + 1, maxList) != lists.begin() + i + 1); // maxList is in lists[..i]
    }

    // Postconditions
    for (const auto& l : lists) {
        ENSURE(l.size() <= maxList.size()); // All lists have length <= maxList
    }
    ENSURE(std::find(lists.begin(), lists.end(), maxList) != lists.end()); // maxList is in lists

    return maxList;
}