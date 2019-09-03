#include <stdio.h>

int rem(char* in, char* out) {
    char* p = out;
    while (*in) {
        if (*in != 'x') {
            *out = *in;
            out++;
        }
        in++;
    }
    *out = '\0';
    return p;
}