#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[20][40], firstSet[26][40], followSet[26][40];
int n;

void add(char *s, char c) {
    if (c == '\0') return;
    for (int i = 0; s[i]; i++) if (s[i] == c) return;
    int k = (int)strlen(s); s[k] = c; s[k+1] = '\0';
}

void calc_first(char *out, char c) {
    if (!isupper((unsigned char)c)) { add(out, c); return; }
    for (int p = 0; p < n; p++) if (prod[p][0] == c) {
        if (prod[p][2] == '$' || prod[p][2] == '@') add(out, '$');
        else {
            char *s = firstSet[prod[p][2] - 'A'];
            for (int k = 0; s[k]; k++) add(out, s[k]);
        }
    }
}

int main(void) {
    printf("Enter number of productions: ");
    scanf("%d", &n);
    if (n < 1 || n > 20) return 1;
    printf("Enter productions (example S=AB, A=a, B=$):\n");
    for (int i = 0; i < n; i++) scanf("%39s", prod[i]);

    /* Compute FIRST sets for the simple grammar format used in this lab. */
    for (int pass = 0; pass < 10; pass++)
        for (int p = 0; p < n; p++) {
            char lhs = prod[p][0];
            if (prod[p][2] == '$' || prod[p][2] == '@') add(firstSet[lhs-'A'], '$');
            else {
                char c = prod[p][2];
                if (!isupper((unsigned char)c)) add(firstSet[lhs-'A'], c);
                else for (int k = 0; firstSet[c-'A'][k]; k++) add(firstSet[lhs-'A'], firstSet[c-'A'][k]);
            }
        }

    add(followSet[prod[0][0]-'A'], '$');
    for (int pass = 0; pass < 20; pass++)
        for (int p = 0; p < n; p++) {
            char lhs = prod[p][0];
            for (int j = 2; prod[p][j]; j++) {
                char B = prod[p][j];
                if (!isupper((unsigned char)B)) continue;
                if (prod[p][j+1]) {
                    char beta = prod[p][j+1];
                    if (!isupper((unsigned char)beta)) add(followSet[B-'A'], beta);
                    else {
                        for (int k = 0; firstSet[beta-'A'][k]; k++)
                            if (firstSet[beta-'A'][k] != '$') add(followSet[B-'A'], firstSet[beta-'A'][k]);
                        if (strchr(firstSet[beta-'A'], '$'))
                            for (int k = 0; followSet[lhs-'A'][k]; k++) add(followSet[B-'A'], followSet[lhs-'A'][k]);
                    }
                } else {
                    for (int k = 0; followSet[lhs-'A'][k]; k++) add(followSet[B-'A'], followSet[lhs-'A'][k]);
                }
            }
        }

    char target;
    printf("Enter non-terminal to find FOLLOW: ");
    scanf(" %c", &target);
    printf("FOLLOW(%c) = { ", target);
    for (int i = 0; followSet[target-'A'][i]; i++) printf("%c ", followSet[target-'A'][i]);
    puts("}");
    return 0;
}
