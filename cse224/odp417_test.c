#include <stdio.h>

int main() {
    char* a = "testxxxhello";
    char* b = "xxxhello";
    char* c = "testxxx";
    char  r[20];
    rem1(a, r);
    printf("%s\n", r);
    rem1(b, r);
    printf("%s\n", r);
    rem1(c, r);
    printf("%s\n", r);
}