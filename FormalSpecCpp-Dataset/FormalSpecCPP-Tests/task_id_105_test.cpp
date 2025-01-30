#include "../FormalSpecCPP/task_id_105.cpp"

#include <cassert>
#include <vector>

void testCountTrue() {
    // Test case 1
    std::vector<bool> a1 = {true, false, true};
    int out1 = CountTrue(a1);
    assert(out1 == 2);

    // Test case 2
    std::vector<bool> a2 = {false, false};
    int out2 = CountTrue(a2);
    assert(out2 == 0);

    // Test case 3
    std::vector<bool> a3 = {true, true, true};
    int out3 = CountTrue(a3);
    assert(out3 == 3);
}

int main() {
    testCountTrue();
    return 0;
}