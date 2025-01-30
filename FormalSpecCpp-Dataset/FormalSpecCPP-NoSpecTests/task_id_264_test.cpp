#include "../FormalSpecCPP-NoSpec/task_id_264.cpp"

#include <cassert>  // Required header for assertions

void testDogYears() {
    // Test case 1
    unsigned int res1 = DogYears(12);
    assert(res1 == 61);

    // Test case 2
    unsigned int res2 = DogYears(15);
    assert(res2 == 73);

    // Test case 3
    unsigned int res3 = DogYears(24);
    assert(res3 == 109);
}

int main() {
    testDogYears();
    return 0;
}