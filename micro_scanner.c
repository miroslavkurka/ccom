#include<stdio.h>
#include<ctype.h>


typedef enum token_types {
BEGIN, END, READ, WRITE, ID, INTLITERAL,
LPAREN, RPAREN, SEMICOLON, COMMA, ASSIGNOP,
PLUSOP, MINUSOP, SCANEOF
} token;

extern token scanner(void);


int in_char, c;

while ((in_char= getchar())!=EOF){

    if (isspace(in_char))
        continue;
    else if (isdigit(in_char)) {
        while (isdigit ((c = getchar())));
        ungetc(c, stdin);
        return INTLITERAL;
    } else if (isalpha(in_char)){
        for (c = getchar(); isalnum(c) || c == ' _'; c= getchar());
        ungetc(c,stdin);
    }
      else
        lexical_error(in_char);
}
