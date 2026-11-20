#include <stdio.h>
#include <string.h>

int main(void) {
    char lhs, rhs[200], *alts[20], alpha[20][100], beta[20][100];
    int na = 0, nb = 0;
    printf("Enter production (example E->E-A|b): ");
    if (scanf(" %c->%199s", &lhs, rhs) != 2) {
        puts("Invalid production format."); return 1;
    }
    char *token = strtok(rhs, "|");
    while (token && na + nb < 20) {
        if (token[0] == lhs) strcpy(alpha[na++], token + 1);
        else strcpy(beta[nb++], token);
        token = strtok(NULL, "|");
    }
    if (na == 0) { puts("Production has no immediate left recursion."); return 0; }
    if (nb == 0) { puts("Cannot eliminate left recursion: no beta alternative."); return 0; }

    printf("%c -> ", lhs);
    for (int i = 0; i < nb; i++) printf("%s%c'%s", beta[i], lhs, i == nb-1 ? "\n" : " | ");
    printf("%c' -> ", lhs);
    for (int i = 0; i < na; i++) printf("%s%c'%s", alpha[i], lhs, i == na-1 ? " | $\n" : " | ");
    return 0;
}
