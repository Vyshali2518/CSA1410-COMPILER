#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    char code[100][100];
    printf("Enter number of three-address statements: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) return 1;
    for (int i = 0; i < n; i++) {
        printf("Enter statement %d (example a=b+c): ", i + 1);
        scanf("%99s", code[i]);
    }

    puts("\nGenerated target code:");
    for (int i = 0; i < n; i++) {
        char lhs[40], a[40], b[40], op = '\0';
        char *eq = strchr(code[i], '=');
        if (!eq) { printf("; Invalid statement: %s\n", code[i]); continue; }
        *eq = '\0'; strcpy(lhs, code[i]);
        char *rhs = eq + 1;
        char *operator_pos = strpbrk(rhs, "+-*/");
        if (!operator_pos) {
            printf("MOV R0, %s\nMOV %s, R0\n", rhs, lhs);
            continue;
        }
        op = *operator_pos; *operator_pos = '\0';
        strcpy(a, rhs); strcpy(b, operator_pos + 1);
        printf("MOV R0, %s\n", a);
        switch (op) {
            case '+': printf("ADD R0, %s\n", b); break;
            case '-': printf("SUB R0, %s\n", b); break;
            case '*': printf("MUL R0, %s\n", b); break;
            case '/': printf("DIV R0, %s\n", b); break;
        }
        printf("MOV %s, R0\n", lhs);
    }
    return 0;
}
