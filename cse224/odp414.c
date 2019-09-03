#include <stdio.h>

int mix(char* A, char* B, char* out) {
    char* p = out;
    while (*A) {
        *out = *A;
        out++;
        A++;
        *out = *B;
        out++;
        B++;
    }
    *out = '\0';
    return 0;
}