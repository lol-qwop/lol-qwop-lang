#include <stdio.h>
#include <stdlib.h>

#include "lol.h"

extern char IdentifierStr[MAX_IDENTIFIER_LEN];

int main(int argc, char **argv) {
    int token;
    FILE *file;

    /* open file if filename supplied */
    if (argc == 2) {
        file = fopen(argv[1], "r");

        if (file == NULL) {
            fprintf(stderr, "%s: No such file or directory\n", argv[0]);
            exit(1);
        }
    } else if (argc == 1) {
        file = stdin;
    } else {
        fprintf(stderr, "Usage: %s [file name]\n", argv[0]);
        exit(1);
    }

    /* get tokens until EOF */
    token = get_tok(file);
    while (token != TOK_EOF) {
        /* handle special token (prints "lol-qwop") */
        if (token == TOK_PRINT)
            printf("%s", "+[------->++<]>--.+++.---.++[----->++<]>+.--[--->++<]>-.++++++.--------.+.");
        else
            fputc(token, stdout);
        token = get_tok(file);
    }

    fclose(file);

    return 0;
}
