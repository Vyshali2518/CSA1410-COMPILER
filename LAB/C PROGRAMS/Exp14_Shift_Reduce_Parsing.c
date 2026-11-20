#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Demonstrates shift-reduce actions for the grammar:
   E -> E+E | E-E | E*E | E/E | (E) | id */
int main(void) {
    char input[200], stack[400] = "";
    int top = 0;
    printf("Enter expression (single-letter identifiers): ");
    if (scanf("%199s", input) != 1) return 1;
    printf("\nStack\t\tInput\t\tAction\n");

    for (int i = 0; input[i]; i++) {
        stack[top++] = input[i]; stack[top] = '\0';
        printf("%-16s %-16s Shift %c\n", stack, input + i + 1, input[i]);
        if (isalpha((unsigned char)input[i])) {
            stack[top-1] = 'E';
            printf("%-16s %-16s Reduce E->id\n", stack, input + i + 1);
        }
        while (top >= 3 && stack[top-3] == 'E' &&
               strchr("+-*/", stack[top-2]) && stack[top-1] == 'E') {
            char op = stack[top-2];
            top -= 2; stack[top-1] = 'E'; stack[top] = '\0';
            printf("%-16s %-16s Reduce E->E%cE\n", stack, input + i + 1, op);
        }
        if (top >= 3 && stack[top-3] == '(' && stack[top-2] == 'E' && stack[top-1] == ')') {
            top -= 2; stack[top-1] = 'E'; stack[top] = '\0';
            printf("%-16s %-16s Reduce E->(E)\n", stack, input + i + 1);
        }
    }
    puts(strcmp(stack, "E") == 0 ? "ACCEPTED" : "Input processed; check grammar/parentheses.");
    return 0;
}
