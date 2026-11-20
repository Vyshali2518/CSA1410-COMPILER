#include <stdio.h>
#include <string.h>

int main(void) {
    char lhs, rhs[200], alt[20][100], prefix[100];
    int n = 0, common = 0;
    printf("Enter production (example S->iEtS|iEtSeS|a): ");
    if (scanf(" %c->%199s", &lhs, rhs) != 2) return 1;

    char *token = strtok(rhs, "|");
    while (token && n < 20) { strcpy(alt[n++], token); token = strtok(NULL, "|"); }
    if (n < 2) { puts("At least two alternatives are required."); return 0; }

    while (alt[0][common]) {
        int same = 1;
        for (int i = 1; i < n; i++)
            if (alt[i][common] != alt[0][common]) same = 0;
        if (!same) break;
        common++;
    }
    if (common == 0) { puts("No common prefix. Left factoring is not required."); return 0; }

    strncpy(prefix, alt[0], common); prefix[common] = '\0';
    printf("%c -> %s%c'\n", lhs, prefix, lhs);
    printf("%c' -> ", lhs);
    for (int i = 0; i < n; i++) {
        const char *suffix = alt[i] + common;
        printf("%s%s", *suffix ? suffix : "$", i == n-1 ? "\n" : " | ");
    }
    return 0;
}
