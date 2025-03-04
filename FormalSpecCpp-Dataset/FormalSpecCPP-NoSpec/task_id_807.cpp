#include <vector>

// Helper function to check if a number is odd
bool IsOdd(int x) {
    return x % 2 != 0;
}

// Function to find the first odd number in an array
int FindFirstOdd(const std::vector<int>& a) {

    bool found = false;
    size_t index = 0;

    while (index < a.size()) {

        if (IsOdd(a[index])) {
            found = true;
            break; // Exit the loop as we found the odd number
        }
        index++;
    }

    if (found) {
        return a[index];
    }else{
        return -1;
    }
}