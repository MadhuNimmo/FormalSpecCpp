#include "../FormalSpecCPP-NoSpec/task_id_14.cpp"

#include <cassert>  // Required header for assertions

void testTriangularPrismVolume() {
    // Test case 1
    double out1 = TriangularPrismVolume(10, 8, 6);
    assert(out1 == 240);

    // Test case 2
    double out2 = TriangularPrismVolume(3, 2, 2);
    assert(out2 == 6);

    // Test case 3
    double out3 = TriangularPrismVolume(1, 2, 1);
    assert(out3 == 1);
}

int main() {
    testTriangularPrismVolume();
    return 0;
}