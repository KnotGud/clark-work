
int move(char* in, char* out) {
    char first = *in++;
    while (*in) { *out++ = *in++; }
    *out++ = first;
    *out   = '\0';
    return 1;
}