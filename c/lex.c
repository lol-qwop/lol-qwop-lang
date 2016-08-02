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
		if (strncmp(IdentifierStr, "lol", 3) == 0) {  //string starting with "lol"
			if (IdentifierStr_len == 3)
				return TOK_MV_RIGHT;
			
			if (IdentifierStr_len == 4)
				switch (IdentifierStr[3]) {
					case '.': return TOK_MV_LEFT;
					case '!': return TOK_INCR;
					case '?': return TOK_DECR;
					default:  return TOK_COMMENT;
				}
				
			if (strncmp(IdentifierStr, "lol-qwop", 8) == 0) {
				if (IdentifierStr_len == 8)
					return TOK_PRINT;
				if (IdentifierStr_len == 9 && IdentifierStr[8] == '!')
					return TOK_RM;
			}
				
			return TOK_COMMENT;
		}
		
		if (strncmp(IdentifierStr, "qwop", 4) == 0) {  //string starting with "qwop"
			if (IdentifierStr_len == 4)
				return TOK_OUTPUT;
			if (IdentifierStr_len == 5)
				switch (IdentifierStr[4]) {
					case '.': return TOK_INPUT;
					case '!': return TOK_JUMP_OPEN;
					case '?': return TOK_DECR;
					default:  return TOK_JUMP_CLOSED;
				}
			return TOK_COMMENT;
		}
    }
    return TOK_EOF;
}
