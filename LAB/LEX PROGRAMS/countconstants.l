%option noyywrap

%{
#include <stdio.h>

int cons = 0;
%}

digit [0-9]

%%

{digit}+ {
    cons++;
    printf("%s is a constant\n", yytext);
}

[ \t\n]+ {
}

. {
}

%%

int main()
{
    FILE *f;
    char file[100];

    printf("Enter File Name: ");
    scanf("%99s", file);

    f = fopen(file, "r");

    if (f == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    yyin = f;
    yylex();

    printf("\nNumber of Constants: %d\n", cons);

    fclose(f);

    return 0;
}