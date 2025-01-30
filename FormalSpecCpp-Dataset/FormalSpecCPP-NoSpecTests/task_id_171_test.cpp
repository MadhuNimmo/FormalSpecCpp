#include "../FormalSpecCPP-NoSpec/task_id_171.cpp"

#include <cassert>  // Required header for assertions

void testPentagonPerimeter() {
    // Test case 1
    int res1 = PentagonPerimeter(5);
    assert(res1 == 25);

    // Test case 2
    int res2 = PentagonPerimeter(10);
    assert(res2 == 50);

    // Test case 3
    int res3 = PentagonPerimeter(15);
    assert(res3 == 75);
}

int main() {
    testPentagonPerimeter();
    return 0;
}