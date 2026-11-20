#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Operator-precedence style expression checker.
   Grammar: E -> E+T | E-T | T; T -> T*F | T/F | F; F -> (E) | id */
char s[200]; int p = 0;
int E(void), T(void), F(void);
int E(void) { if (!T()) return 0; while (s[p]=='+' || s[p]=='-') { p++; if(!T()) return 0; } return 1; }
int T(void) { if (!F()) return 0; while (s[p]=='*' || s[p]=='/') { p++; if(!F()) return 0; } return 1; }
int F(void) {
    if (s[p]=='(') { p++; if(!E() || s[p]!=')') return 0; p++; return 1; }
    if (isalpha((unsigned char)s[p])) { while (isalnum((unsigned char)s[p])) p++; return 1; }
    return 0;
}
int main(void) {
    printf("Enter expression: ");
    if (scanf("%199s", s) != 1) return 1;
    puts(E() && s[p]=='\0' ? "Expression accepted." : "Expression not accepted.");
    return 0;
}
