#include "../FormalSpecCPP/task_id_573.cpp"

#include <cassert>
#include <vector>

void testUniqueProduct() {
    // Test case 1
    std::vector<int> a1 = {10, 20, 30, 40, 20, 50, 60, 40};
    int out1 = UniqueProduct(a1);
    assert(out1 == 720000000);

    // Test case 2
    std::vector<int> a2 = {1, 2, 3, 1};
    int out2 = UniqueProduct(a2);
    assert(out2 == 6);

    // Test case 3
    std::vector<int> a3 = {7, 8, 9, 0, 1, 1};
    int out3 = UniqueProduct(a3);
    assert(out3 == 0);
}

int main() {
    testUniqueProduct();
    return 0;
}