%option noyywrap

%{
#include <stdio.h>
%}

%%

^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$ {
    printf("\nEmail is VALID\n");
}

^[^\n]+$ {
    printf("\nEmail is INVALID\n");
}

\n ;

%%

int main()
{
    printf("Enter Email: ");
    yylex();
    return 0;
}