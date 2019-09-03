
int global;

int put(int x) {
    global = x;
    return 0;
}

int get() {
    return global;
}