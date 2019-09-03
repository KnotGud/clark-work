
int global[10];

int put(int index, int x) {
    global[index] = x;
    return 0;
}

int get(int index) {
    return global[index];
}