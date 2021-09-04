#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "misc.h"

int printsn(char *str) {
    return printf("%s\n", str);
}

void prints(char *str) {
    printf("%s", str);
}

bool isObjectFile(char *filename) {
    assert(filename != NULL);

    char *extension = findFileExtension(filename);
    if (strcmp(extension, "o") == 0) {
        return true;
    }
    free(extension);
    return false;
}


char * findFileExtension(char *filename) {
    assert(filename != NULL);

    bool isnormalfile = false;
    char *ext = malloc(sizeof(char) * 6);
    assert(ext != NULL);
    if (filename[0] == '.') {
        strcpy(ext, "text");
        return ext;
    }

    size_t len = strlen(filename);
    size_t c = 0;
    for (size_t i = 0; i != len; i++) {
        if (isnormalfile) {
            ext[c++] = filename[i];
        }
        if (filename[i] == '.') {
            isnormalfile = true;
        }
    }
    ext[c] = '\0';
    if (!isnormalfile) {
        free(ext);
        return "o";
    }
    if (filename[len - 1] == 'o') {
        free(ext);
        return "o";
    }
    return ext;
}
