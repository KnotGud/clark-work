int pick(int n) {
    int r = n % 4;
    if (r == 0) {
        return 1;
    } else {
        return r;
    }
}