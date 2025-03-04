bool IsPerfectSquare(unsigned int n) {

    unsigned int i = 0;
    while (i * i < n) {
        i++;
    }

    bool result = (i * i == n);
    return result;
}
