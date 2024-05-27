#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
/*
Write a lex function that accepts a file and returns a list of tokens. 
It should work for all stage 1 examples in the test suite, including the invalid ones. 
(The invalid examples should raise errors in the parser, not the lexer.) 
To keep things simple, we only lex decimal integers. 
If you like, you can extend your lexer to handle octal and hex integers too.
*/

// For now this function will print out all the lex it sees
static void lexing(FILE *file){
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
}

int main(int argc, char *argv[]) {
    // Tell user how to use the compiler
    if (argc < 2) { 
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file;
    if ((file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }
    lexing(file);

    fclose(file);
    return 0;
}
