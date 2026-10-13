
%{
#include <stdio.h>
%}

%%
[0-9]+  { printf("Valid digit\n"); }
.*      { printf("Invalid digit\n"); }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a digit: ");
    yylex();
    return 0;
}
