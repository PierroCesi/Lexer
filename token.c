//
// Created by Pierre Forques on 11/12/2022.
//

#include <stdlib.h>
#include "includes/token.h"

token_st* init_token(char* token_value, int token_type){
    token_st *token = malloc(sizeof(token_st));

    token->type = token_type;
    token->value = token_value;

    return token;
}