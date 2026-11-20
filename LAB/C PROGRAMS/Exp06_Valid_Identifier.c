#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char id[100];
    int i, valid = 1;

    printf("Enter an identifier: ");
    if (scanf("%99s", id) != 1) return 1;

    if (!(isalpha((unsigned char)id[0]) || id[0] == '_')) valid = 0;
    for (i = 1; id[i]; i++)
        if (!(isalnum((unsigned char)id[i]) || id[i] == '_')) valid = 0;

    puts(valid ? "Valid identifier" : "Invalid identifier");
    return 0;
}
