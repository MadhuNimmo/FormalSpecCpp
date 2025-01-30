int TetrahedralNumber(unsigned int n) {

    // Calculate the tetrahedral number
    unsigned long long t = n * (n + 1) * (n + 2) / 6;


    return static_cast<int>(t);
}
