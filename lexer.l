%{
    #include<stdio.h>
%}

%%
[0-9]+ {printf("Token: num Lexeme: %s\n", yytext);}
[A-Za-z][A-Za-z0-9_]* {printf("Token: id Lexeme: %s\n", yytext);}
.   {}
%%

int main(){
    yylex();
    return 0;
}