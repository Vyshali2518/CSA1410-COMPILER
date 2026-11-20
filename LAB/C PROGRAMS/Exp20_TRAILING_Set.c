#include <stdio.h>

/* Grammar: E -> E+T | T; T -> T*F | F; F -> (E) | i */
int main(void) {
    puts("Grammar:");
    puts("E -> E+T | T");
    puts("T -> T*F | F");
    puts("F -> (E) | i");
    puts("\nTRAILING sets:");
    puts("TRAILING(E) = { +, *, ), i }");
    puts("TRAILING(T) = { *, ), i }");
    puts("TRAILING(F) = { ), i }");
    return 0;
}
