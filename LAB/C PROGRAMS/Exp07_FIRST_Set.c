#include <stdio.h>
#include <string.h>
#include <ctype.h>

char productions[20][40];
int count;

void add(char *set, char c) {
    int i;
    for (i = 0; set[i]; i++) if (set[i] == c) return;
    i = (int)strlen(set);
    set[i] = c;
    set[i + 1] = '\0';
}

void first(char *result, char symbol, int depth) {
    int p, k;
    if (depth > 20) return;
    if (!isupper((unsigned char)symbol)) { add(result, symbol); return; }

    for (p = 0; p < count; p++) {
        if (productions[p][0] != symbol) continue;
        if (productions[p][2] == '$' || productions[p][2] == '@') {
            add(result, '$');
            continue;
        }
        for (k = 2; productions[p][k]; k++) {
            char part[40] = "";
            first(part, productions[p][k], depth + 1);
            for (int x = 0; part[x]; x++) if (part[x] != '$') add(result, part[x]);
            if (!strchr(part, '$')) break;
            if (!productions[p][k + 1]) add(result, '$');
        }
    }
}

int main(void) {
    char symbol, result[40] = "";
    printf("Enter number of productions: ");
    scanf("%d", &count);
    if (count < 1 || count > 20) return 1;
    printf("Enter productions without spaces (example S=AB, A=a, B=$):\n");
    for (int i = 0; i < count; i++) scanf("%39s", productions[i]);
    printf("Enter non-terminal to find FIRST: ");
    scanf(" %c", &symbol);
    first(result, symbol, 0);
    printf("FIRST(%c) = { ", symbol);
    for (int i = 0; result[i]; i++) printf("%c ", result[i]);
    puts("}");
    return 0;
}
