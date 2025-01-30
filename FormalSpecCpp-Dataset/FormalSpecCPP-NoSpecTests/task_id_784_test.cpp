#include "../FormalSpecCPP-NoSpec/task_id_784.cpp"

#include <cassert>  // Required header for assertions
#include <vector>   // Required header for using std::vector

void testProductEvenOdd() {
    // Test case 1
    std::vector<int> a1 = {1, 3, 5, 7, 4, 1, 6, 8};
    int out1 = ProductEvenOdd(a1);
    assert(out1 == 4);

    // Test case 2
    std::vector<int> a2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int out2 = ProductEvenOdd(a2);
    assert(out2 == 2);

    // Test case 3
    std::vector<int> a3 = {1, 5, 7, 9, 10};
    int out3 = ProductEvenOdd(a3);
    assert(out3 == 10);
}

int main() {
    testProductEvenOdd();
    return 0;
}