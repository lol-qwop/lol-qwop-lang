#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "lol.h"

char IdentifierStr[MAX_IDENTIFIER_LEN];

/* Returns 1 if the c can be part of a valid token */
inline int is_valid(char c) {
    return c == '.' || c == '!' || c == '?' || c == '-' || (c >= 'a' && c <= 'z');
}

/* Returns the next token */
int get_tok(FILE *file) {
    int last_char;
    int IdentifierStr_len;

    /* eat whitespace */
    do {
        last_char = fgetc(file);
    } while (isspace(last_char));

    if (is_valid(last_char)) {
        /* read token */
        IdentifierStr_len = 0;
        do {
            IdentifierStr[IdentifierStr_len] = last_char;
            IdentifierStr_len++;
        } while (is_valid(last_char = fgetc(file)));
        IdentifierStr[IdentifierStr_len] = '\0';

        /* get token type */
        if (strcmp(IdentifierStr, "lol") == 0)
            return TOK_MV_RIGHT;
        else if (strcmp(IdentifierStr, "lol.") == 0)
            return TOK_MV_LEFT;
        else if (strcmp(IdentifierStr, "lol!") == 0)
            return TOK_INCR;
        else if (strcmp(IdentifierStr, "lol?") == 0)
            return TOK_DECR;
        else if (strcmp(IdentifierStr, "qwop") == 0)
            return TOK_OUTPUT;
        else if (strcmp(IdentifierStr, "qwop.") == 0)
            return TOK_INPUT;
        else if (strcmp(IdentifierStr, "qwop!") == 0)
            return TOK_JUMP_OPEN;
        else if (strcmp(IdentifierStr, "qwop?") == 0)
            return TOK_JUMP_CLOSED;
        else if (strcmp(IdentifierStr, "lol-qwop") == 0)
            return TOK_PRINT;
        else if (strcmp(IdentifierStr, "lol-qwop!") == 0)
            return TOK_RM;
        /* comments are ignored */
        return TOK_COMMENT;
    }

    return TOK_EOF;
}
