#include "../FormalSpecCPP-NoSpec/task_id_599.cpp"

#include <cassert>  // Required header for assertions
#include <tuple>    // Required header for using std::tuple

void testSumAndAverage() {
    // Test case 1
    auto [sum1, avg1] = SumAndAverage(10);
    assert(sum1 == 55);
    assert(avg1 == 5.5);

    // Test case 2
    auto [sum2, avg2] = SumAndAverage(15);
    assert(sum2 == 120);
    assert(avg2 == 8.0);

    // Test case 3
    auto [sum3, avg3] = SumAndAverage(20);
    assert(sum3 == 210);
    assert(avg3 == 10.5);
}

int main() {
    testSumAndAverage();
    return 0;
}