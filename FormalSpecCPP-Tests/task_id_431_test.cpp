#include "../FormalSpecCPP/task_id_431.cpp"

#include <cassert>
#include <vector>

void testHasCommonElement() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3, 4, 5};
    std::vector<int> a2 = {5, 6, 7, 8, 9};
    bool out1 = HasCommonElement(a1, a2);
    assert(out1 == true);

    // Test case 2
    std::vector<int> a3 = {1, 2, 3, 4, 5};
    std::vector<int> a4 = {6, 7, 8, 9};
    bool out2 = HasCommonElement(a3, a4);
    assert(out2 == false);

    // Test case 3
    std::vector<int> a5 = {1, 0, 1, 0};
    std::vector<int> a6 = {2, 0, 1};
    bool out3 = HasCommonElement(a5, a6);
    assert(out3 == true);
}

int main() {
    testHasCommonElement();
    return 0;
}