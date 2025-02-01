#include "task_id_618.cpp"

#include <vector>
#include <cassert>
#include <cmath>

void testElementWiseDivide() {
    // Test case 1
    std::vector<int> s1 = {4, 5, 6};
    std::vector<int> s2 = {1, 2, 3};
    std::vector<double> e1 = {4.0, 2.5, 2.0};
    auto res1 = ElementWiseDivide(s1, s2);
    assert(res1.size() == e1.size() && std::equal(res1.begin(), res1.end(), e1.begin(), [](double a, double b) { return std::abs(a - b) < 1e-9; }));

    // Test case 2
    std::vector<int> s3 = {3, 2};
    std::vector<int> s4 = {1, 4};
    std::vector<double> e2 = {3.0, 0.5};
    auto res2 = ElementWiseDivide(s3, s4);
    assert(res2.size() == e2.size() && std::equal(res2.begin(), res2.end(), e2.begin(), [](double a, double b) { return std::abs(a - b) < 1e-9; }));

    // Test case 3
    std::vector<int> s5 = {90, 120};
    std::vector<int> s6 = {50, 70};
    std::vector<double> e3 = {1.8, 1.7142857142857142};
    auto res3 = ElementWiseDivide(s5, s6);
    assert(res3.size() == e3.size() && std::equal(res3.begin(), res3.end(), e3.begin(), [](double a, double b) { return std::abs(a - b) < 1e-9; }));
}

int main() {
    testElementWiseDivide();
    return 0;
}