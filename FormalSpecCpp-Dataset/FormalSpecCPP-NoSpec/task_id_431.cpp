#include <vector>

bool HasCommonElement(const std::vector<int>& a, const std::vector<int>& b) {

    bool result = false;
    size_t a_length = a.size();
    size_t b_length = b.size();

    for (size_t i = 0; i < a_length; ++i) {
        if (!result) {
            for (size_t k = 0; k < i; ++k) {
                for (size_t j = 0; j < b_length; ++j) {
                }
            }
        }

        for (size_t j = 0; j < b_length; ++j) {
            if (!result) {
                for (size_t k = 0; k < j; ++k) {
                }
            }

            if (a[i] == b[j]) {
                result = true;
                return result;
            }
        }
    }

    if (!result) {
        for (size_t i = 0; i < a_length; ++i) {
            for (size_t j = 0; j < b_length; ++j) {
            }
        }
    }


    return result;
}
