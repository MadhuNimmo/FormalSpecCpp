#include "../FormalSpecCPP-NoSpec/task_id_401.cpp"

#include <cassert>
#include <vector>

void testIndexWiseAddition() {
    // Test case 1
    std::vector<std::vector<int>> s1 = {{1, 3}, {4, 5}, {2, 9}, {1, 10}};
    std::vector<std::vector<int>> s2 = {{6, 7}, {3, 9}, {1, 1}, {7, 3}};
    std::vector<std::vector<int>> expected1 = {{7, 10}, {7, 14}, {3, 10}, {8, 13}};
    auto result1 = IndexWiseAddition(s1, s2);
    assert(result1 == expected1);

    // Test case 2
    std::vector<std::vector<int>> s3 = {{2, 4}, {5, 6}, {3, 10}, {2, 11}};
    std::vector<std::vector<int>> s4 = {{7, 8}, {4, 10}, {2, 2}, {8, 4}};
    std::vector<std::vector<int>> expected2 = {{9, 12}, {9, 16}, {5, 12}, {10, 15}};
    auto result2 = IndexWiseAddition(s3, s4);
    assert(result2 == expected2);

    // Test case 3
    std::vector<std::vector<int>> s5 = {{3, 5}, {6, 7}, {4, 11}, {3, 12}};
    std::vector<std::vector<int>> s6 = {{8, 9}, {5, 11}, {3, 3}, {9, 5}};
    std::vector<std::vector<int>> expected3 = {{11, 14}, {11, 18}, {7, 14}, {12, 17}};
    auto result3 = IndexWiseAddition(s5, s6);
    assert(result3 == expected3);
}

int main() {
    testIndexWiseAddition();
    return 0;
}