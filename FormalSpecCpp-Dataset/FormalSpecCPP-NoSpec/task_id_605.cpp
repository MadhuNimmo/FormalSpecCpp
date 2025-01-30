bool IsPrime(unsigned int n) {

    bool result = true;
    unsigned int i = 2;

    while (i <= n / 2) {

        if (n % i == 0) {
            result = false;
            break;
        }
        i = i + 1;
    }


    return result;
}
