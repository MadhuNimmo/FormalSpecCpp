#include "../FormalSpecCPP/task_id_433.cpp"

#include <cassert>
#include <vector>

void testIsGreater() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3, 4, 5};
    bool out1 = IsGreater(a1, 4);
    assert(out1 == false);

    // Test case 2
    std::vector<int> a2 = {2, 3, 4, 5, 6};
    bool out2 = IsGreater(a2, 8);
    assert(out2 == true);

    // Test case 3
    std::vector<int> a3 = {9, 7, 4, 8, 6, 1};
    bool out3 = IsGreater(a3, 11);
    assert(out3 == true);
}

int main() {
    testIsGreater();
    return 0;
}