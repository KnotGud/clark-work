
int main() {
    char  r[20];
    char* a = "hello";
    char* b = "ta";
    char* c = "abcdefg";
    move(a, r);
    printf("%s\n", r);
    move(b, r);
    printf("%s\n", r);
    move(c, r);
    printf("%s\n", r);
}