#include <vector>


bool IsEven(int n) {
    return n % 2 == 0;
}

bool IsOdd(int n) {
    return n % 2 != 0;
}

int FirstEvenOddDifference(const std::vector<int>& a) {

    int firstEven = -1;
    int firstOdd = -1;

    for (size_t i = 0; i < a.size(); ++i) {

        if (firstEven == -1 && IsEven(a[i])) {
            firstEven = i;
        }
        if (firstOdd == -1 && IsOdd(a[i])) {
            firstOdd = i;
        }
        if (firstEven != -1 && firstOdd != -1) {
            break;
        }
    }

    int diff = a[firstEven] - a[firstOdd];
    return diff;
}
