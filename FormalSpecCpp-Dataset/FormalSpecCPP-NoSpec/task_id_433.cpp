#include <vector>


bool IsGreater(const std::vector<int>& a, int n) {

    bool result = true;
    size_t i = 0;

    while (i < a.size()) {
        if (result) {
            for (size_t k = 0; k < i; ++k) {
            }
        } else {
            bool exists = false;
            for (size_t k = 0; k < i; ++k) {
                if (n <= a[k]) {
                    exists = true;
                    break;
                }
            }
        }

        if (n <= a[i]) {
            result = false;
            break;
        }
        i++;
    }

    if (result) {
        for (size_t j = 0; j < a.size(); ++j) {
        }
    } else {
        bool exists = false;
        for (size_t j = 0; j < a.size(); ++j) {
            if (n <= a[j]) {
                exists = true;
                break;
            }
        }
    }

    return result;
}
