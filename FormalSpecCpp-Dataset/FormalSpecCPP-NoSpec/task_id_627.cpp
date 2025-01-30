#include <vector>


int SmallestMissingNumber(const std::vector<int>& s) {
    for (size_t i = 0; i < s.size(); ++i) {
        for (size_t j = i + 1; j < s.size(); ++j) {
        }
    }

    int v = 0;
    size_t i = 0;
    for (; i < s.size(); ++i) {
        bool v_not_in_s = true;
        for (size_t j = 0; j < i; ++j) {
            if (s[j] == v) {
                v_not_in_s = false;
                break;
            }
        }

        if (s[i] > v) {
            break;
        } else if (s[i] == v) {
            v += 1;
        }
    }

    bool v_not_in_s_final = true;
    for (size_t j = 0; j < s.size(); ++j) {
        if (s[j] == v) {
            v_not_in_s_final = false;
            break;
        }
    }

    for (int k = 0; k < v; ++k) {
        bool k_in_s = false;
        for (size_t j = 0; j < s.size(); ++j) {
            if (s[j] == k) {
                k_in_s = true;
                break;
            }
        }
    }

    return v;
}
