#include <stdio.h>
#include <string.h>

/* Grammar: S -> aS | Sb | ab. Its strings contain one or more a's
   followed by one or more b's. */
int main(void) {
    char input[200];
    int i = 0, seen_b = 0, valid = 1, a_count = 0, b_count = 0;

    printf("Grammar: S -> aS | Sb | ab\nEnter string: ");
    if (scanf("%199s", input) != 1) return 1;

    for (i = 0; input[i]; i++) {
        if (input[i] == 'a' && !seen_b) a_count++;
        else if (input[i] == 'b') { seen_b = 1; b_count++; }
        else { valid = 0; break; }
    }
    if (a_count == 0 || b_count == 0) valid = 0;
    puts(valid ? "String accepted." : "String rejected.");
    return 0;
}
