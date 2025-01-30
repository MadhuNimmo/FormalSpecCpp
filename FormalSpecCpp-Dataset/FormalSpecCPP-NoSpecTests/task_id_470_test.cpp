#include "../FormalSpecCPP-NoSpec/task_id_470.cpp"

#include <vector>
#include <cassert>

void testPairwiseAddition() {
    // Test case 1
    std::vector<int> s1 = {1, 5, 7, 8, 10};
    std::vector<int> e1 = {6, 12, 15, 18};
    std::vector<int> res1 = PairwiseAddition(s1);
    assert(res1 == e1);

    // Test case 2
    std::vector<int> s2 = {2, 6, 8, 9, 11};
    std::vector<int> e2 = {8, 14, 17, 20};
    std::vector<int> res2 = PairwiseAddition(s2);
    assert(res2 == e2);

    // Test case 3
    std::vector<int> s3 = {3, 7, 9, 10, 12};
    std::vector<int> e3 = {10, 16, 19, 22};
    std::vector<int> res3 = PairwiseAddition(s3);
    assert(res3 == e3);
}

int main() {
    testPairwiseAddition();
    return 0;
}