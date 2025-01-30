#include "../FormalSpecCPP-NoSpec/task_id_273.cpp"

#include <vector>
#include <cassert>

// Assuming SubtractSequences and sequenceEquals are defined elsewhere
extern std::vector<int> SubtractSequences(const std::vector<int>& a, const std::vector<int>& b);

void testSubtractSequences() {
    // Test case 1
    std::vector<int> s1 = {10, 4, 5};
    std::vector<int> s2 = {2, 5, 18};
    std::vector<int> e1 = {8, -1, -13};
    std::vector<int> res1 = SubtractSequences(s1, s2);
    assert(res1==e1);

    // Test case 2
    std::vector<int> s3 = {11, 2, 3};
    std::vector<int> s4 = {24, 45, 16};
    std::vector<int> e2 = {-13, -43, -13};
    std::vector<int> res2 = SubtractSequences(s3, s4);
    assert(res2==e2);

    // Test case 3
    std::vector<int> s5 = {7, 18, 9};
    std::vector<int> s6 = {10, 11, 12};
    std::vector<int> e3 = {-3, 7, -3};
    std::vector<int> res3 = SubtractSequences(s5, s6);
    assert(res3==e3);
}

int main() {
    testSubtractSequences();
    return 0;
}