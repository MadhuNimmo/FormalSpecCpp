#include <vector>


std::vector<int> MaxLengthList(const std::vector<std::vector<int>>& lists) {

    std::vector<int> maxList = lists[0];

    // Loop through each list starting from the second element
    for (size_t i = 1; i < lists.size(); ++i) {
        // Update maxList if the current list is longer
        if (lists[i].size() > maxList.size()) {
            maxList = lists[i];
        }
    }
    
    return maxList;
}
