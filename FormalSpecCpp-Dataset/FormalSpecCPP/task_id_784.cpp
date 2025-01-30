#include <vector>
#include <cassert>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool IsEven(int n) {
    return n % 2 == 0;
}

bool IsOdd(int n) {
    return n % 2 != 0;
}

bool IsFirstEven(size_t evenIndex, const std::vector<int>& lst) {
    REQUIRE(evenIndex < lst.size());
    REQUIRE(IsEven(lst[evenIndex]));
    for (size_t i = 0; i < evenIndex; ++i) {
        if (!IsOdd(lst[i])) {
            return false;
        }
    }
    return true;
}

bool IsFirstOdd(size_t oddIndex, const std::vector<int>& lst) {
    REQUIRE(oddIndex < lst.size());
    REQUIRE(IsOdd(lst[oddIndex]));
    for (size_t i = 0; i < oddIndex; ++i) {
        if (!IsEven(lst[i])) {
            return false;
        }
    }
    return true;
}

void FirstEvenOddIndices(const std::vector<int>& lst, size_t& evenIndex, size_t& oddIndex) {
    REQUIRE(lst.size() >= 2);
    REQUIRE([&]() {
        for (int x : lst) if (IsEven(x)) return true;
        return false;
    }());
    REQUIRE([&]() {
        for (int x : lst) if (IsOdd(x)) return true;
        return false;
    }());

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

    ENSURE(evenIndex < lst.size());
    ENSURE(oddIndex < lst.size());
    ENSURE(IsEven(lst[evenIndex]) && IsFirstEven(evenIndex, lst));
    ENSURE(IsOdd(lst[oddIndex]) && IsFirstOdd(oddIndex, lst));
}

int ProductEvenOdd(const std::vector<int>& lst) {
    REQUIRE(lst.size() >= 2);
    REQUIRE([&]() {
        for (int x : lst) if (IsEven(x)) return true;
        return false;
    }());
    REQUIRE([&]() {
        for (int x : lst) if (IsOdd(x)) return true;
        return false;
    }());

    size_t evenIndex, oddIndex;
    FirstEvenOddIndices(lst, evenIndex, oddIndex);
    int product = lst[evenIndex] * lst[oddIndex];

    ENSURE([&]() {
        return IsEven(lst[evenIndex]) && IsFirstEven(evenIndex, lst) &&
               IsOdd(lst[oddIndex]) && IsFirstOdd(oddIndex, lst) &&
               product == lst[evenIndex] * lst[oddIndex];
    }());

    return product;
}