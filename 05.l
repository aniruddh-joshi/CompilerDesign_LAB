%{
#include <stdio.h>
%}

%%

int|float|char|double|short|long|unsigned|signed|void|auto|const|extern|static|register|volatile { printf("KEYWORD: %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9]* { printf("IDENTIFIER: %s\n", yytext); }
[ \t]+               { printf("WHITESPACE: \"%s\"\n", yytext); } 
\n                   { printf("NEWLINE\n"); }
.                    { printf("CHARACTER: %c\n", yytext[0]); }

%%
int yywrap() {
    return 1;
}
int main() {
    yylex();
    return 0;
}

//OUTPUT
^Z
PS D:\C> flex as.l
PS D:\C> gcc lex.yy.c
PS D:\C> .\a.exe
aniruddh joshi int float if;
IDENTIFIER: aniruddh
WHITESPACE: " "
IDENTIFIER: joshi
WHITESPACE: " "
KEYWORD: int
WHITESPACE: " "
KEYWORD: float
WHITESPACE: " "
IDENTIFIER: if
CHARACTER: ;
NEWLINE
=
CHARACTER: =
NEWLINE
^Z
