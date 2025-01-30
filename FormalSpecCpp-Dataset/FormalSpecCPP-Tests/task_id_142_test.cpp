#include "../FormalSpecCPP/task_id_142.cpp"

#include <cassert>
#include <vector>

void testCountIdenticalPositions() {
    // Test case 1
    std::vector<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> s2 = {2, 2, 3, 1, 2, 6, 7, 9};
    std::vector<int> s3 = {2, 1, 3, 1, 2, 6, 7, 9};
    int res1 = CountIdenticalPositions(s1, s2, s3);
    assert(res1 == 3);

    // Test case 2
    std::vector<int> s4 = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> s5 = {2, 2, 3, 1, 2, 6, 7, 8};
    std::vector<int> s6 = {2, 1, 3, 1, 2, 6, 7, 8};
    int res2 = CountIdenticalPositions(s4, s5, s6);
    assert(res2 == 4);

    // Test case 3
    std::vector<int> s7 = {1, 2, 3, 4, 2, 6, 7, 8};
    std::vector<int> s8 = {2, 2, 3, 1, 2, 6, 7, 8};
    std::vector<int> s9 = {2, 1, 3, 1, 2, 6, 7, 8};
    int res3 = CountIdenticalPositions(s7, s8, s9);
    assert(res3 == 5);
}

int main() {
    testCountIdenticalPositions();
    return 0;
}