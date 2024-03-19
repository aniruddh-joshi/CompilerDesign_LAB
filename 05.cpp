%{
#include<stdio.h>
int lc=0,sc=0,tc=0,ch=0,wc=0;	 
%}

%%
int|float|char|double { printf("KEYWORD: %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9]* { printf("IDENTIFIER: %s\n", yytext); }
[\n] { lc++; ch+=yyleng;}
[ \t] { sc++; ch+=yyleng;}
[^\t] { tc++; ch+=yyleng;}
[^\t\n ]+ { wc++; ch+=yyleng;} 
%%

int yywrap(){ return 1; }

int main(){
	printf("Enter the Sentence : ");
	yylex();
	printf("Number of lines : %d\n",lc);
	printf("Number of spaces : %d\n",sc);
	printf("Number of tabs, words, charc : %d , %d , %d\n",tc,wc,ch);
	
	return 0;
}


//OUTPUT
PS D:\C> flex as.l
PS D:\C> gcc lex.yy.c
PS D:\C> .\a.exe
Enter the Sentence : aniruddh int joshi float
IDENTIFIER: aniruddh
KEYWORD: int
IDENTIFIER: joshi
KEYWORD: float
^Z
Number of lines : 1
Number of spaces : 3
Number of tabs, words, charc : 0 , 0 , 4
PS D:\C>
