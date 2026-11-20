#include <stdio.h>
#include <ctype.h>
#include <string.h>

static int is_keyword(const char *word) {
    const char *keywords[] = {
        "auto","break","case","char","const","continue","default","do","double",
        "else","enum","extern","float","for","goto","if","int","long","register",
        "return","short","signed","sizeof","static","struct","switch","typedef",
        "union","unsigned","void","volatile","while","main","printf","scanf"
    };
    size_t i;
    for (i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++)
        if (strcmp(word, keywords[i]) == 0) return 1;
    return 0;
}

int main(void) {
    char line[1000], word[100];
    int i, j;

    printf("Enter C code (finish with a line containing END):\n");
    while (fgets(line, sizeof(line), stdin)) {
        if (strcmp(line, "END\n") == 0 || strcmp(line, "END") == 0) break;
        for (i = 0; line[i]; ) {
            if (isspace((unsigned char)line[i])) { i++; continue; }
            if (line[i] == '/' && line[i+1] == '/') break;
            if (line[i] == '/' && line[i+1] == '*') {
                i += 2;
                while (line[i] && !(line[i] == '*' && line[i+1] == '/')) i++;
                if (line[i]) i += 2;
                continue;
            }
            if (isalpha((unsigned char)line[i]) || line[i] == '_') {
                j = 0;
                while ((isalnum((unsigned char)line[i]) || line[i] == '_') && j < 98)
                    word[j++] = line[i++];
                word[j] = '\0';
                printf("%s : %s\n", word, is_keyword(word) ? "keyword" : "identifier");
            } else if (isdigit((unsigned char)line[i])) {
                j = 0;
                while ((isdigit((unsigned char)line[i]) || line[i] == '.') && j < 98)
                    word[j++] = line[i++];
                word[j] = '\0';
                printf("%s : constant\n", word);
            } else {
                if (strchr("+-*/%=<>!&|", line[i]))
                    printf("%c : operator\n", line[i]);
                i++;
            }
        }
    }
    return 0;
}
