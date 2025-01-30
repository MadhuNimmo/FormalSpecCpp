double ParabolaDirectrix(int a, int h, int k) {

    // Fix: Ensure floating-point division by casting `1` to a double
    double directrix = k - (1.0 / (4.0 * a));


    return directrix;
}
