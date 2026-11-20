#include <stdio.h>
#include <string.h>

int main(void) {
    char op[20];
    printf("Enter an arithmetic operator (+, -, *, /): ");
    if (scanf("%19s", op) != 1) return 1;

    if (strlen(op) != 1) {
        printf("Invalid arithmetic operator.\n");
        return 0;
    }

    switch (op[0]) {
        case '+': puts("Addition operator"); break;
        case '-': puts("Subtraction operator"); break;
        case '*': puts("Multiplication operator"); break;
        case '/': puts("Division operator"); break;
        default: puts("Invalid arithmetic operator");
    }
    return 0;
}
