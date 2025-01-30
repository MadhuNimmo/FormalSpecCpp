#include "../FormalSpecCPP-NoSpec/task_id_760.cpp"

#include <cassert>
#include <vector>

void testHasOnlyOneDistinctElement() {
    // Test case 1
    std::vector<int> a1 = {1, 1, 1};
    bool res1 = HasOnlyOneDistinctElement(a1);
    assert(res1 == true);

    // Test case 2
    std::vector<int> a2 = {1, 2, 1, 2};
    bool res2 = HasOnlyOneDistinctElement(a2);
    assert(res2 == false);

    // Test case 3
    std::vector<int> a3 = {1, 2, 3, 4, 5};
    bool res3 = HasOnlyOneDistinctElement(a3);
    assert(res3 == false);
}

int main() {
    testHasOnlyOneDistinctElement();
    return 0;
}