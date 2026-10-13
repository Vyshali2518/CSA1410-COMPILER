
%{
#include <stdio.h>
%}

%%
(https?|ftp):\/\/[a-zA-Z0-9.-]+\.[a-zA-Z]{2,} {
    printf("URL Valid\n");
}

.+ {
    printf("URL Invalid\n");
}
%%

int main()
{
    printf("Enter URL: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
