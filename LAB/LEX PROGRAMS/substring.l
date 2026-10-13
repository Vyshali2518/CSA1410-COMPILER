%option noyywrap

%{
#include <stdio.h>
%}

%%

^[^\n]* {
    int i;

    for(i = 0; yytext[i] != '\0'; i++)
    {
        if(yytext[i] == 'a' &&
           yytext[i+1] == 'b' &&
           yytext[i+2] == 'c')
        {
            yytext[i] = 'A';
            yytext[i+1] = 'B';
            yytext[i+2] = 'C';
        }
    }

    printf("Converted string: %s\n", yytext);
}

\n ;

%%

int main()
{
    printf("Enter a string: ");
    yylex();

    return 0;
}