#include "task_id_793.cpp"

#include <cassert>  // Required header for assertions
#include <vector>   // Required header for using std::vector

void testLastPosition() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3};
    int out1 = LastPosition(a1, 1);
    assert(out1 == 0);

    // Test case 2
    std::vector<int> a2 = {1, 1, 1, 2, 3, 4};
    int out2 = LastPosition(a2, 1);
    assert(out2 == 2);

    // Test case 3
    std::vector<int> a3 = {2, 3, 2, 3, 6, 8, 9};
    int out3 = LastPosition(a3, 3);
    assert(out3 == 3);
}

int main() {
    testLastPosition();
    return 0;
}