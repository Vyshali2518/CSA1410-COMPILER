%option noyywrap

%{
#include <stdio.h>

int com = 0;
%}

%s COMMENT

%%

"/*"              { BEGIN COMMENT; }

<COMMENT>"*/"     { BEGIN 0; com++; }

<COMMENT>\n       { com++; }

<COMMENT>.        { }

"//".*            { com++; }

.|\n              { fprintf(yyout, "%s", yytext); }

%%

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: a.exe input.c output.c\n");
        return 0;
    }

    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");

    yylex();

    printf("\nNumber of comments are = %d\n", com);

    fclose(yyin);
    fclose(yyout);

    return 0;
}