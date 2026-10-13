%option noyywrap

%{
#include <stdio.h>

int count_id = 0;
int count_key = 0;
%}

%%

"#include<stdio.h>" {
    printf("%s is a standard library\n", yytext);
}

"int"|"float"|"char"|"void"|"main"|"printf"|"scanf" {
    printf("%s is a keyword\n", yytext);
    count_key++;
}

[A-Za-z_][A-Za-z0-9_]* {
    printf("%s is an identifier\n", yytext);
    count_id++;
}

[0-9]+ {
    printf("%s is a number\n", yytext);
}

\"[^"]*\" {
    printf("%s is a string literal\n", yytext);
}

[ \t\n]+ {
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

    printf("\nNumber of identifiers = %d\n", count_id);
    printf("Number of keywords = %d\n", count_key);

    fclose(yyin);

    return 0;
}