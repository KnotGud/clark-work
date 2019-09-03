#include <math.h>
#include <stdio.h>

int main(int argc, char** argv) {
    switch (argc) {
        case 1:
            printf("ERR\n");
            return 1;
        case 2: {
            int    c;
            double r;
            c = sscanf(argv[1], "%lf", &r);
            if (c != 1) {
                printf("INV\n");
                return 1;
            }
            if (r < 0) {
                printf("NEG\n");
                return 1;
            }
            printf("%lf\n", sqrt(r));
            return 1;
        }
        default:
            printf("ERR\n");
            return 1;
    }
}