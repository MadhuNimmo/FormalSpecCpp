#include "../FormalSpecCPP-NoSpec/task_id_567.cpp"

#include <cassert>
#include <vector>

void testIsSorted() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 4, 6, 8, 10, 12, 14, 16, 17};
    bool out1 = IsSorted(a1);
    assert(out1 == true);

    // Test case 2
    std::vector<int> a2 = {1, 2, 4, 6, 8, 10, 12, 14, 20, 17};
    bool out2 = IsSorted(a2);
    assert(out2 == false);

    // Test case 3
    std::vector<int> a3 = {1, 2, 4, 6, 8, 10, 15, 14, 20};
    bool out3 = IsSorted(a3);
    assert(out3 == false);
}

int main() {
    testIsSorted();
    return 0;
}