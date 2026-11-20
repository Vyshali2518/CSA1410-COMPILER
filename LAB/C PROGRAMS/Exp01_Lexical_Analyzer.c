#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char input[500];
    int i = 0;

    printf("Enter a C expression: ");
    if (!fgets(input, sizeof(input), stdin)) return 1;

    printf("\nIdentifiers: ");
    for (i = 0; input[i]; ) {
        if (isalpha((unsigned char)input[i]) || input[i] == '_') {
            int start = i;
            while (isalnum((unsigned char)input[i]) || input[i] == '_') i++;
            printf("%.*s ", i - start, input + start);
        } else if (isdigit((unsigned char)input[i])) {
            int start = i;
            while (isdigit((unsigned char)input[i]) || input[i] == '.') i++;
            /* Numbers are printed in the constants section below. */
            (void)start;
        } else i++;
    }

    printf("\nConstants: ");
    for (i = 0; input[i]; ) {
        if (isdigit((unsigned char)input[i])) {
            int start = i;
            while (isdigit((unsigned char)input[i]) || input[i] == '.') i++;
            printf("%.*s ", i - start, input + start);
        } else i++;
    }

    printf("\nOperators: ");
    for (i = 0; input[i]; i++) {
        if (strchr("+-*/%=<>!&|", input[i])) {
            printf("%c ", input[i]);
        }
    }
    printf("\n");
    return 0;
}
