#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    switch (argc) {
        case 1:
            exit(1);
            return 1;
        case 2: {
            double r;
            sscanf(argv[1], "%lf", &r);
            printf("%lf\n", sqrt(r));
        }
        default:
            return 1;
    }
}