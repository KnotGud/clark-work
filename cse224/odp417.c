int rem1(char* in, char* out) {
    while (*in) {
        if (*in == 'x') {
            in++;
            break;
        }
        *out++ = *in++;
    }
    while (*in) { *out++ = *in++; }
    *out = '\0';
    return 0;
}