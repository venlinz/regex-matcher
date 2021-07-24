#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include "bufio.h"
#include "dir.h"
#include "misc.h"
#include "regex.h"

#define LINE_LEN 50


int openfiles(filenames_t *filenames, char *pattern) {
    int flag = 0;
    if (filenames == NULL) {
        perror("Error filenames_t is null in bufio.c");
        return flag = -1;
    }


    char *buffer = NULL;
    FILE *fp = NULL;
    size_t count = filenames -> count;
    for (size_t i = 0; i < count; ++i) {
        bool hasMatch = false;
        if (!isObjectFile(filenames->f_names[i])) {
            fp = fopen (filenames->f_names[i], "r");
            if (fp == NULL) {
                return flag = -1;
            }
            /* while (fgets(buffer, 128, fp) != NULL) { */
            while ((buffer = readline(fp)) != NULL) {
                if (match(buffer, pattern)) {
                    if (!hasMatch) {
                        hasMatch = true;
                        prints(filenames->f_names[i]);
                        prints(":");
                    }
                    prints(buffer);
                }
                free(buffer);
            }
            fclose(fp);
        }
    }
    free(buffer);
    return flag;
}


char * readline(FILE *fp) {
    if (fp == NULL) {
        perror("Error on FILE * in bufio.c");
        return NULL;
    }


    size_t curBufLen = LINE_LEN;
    char *buffer = (char *) malloc(sizeof(char) * LINE_LEN);
    if (buffer == NULL) {
        perror("Error on char * buffer allocation");
        return NULL;
    }

    size_t i;
    int c;
    for (i = 0; ((c = getc(fp)) != EOF) && c != '\n'; ++i) {
        buffer[i] = c;
        if (i == curBufLen - 2) {
            curBufLen = i * 2;
            char *temp = (char *) realloc(buffer, sizeof(char) * curBufLen);
            if (temp == NULL) {
                perror("Error on char * buffer reallocation");
                return NULL;
            }
            buffer = temp;
        }
    }

    if (c == '\n') {
        buffer[i++] = c;
        buffer[i] = '\0';
    }
    else if (c == EOF) {
        buffer[i++] = '\n';
        buffer[i] = '\0';
        free(buffer);
        return NULL;
    }

    return buffer;
}
