#include "../FormalSpecCPP/task_id_424.cpp"

#include <cassert>
#include <vector>
#include <string>

void testExtractRearChars() {
    // Test case 1
    std::vector<std::string> s1 = {"Mers", "for", "Vers"};
    std::vector<char> e1 = {'s', 'r', 's'};
    auto res1 = ExtractRearChars(s1);
    assert(res1 == e1);

    // Test case 2
    std::vector<std::string> s2 = {"Avenge", "for", "People"};
    std::vector<char> e2 = {'e', 'r', 'e'};
    auto res2 = ExtractRearChars(s2);
    assert(res2 == e2);

    // Test case 3
    std::vector<std::string> s3 = {"Gotta", "get", "go"};
    std::vector<char> e3 = {'a', 't', 'o'};
    auto res3 = ExtractRearChars(s3);
    assert(res3 == e3);
}

int main() {
    testExtractRearChars();
    return 0;
}