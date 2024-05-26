#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Tell user how to use the compiler
    if (argc < 2) { 
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (!file) {
        perror("Could not open file");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}
