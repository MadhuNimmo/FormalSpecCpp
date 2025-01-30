#include "../FormalSpecCPP/task_id_17.cpp"

#include <cassert>  // Required header for assertions

void testSquarePerimeter() {
    // Test case 1
    int res1 = SquarePerimeter(10);
    assert(res1 == 40);

    // Test case 2
    int res2 = SquarePerimeter(5);
    assert(res2 == 20);

    // Test case 3
    int res3 = SquarePerimeter(4);
    assert(res3 == 16);
}

int main() {
    testSquarePerimeter();
    return 0;
}