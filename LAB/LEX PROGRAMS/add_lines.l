%option noyywrap

%{
#include <stdio.h>

int line_no = 0;
%}

%%

^(.*)\n {
    printf("%4d\t%s", ++line_no, yytext);
}

. {
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

    fclose(yyin);

    return 0;
}