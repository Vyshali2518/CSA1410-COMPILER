%option noyywrap

%%

[A-Z]+[\t\n ] {
    printf("%s is a capital word\n", yytext);
}

. ;

%%

int main()
{
    printf("Enter String :\n");
    yylex();

    return 0;
}