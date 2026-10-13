%option noyywrap

%{
#include <stdio.h>

int tags = 0;
%}

%%

"<"[^>]*> {
    tags++;
    printf("%s\n", yytext);
}

.|\n {
}

%%

int main()
{
    FILE *f;
    char file[100];

    printf("Enter HTML File Name: ");
    scanf("%99s", file);

    f = fopen(file, "r");

    if (f == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    yyin = f;
    yylex();

    printf("\nNumber of HTML tags: %d\n", tags);

    fclose(f);

    return 0;
}