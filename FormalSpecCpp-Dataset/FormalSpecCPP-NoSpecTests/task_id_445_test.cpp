#include "../FormalSpecCPP-NoSpec/task_id_445.cpp"

#include <cassert>
#include <vector>

void testMultiplyElements() {
    // Test case 1
    std::vector<int> s1 = {1, 3, 4, 5, 2, 9, 1, 10};
    std::vector<int> s2 = {6, 7, 3, 9, 1, 1, 7, 3};
    std::vector<int> res1 = MultiplyElements(s1, s2);
    std::vector<int> e1 = {6, 21, 12, 45, 2, 9, 7, 30};
    assert(res1 == e1);

    // Test case 2
    std::vector<int> s3 = {2, 4, 5, 6, 3, 10, 2, 11};
    std::vector<int> s4 = {7, 8, 4, 10, 2, 2, 8, 4};
    std::vector<int> res2 = MultiplyElements(s3, s4);
    std::vector<int> e2 = {14, 32, 20, 60, 6, 20, 16, 44};
    assert(res2 == e2);

    // Test case 3
    std::vector<int> s5 = {3, 5, 6, 7, 4, 11, 3, 12};
    std::vector<int> s6 = {8, 9, 5, 11, 3, 3, 9, 5};
    std::vector<int> res3 = MultiplyElements(s5, s6);
    std::vector<int> e3 = {24, 45, 30, 77, 12, 33, 27, 60};
    assert(res3 == e3);
}

int main() {
    testMultiplyElements();
    return 0;
}