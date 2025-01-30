#include <iostream>
#include <vector>
#include <set>


int SetProduct(const std::set<int>& s) {
    if (s.empty()) {
        return 1;
    } else {
        int product = 1;
        for (int x : s) {
            product *= x;
        }
        return product;
    }
}

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
