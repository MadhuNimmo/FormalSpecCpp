#include "../FormalSpecCPP/task_id_458.cpp"

#include <cassert>  // Required header for assertions

void testRectangleArea() {
    // Test case 1
    int out1 = RectangleArea(10, 20);
    assert(out1 == 200);

    // Test case 2
    int out2 = RectangleArea(10, 5);
    assert(out2 == 50);

    // Test case 3
    int out3 = RectangleArea(4, 2);
    assert(out3 == 8);
}

int main() {
    testRectangleArea();
    return 0;
}