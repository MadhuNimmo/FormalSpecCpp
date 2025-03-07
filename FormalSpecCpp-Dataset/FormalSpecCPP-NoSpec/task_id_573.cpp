#include <iostream>
#include <vector>
#include <set>

int UniqueProduct(const std::vector<int>& arr) {
    int p = 1;
    std::set<int> seen;

    for (size_t i = 0; i < arr.size(); ++i) {
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            p *= arr[i];
        }
    }

    return p;
}
