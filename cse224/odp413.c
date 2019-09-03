
int counte(char* in) {
    int ret = 0;
    while (*in) {
        if (*in == 'e') { ret++; }
        in++;
    }
    return ret;
}
