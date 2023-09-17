double square_root(double input) {
    long double x[21];
    x[0] = input;

    for (int i; i < 20; i++) {
        x[i + 1] = 0.5 * (x[i] + x[0] / x[i]);
    }

    return x[20];
}