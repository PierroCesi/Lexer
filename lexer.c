//
// Created by Pierre Forques on 12/12/2022.
//

#include <stdlib.h>
#include <printf.h>
#include "includes/lexer.h"
#include "includes/token.h"

lexer_st* init_lexer(const char* src){
    lexer_st *lexer = malloc(sizeof(lexer_st));

    lexer->src = src;
    lexer->i = 0;
    lexer->c = src[lexer->i];

    return lexer;
}

void lexer_skip_space(lexer_st *lexer){
    while(lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n'){
        lexer_advance_plus_one(lexer);
    }
}

void lexer_advance_plus_one(lexer_st *lexer){
    //ptetre une erreur si je dépasse la taille de la source
    lexer->i = lexer->i + 1;
    lexer->c = lexer->src[lexer->i];
}

char* lexer_parse_id(lexer_st *lexer){
    int id_length = lexer_count_id(lexer);
    char* id = NULL;
    id = malloc(id_length*sizeof(char)+1);

    for(int y=0; y<id_length; ++y){
        id[y] = lexer->c;
        lexer_advance_plus_one(lexer);
    }

    id[id_length+1] = '\0';
    return id;
}

token_st* lexer_assign_token_id(char* str, int token_type){
    token_st *token = init_token(str, token_type);
    return token;
}

token_st* lexer_assign_token(lexer_st* lexer, int token_type){
    char* token_value = malloc(2*sizeof(char));
    token_value[0] = lexer->c;
    token_value[1] = '\0';

    token_st *token = init_token(token_value, token_type);

    return token;
}

token_st* lexer_assign_loop(lexer_st* lexer){
    token_st *token;
    while(lexer->c != '\0'){
        lexer_skip_space(lexer);

        if(isalpha(lexer->c)) {
            return lexer_assign_token_id(lexer_parse_id(lexer), TOKEN_ID);
        }

        switch (lexer->c) {
            case '+':
                token = lexer_assign_token(lexer, TOKEN_PLUS); break;
            case '=':
                token = lexer_assign_token(lexer, TOKEN_EQUAL); break;
            case '(':
                token = lexer_assign_token(lexer, TOKEN_LPAREN); break;
            case ')':
                token = lexer_assign_token(lexer, TOKEN_RPAREN); break;
            default:
                printf("[LEXER] Undefined character %c. Ascii code is %d", lexer->c, lexer->c);
                exit(1);
        }
        lexer_advance_plus_one(lexer);
        return token;
    }
    return lexer_assign_token(lexer, TOKEN_EOF);
}

int lexer_count_id(lexer_st* lexer){
    int i = 0;

    while(isalpha(lexer->src[lexer->i+i])){
        i++;
    }
    return i;
}