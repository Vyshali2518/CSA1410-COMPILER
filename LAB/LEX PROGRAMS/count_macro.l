%option noyywrap

%{
#include <stdio.h>

int nmacro = 0;
int nheader = 0;
%}

%%

^#define {
    nmacro++;
}

^#include {
    nheader++;
}

.|\n {
}

%%

int main()
{
    char filename[100];

    printf("Enter C source file name: ");
    scanf("%99s", filename);

    yyin = fopen(filename, "r");

    if (yyin == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    yylex();

    printf("\nNumber of macros defined = %d\n", nmacro);
    printf("Number of header files included = %d\n", nheader);

    fclose(yyin);

    return 0;
}