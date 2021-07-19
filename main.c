#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <dirent.h>
#include <string.h>

#include "args.h"
#include "dir.h"


#define _POSIX_OPTION_ORDER
#define CUR_DIR "./"

extern char *optarg;
extern int optopt;
extern int opterr;


int main(int argc, char **argv) {

    if (argc < 2) {
        usage(basename(argv[0]));
        return EXIT_FAILURE;
    }

    filenames_t *filenames = NULL;

    int opt;
    while ((opt = getopt(argc, argv, OPTIONS)) != EOI) {
        switch (opt) {
            case 'f':
                filenames = addFilename(filenames, optarg);
                /* if (filenames == NULL) { */
                /*     filenames = (filenames_t *) malloc(sizeof(filenames_t)); */
                /*     if (filenames == NULL) { */
                /*         perror("Error on filenames_t allocation in -f in main"); */
                /*         return EXIT_FAILURE; */
                /*     } */

                /*     size_t count; */
                /*     filenames->count = count = 1; */
                /*     filenames->f_names = (char **) malloc(sizeof (char *) * count); */
                /*     if (filenames->f_names == NULL) { */
                /*         perror("Error on filenames_t f_names allocation"); */
                /*         return EXIT_FAILURE; */
                /*     } */

                /*     filenames->f_names[count - 1] = (char *) malloc(strlen(optarg) + 1); */
                /*     if (filenames->f_names[count - 1] == NULL) { */
                /*         perror("Error on filenames_t f_names[] allocation"); */
                /*         return EXIT_FAILURE; */
                /*     } */
                /*     strcpy(filenames->f_names[count - 1], optarg); */
                /* } */
                /* else { */
                /*     filenames->count++; */
                /*     size_t count = filenames->count; */
                /*     /1* char *f_names0 = filenames->f_names[0]; *1/ */

                /*     char **temp = realloc(filenames->f_names, count * sizeof(char *)); */
                /*     if (temp == NULL) { */
                /*         perror("Error on filenames_t f_names reallocation in main"); */
                /*         return EXIT_FAILURE; */
                /*     } */

                /*     filenames->f_names = temp; */
                /*     temp = NULL; */
                /*     filenames->f_names[count - 1] = (char *) malloc(strlen(filenames->f_names[0]) + 1); */
                /*     if (filenames->f_names[count - 1] == NULL) { */
                /*         perror("Error on new filenames_t f_names[] allocation in main"); */
                /*         return EXIT_FAILURE; */
                /*     } */
                /*     strcpy(filenames->f_names[count - 1], filenames->f_names[0]); */

                /*     filenames->f_names[0] = realloc(filenames->f_names[0], strlen(optarg) + 1); */
                /*     if (filenames->f_names[0] == NULL) { */
                /*         perror("Error on filenames_t f_names[] reallocation in main"); */
                /*         return EXIT_FAILURE; */
                /*     } */
                /*     strcpy(filenames->f_names[0], optarg); */
                /* } */
                break;

            case '.':
                if (filenames == NULL) {
                    filenames = getFilenames(CUR_DIR);
                }
                else if (filenames->count > 0) {
                    filenames = addFilenames(filenames, CUR_DIR);
                }
        }
    }

    printFilenames(filenames);

    freeEntries(filenames);
    return 0;
}
