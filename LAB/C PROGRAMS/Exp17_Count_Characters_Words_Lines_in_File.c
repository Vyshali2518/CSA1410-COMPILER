#include <stdio.h>
#include <ctype.h>

int main(void) {
    char filename[200];
    FILE *fp;
    int ch, in_word = 0, chars = 0, words = 0, lines = 0, last = '\n';

    printf("Enter input file name (example: sample_input.txt): ");
    if (scanf("%199s", filename) != 1) return 1;
    fp = fopen(filename, "r");
    if (!fp) { perror("Unable to open file"); return 1; }

    while ((ch = fgetc(fp)) != EOF) {
        chars++;
        if (ch == '\n') lines++;
        if (isspace((unsigned char)ch)) in_word = 0;
        else if (!in_word) { words++; in_word = 1; }
        last = ch;
    }
    if (chars > 0 && last != '\n') lines++;
    fclose(fp);

    printf("Characters: %d\nWords: %d\nLines: %d\n", chars, words, lines);
    return 0;
}
