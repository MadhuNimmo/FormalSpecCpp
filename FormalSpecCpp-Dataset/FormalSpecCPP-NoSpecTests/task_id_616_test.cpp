#include "../FormalSpecCPP-NoSpec/task_id_616.cpp"

#include <vector>
#include <cassert>
#include <iostream>

void testElementWiseModulo() {
    // Test case 1
    std::vector<int> a1 = {10, 4, 5, 6};
    std::vector<int> a2 = {5, 6, 7, 5};
    std::vector<int> e1 = {0, 4, 5, 1};
    std::vector<int> res1 = ElementWiseModulo(a1, a2);
    assert(res1==e1);

    // Test case 2
    std::vector<int> a3 = {11, 5, 6, 7};
    std::vector<int> a4 = {6, 7, 8, 6};
    std::vector<int> e2 = {5, 5, 6, 1};
    std::vector<int> res2 = ElementWiseModulo(a3, a4);
    assert(res2==e2);

    // Test case 3
    std::vector<int> a5 = {12, 6, 7, 8};
    std::vector<int> a6 = {7, 8, 9, 7};
    std::vector<int> e3 = {5, 6, 7, 1};
    std::vector<int> res3 = ElementWiseModulo(a5, a6);
    assert(res3==e3);
}

int main() {
    testElementWiseModulo();
    return 0;
}