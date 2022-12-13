//
// Created by Pierre Forques on 11/12/2022.
//

#include <printf.h>
#include <stdlib.h>
#include "includes/onichan.h"

void run_run_bby(const char* src){
    lexer_st *lexer = init_lexer(src);
    token_st *token = NULL;

    while((token = lexer_assign_loop(lexer))->type != TOKEN_EOF){
        printf("%s %d\n", token->value, token->type);
        free(token);
    }
}