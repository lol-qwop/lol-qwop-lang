#include <stdio.h>

#ifndef LOL_H_INCLUDED
#define LOL_H_INCLUDED

#define MAX_IDENTIFIER_LEN 10

enum Token {
    TOK_EOF = -1,
    TOK_COMMENT = -2,

    TOK_MV_RIGHT = '>',
    TOK_MV_LEFT = '<',
    TOK_INCR = '+',
    TOK_DECR = '-',
    TOK_OUTPUT = '.',
    TOK_INPUT = ',',
    TOK_JUMP_OPEN = '[',
    TOK_JUMP_CLOSED = ']',
    TOK_PRINT = 1,
    TOK_RM = 2
};

int get_tok(FILE *file);

#endif
