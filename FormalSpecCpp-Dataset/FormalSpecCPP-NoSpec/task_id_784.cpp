#include <vector>

bool IsEven(int n) {
    return n % 2 == 0;
}

bool IsOdd(int n) {
    return n % 2 != 0;
}

bool IsFirstEven(size_t evenIndex, const std::vector<int>& lst) {
    for (size_t i = 0; i < evenIndex; ++i) {
        if (!IsOdd(lst[i])) {
            return false;
        }
    }
    return true;
}

bool IsFirstOdd(size_t oddIndex, const std::vector<int>& lst) {
    for (size_t i = 0; i < oddIndex; ++i) {
        if (!IsEven(lst[i])) {
            return false;
        }
    }
    return true;
}

void FirstEvenOddIndices(const std::vector<int>& lst, size_t& evenIndex, size_t& oddIndex) {

    evenIndex = lst.size(); // Initialize to an invalid index
    oddIndex = lst.size(); // Initialize to an invalid index

    for (size_t i = 0; i < lst.size(); ++i) {
        if (IsEven(lst[i])) {
            evenIndex = i;
            break;
        }
    }

    for (size_t i = 0; i < lst.size(); ++i) {
        if (IsOdd(lst[i])) {
            oddIndex = i;
            break;
        }
    }

}

int ProductEvenOdd(const std::vector<int>& lst) {

    size_t evenIndex, oddIndex;
    FirstEvenOddIndices(lst, evenIndex, oddIndex);
    int product = lst[evenIndex] * lst[oddIndex];


    return product;
}
