bool IsPerfectSquare(unsigned int n) {

    unsigned int i = 0;
    while (i * i < n) {
        for (unsigned int k = 0; k < i; ++k) {
        }
        i++;
    }

    bool result = (i * i == n);
    if (result) {
    } else {
        // it's a logical consequence of the algorithm and the loop exit condition.
    }

    return result;
}
