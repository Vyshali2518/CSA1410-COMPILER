%option noyywrap

%{
#include <stdio.h>
%}

%%

^[6-9][0-9]{9}$ {
    printf("\nMobile Number is VALID\n");
}

^[^\n]+$ {
    printf("\nMobile Number is INVALID\n");
}

\n ;

%%

int main()
{
    printf("Enter Mobile Number: ");
    yylex();
    return 0;
}