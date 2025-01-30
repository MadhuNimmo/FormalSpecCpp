#include <vector>


std::vector<int> RotateRight(const std::vector<int>& l, unsigned int n) {

    size_t length = l.size();
    std::vector<int> rotated(length);

    // Loop to fill the rotated vector
    for (size_t i = 0; i < length; ++i) {

        int index = (i - n + length) % length; // Calculate the new index considering rotation
        if (index < 0) {
            index += length; // Correct negative index
        }
        rotated[i] = l[index];

        for (size_t k = 0; k <= i; ++k) {
            int check_index = (k - n + length) % length;
            if (check_index < 0) {
                check_index += length;
            }
        }
    }

    for (size_t i = 0; i < length; ++i) {
    }

    return rotated;
}
