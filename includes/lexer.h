//
// Created by Pierre Forques on 11/12/2022.
//

#ifndef PF_LEXER_LEXER_H
#define PF_LEXER_LEXER_H

#include <string.h>
#include "token.h"

typedef struct lexer_s{
    char* src;  //string that contains code
    char c;     //current character
    int i;      //index of the current character
    //maybe add size of source
} lexer_st;

lexer_st* init_lexer(const char* src);
void lexer_skip_space(lexer_st *lexer);
void lexer_advance_plus_one(lexer_st *lexer);
char* lexer_parse_id(lexer_st *lexer);
token_st* lexer_assign_token(lexer_st* lexer, int token_type);
token_st* lexer_assign_loop(lexer_st* lexer);
int lexer_count_id(lexer_st* lexer);

#endif //PF_LEXER_LEXER_H
