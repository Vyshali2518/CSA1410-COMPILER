%{
int nchar = 0, nword = 0, nline = 0;
%}

%%

\n              { nline++; nchar++; }

[^ \t\n]+        { nword++; nchar += yyleng; }

.                { nchar++; }

%%

int yywrap(void)
{
    return 1;
}

int main()
{
    char filename[100];

    printf("Enter C file name: ");
    scanf("%s", filename);

    yyin = fopen(filename, "r");

    if (yyin == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    yylex();

    printf("\nNumber of characters = %d\n", nchar);
    printf("Number of words = %d\n", nword);
    printf("Number of lines = %d\n", nline);

    fclose(yyin);

    return 0;
}