
%{
#include <stdio.h>
#include <stdlib.h>

int f1 = 0, f2 = 0;
char oper;
float op1 = 0, op2 = 0, ans = 0;

void eval();
%}

DIGIT [0-9]
NUM {DIGIT}+(\.{DIGIT}+)?
OP [*/+-]

%%

{NUM} {
    if (f1 == 0) {
        op1 = atof(yytext);
        f1 = 1;
    }
    else if (f2 == -1) {
        op2 = atof(yytext);
        f2 = 1;
        eval();
        f1 = 0;
        f2 = 0;
    }
}

{OP} {
    oper = *yytext;
    f2 = -1;
}

[ \t]+ ;

\n ;

. ;

%%

int main()
{
    printf("Enter an expression (e.g., 10+5):\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}

void eval()
{
    switch (oper) {
        case '+': ans = op1 + op2; break;
        case '-': ans = op1 - op2; break;
        case '*': ans = op1 * op2; break;

        case '/':
            if (op2 == 0) {
                printf("Error: Division by zero\n");
                return;
            }
            ans = op1 / op2;
            break;

        default:
            printf("Operation not available\n");
            return;
    }

    printf("The answer is = %g\n", ans);
}
