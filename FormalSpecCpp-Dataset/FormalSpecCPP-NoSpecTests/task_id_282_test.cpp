#include "../FormalSpecCPP-NoSpec/task_id_282.cpp"

#include <cassert>
#include <vector>

void testElementWiseSubtraction() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3};
    std::vector<int> a2 = {4, 5, 6};
    std::vector<int> e1 = {-3, -3, -3};
    std::vector<int> res1 = ElementWiseSubtraction(a1, a2);
    assert(res1 == e1);

    // Test case 2
    std::vector<int> a3 = {1, 2};
    std::vector<int> a4 = {3, 4};
    std::vector<int> e2 = {-2, -2};
    std::vector<int> res2 = ElementWiseSubtraction(a3, a4);
    assert(res2 == e2);

    // Test case 3
    std::vector<int> a5 = {90, 120};
    std::vector<int> a6 = {50, 70};
    std::vector<int> e3 = {40, 50};
    std::vector<int> res3 = ElementWiseSubtraction(a5, a6);
    assert(res3 == e3);
}

int main() {
    testElementWiseSubtraction();
    return 0;
}