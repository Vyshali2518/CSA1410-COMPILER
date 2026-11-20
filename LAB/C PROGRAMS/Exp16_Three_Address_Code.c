#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char statement[200], lhs[40], rhs[160], token[40];
    char operands[40][40], operators[40];
    int n = 0, op_count = 0, i = 0, j;

    printf("Enter assignment (example: result=a+b*c): ");
    if (scanf("%199s", statement) != 1) return 1;
    char *eq = strchr(statement, '=');
    if (!eq) { puts("Invalid assignment."); return 1; }
    *eq = '\0'; strcpy(lhs, statement); strcpy(rhs, eq + 1);

    while (rhs[i]) {
        if (isalnum((unsigned char)rhs[i]) || rhs[i] == '_') {
            j = 0;
            while ((isalnum((unsigned char)rhs[i]) || rhs[i] == '_') && j < 38) token[j++] = rhs[i++];
            token[j] = '\0'; strcpy(operands[n++], token);
        } else if (strchr("+-*/", rhs[i])) operators[op_count++] = rhs[i++];
        else { puts("Unsupported character in expression."); return 1; }
    }
    if (n != op_count + 1 || n > 40) { puts("Invalid expression."); return 1; }

    /* Respect multiplication/division before addition/subtraction. */
    char temp[40][40]; int used = 0;
    for (i = 0; i < n; i++) strcpy(temp[i], operands[i]);
    for (i = 0; i < op_count; i++) {
        if (operators[i] == '*' || operators[i] == '/') {
            char name[20]; sprintf(name, "t%d", ++used);
            printf("%s=%s%c%s\n", name, temp[i], operators[i], temp[i+1]);
            strcpy(temp[i], name);
            for (j = i+1; j < n-1; j++) strcpy(temp[j], temp[j+1]);
            for (j = i; j < op_count-1; j++) operators[j] = operators[j+1];
            n--; op_count--; i--;
        }
    }
    while (op_count > 0) {
        char name[20]; sprintf(name, "t%d", ++used);
        printf("%s=%s%c%s\n", name, temp[0], operators[0], temp[1]);
        strcpy(temp[0], name);
        for (j = 1; j < n-1; j++) strcpy(temp[j], temp[j+1]);
        for (j = 0; j < op_count-1; j++) operators[j] = operators[j+1];
        n--; op_count--;
    }
    printf("%s=%s\n", lhs, temp[0]);
    return 0;
}
