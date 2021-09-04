#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "args.h"
#include "dir.h"

void usage(char *argv0) {
    printf("Usage: %s PATTERN [OPTIONS] ...\n", argv0);
    printf("Try '%s -h' for more information\n", argv0);
}


filenames_t * addFilename(filenames_t *filenames, char *filename) {

    if (filenames == NULL) {
        filenames = (filenames_t *) malloc(sizeof(filenames_t));
        if (filenames == NULL) {
            perror("Error on filenames_t allocation in -f in main");
            return NULL;
        }

        size_t count;
        filenames->count = count = 1;
        filenames->f_names = (char **) malloc(sizeof (char *) * count);
        if (filenames->f_names == NULL) {
            perror("Error on filenames_t f_names allocation");
            return NULL;
        }

        filenames->f_names[count - 1] = (char *) malloc(strlen(filename) + 1);
        if (filenames->f_names[count - 1] == NULL) {
            perror("Error on filenames_t f_names[] allocation");
            return NULL;
        }
        strcpy(filenames->f_names[count - 1], filename);
    }
    else {
        filenames->count++;
        size_t count = filenames->count;
        /* char *f_names0 = filenames->f_names[0]; */

        char **temp = realloc(filenames->f_names, count * sizeof(char *));
        if (temp == NULL) {
            perror("Error on filenames_t f_names reallocation in main");
            return NULL;
        }

        filenames->f_names = temp;
        temp = NULL;
        filenames->f_names[count - 1] = (char *) malloc(strlen(filenames->f_names[0]) + 1);
        if (filenames->f_names[count - 1] == NULL) {
            perror("Error on new filenames_t f_names[] allocation in main");
            return NULL;
        }
        strcpy(filenames->f_names[count - 1], filenames->f_names[0]);

        filenames->f_names[0] = realloc(filenames->f_names[0], strlen(filename) + 1);
        if (filenames->f_names[0] == NULL) {
            perror("Error on filenames_t f_names[] reallocation in main");
            return NULL;
        }
        strcpy(filenames->f_names[0], filename);

    }

    return filenames;
}
// ab
//hi  vab
