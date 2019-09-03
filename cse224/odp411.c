#include <stdio.h>

int parse(char* str) {
    int r;
    int chk = sscanf(str, "%d", &r);
    if (chk != 1) { return -1; }
    switch (r) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        default:
            return -1;
    }
}