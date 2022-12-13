//
// Created by Pierre Forques on 11/12/2022.
//

#ifndef PF_LEXER_TOKEN_H
#define PF_LEXER_TOKEN_H

typedef struct token_s{
    char* value;
    enum {
        TOKEN_EOF,
        TOKEN_ID,
        TOKEN_PLUS,
        TOKEN_EQUAL,
        TOKEN_LPAREN,
        TOKEN_RPAREN
    } type;
} token_st;

token_st* init_token(char* token_value, int token_type);

#endif //PF_LEXER_TOKEN_H
