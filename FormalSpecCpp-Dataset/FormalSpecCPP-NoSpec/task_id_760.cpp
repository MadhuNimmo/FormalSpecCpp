#include <vector>


bool HasOnlyOneDistinctElement(const std::vector<int>& a) {

    if (a.size() == 0) {
        return true;
    }

    int firstElement = a[0];
    bool result = true;

    for (size_t i = 1; i < a.size(); ++i) {

        if (a[i] != firstElement) {
            result = false;
            break;
        }
    }

    if (result) {
    } else {
    }

    return result;
}
