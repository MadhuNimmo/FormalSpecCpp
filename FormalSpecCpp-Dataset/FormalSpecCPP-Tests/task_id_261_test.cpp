#include "task_id_261.cpp"

#include <vector>
#include <cassert>
#include <cmath>

void testElementWiseDivision() {
    // Test case 1
    std::vector<int> s1 = {10, 4, 6, 9};
    std::vector<int> s2 = {5, 2, 3, 3};
    std::vector<double> e1 = {2.0, 2.0, 2.0, 3.0};
    std::vector<double> res1 = ElementWiseDivision(s1, s2);
    assert(res1.size() == e1.size() && std::equal(res1.begin(), res1.end(), e1.begin(), [](double a, double b) { return std::abs(a - b) < 1e-6; }));

    // Test case 2
    std::vector<int> s3 = {12, 6, 8, 16};
    std::vector<int> s4 = {6, 3, 4, 4};
    std::vector<double> e2 = {2.0, 2.0, 2.0, 4.0};
    std::vector<double> res2 = ElementWiseDivision(s3, s4);
    assert(res2.size() == e2.size() && std::equal(res2.begin(), res2.end(), e2.begin(), [](double a, double b) { return std::abs(a - b) < 1e-6; }));

    // Test case 3
    std::vector<int> s5 = {20, 14, 36, 18};
    std::vector<int> s6 = {5, 7, 6, 9};
    std::vector<double> e3 = {4.0, 2.0, 6.0, 2.0};
    std::vector<double> res3 = ElementWiseDivision(s5, s6);
    assert(res3.size() == e3.size() && std::equal(res3.begin(), res3.end(), e3.begin(), [](double a, double b) { return std::abs(a - b) < 1e-6; }));
}

int main() {
    testElementWiseDivision();
    return 0;
}