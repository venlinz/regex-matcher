#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <dirent.h>

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
                printf("to be done");
                break;

            case '.':
                filenames = getFilenames(CUR_DIR);
        }
    }

    if (filenames) {
        printf("listing from main: \n");
        for (int i = 0; i < filenames->count; i++) {
            printf("%d. %s\n", i, filenames->f_names[i]);
        }
    }
    return 0;
}
