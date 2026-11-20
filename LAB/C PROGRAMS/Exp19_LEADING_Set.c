#include <stdio.h>

/* Grammar: E -> E+T | T; T -> T*F | F; F -> (E) | i */
int main(void) {
    puts("Grammar:");
    puts("E -> E+T | T");
    puts("T -> T*F | F");
    puts("F -> (E) | i");
    puts("\nLEADING sets:");
    puts("LEADING(E) = { +, *, (, i }");
    puts("LEADING(T) = { *, (, i }");
    puts("LEADING(F) = { (, i }");
    return 0;
}
