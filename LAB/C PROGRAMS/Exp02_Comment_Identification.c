#include <stdio.h>
#include <string.h>

int main(void) {
    char line[500];
    size_t n;

    printf("Enter a line: ");
    if (!fgets(line, sizeof(line), stdin)) return 1;
    n = strlen(line);

    if (n >= 2 && line[0] == '/' && line[1] == '/') {
        printf("It is a single-line comment.\n");
    } else if (n >= 4 && line[0] == '/' && line[1] == '*') {
        char *end = strstr(line + 2, "*/");
        printf(end ? "It is a multi-line comment.\n" : "It is not a complete comment.\n");
    } else {
        printf("It is not a comment.\n");
    }
    return 0;
}
