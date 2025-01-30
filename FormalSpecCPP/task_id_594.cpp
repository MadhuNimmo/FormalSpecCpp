#include <cassert>
#include <vector>

// Required macro definitions
#define REQUIRE(cond) assert(cond)
#define ENSURE(cond) assert(cond)

bool IsEven(int n) {
    return n % 2 == 0;
}

bool IsOdd(int n) {
    return n % 2 != 0;
}

int FirstEvenOddDifference(const std::vector<int>& a) {
    REQUIRE(a.size() >= 2);
    REQUIRE([&]() {
        for (size_t i = 0; i < a.size(); ++i) {
            if (IsEven(a[i])) return true;
        }
        return false;
    }()); // Ensure there is at least one even number
    REQUIRE([&]() {
        for (size_t i = 0; i < a.size(); ++i) {
            if (IsOdd(a[i])) return true;
        }
        return false;
    }()); // Ensure there is at least one odd number

    int firstEven = -1;
    int firstOdd = -1;

    for (size_t i = 0; i < a.size(); ++i) {
        assert((firstEven == -1 || (0 <= firstEven && static_cast<size_t>(firstEven) < i && IsEven(a[firstEven]))));
        assert((firstOdd == -1 || (0 <= firstOdd && static_cast<size_t>(firstOdd) < i && IsOdd(a[firstOdd]))));
        assert((firstEven == -1 || [&]() {
            for (size_t k = 0; k < static_cast<size_t>(firstEven); ++k) {
                if (!IsOdd(a[k])) return false;
            }
            return true;
        }()));
        assert((firstOdd == -1 || [&]() {
            for (size_t k = 0; k < static_cast<size_t>(firstOdd); ++k) {
                if (!IsEven(a[k])) return false;
            }
            return true;
        }()));

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
    ENSURE([&]() {
        return IsEven(a[firstEven]) && IsOdd(a[firstOdd]) && diff == a[firstEven] - a[firstOdd];
    }());
    return diff;
}