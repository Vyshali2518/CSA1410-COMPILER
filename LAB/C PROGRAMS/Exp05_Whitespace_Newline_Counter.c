#include <stdio.h>

int main(void) {
    int ch, spaces = 0, tabs = 0, newlines = 0, characters = 0;

    printf("Enter text (press Ctrl+Z then Enter on Windows to finish):\n");
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') spaces++;
        else if (ch == '\t') tabs++;
        else if (ch == '\n') newlines++;
        else characters++;
    }

    printf("\nSpaces: %d\nTabs: %d\nNewline characters: %d\nOther characters: %d\n",
           spaces, tabs, newlines, characters);
    return 0;
}
