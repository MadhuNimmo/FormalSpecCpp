bool IsNonPrime(int n) {

    bool result = false;
    int i = 2;

    // Loop with invariants
    while (i <= n / 2) {

        if (n % i == 0) {
            result = true;
            break;
        }
        i = i + 1;
    }

    return result;
}
