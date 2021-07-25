#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <dirent.h>
#include <string.h>

#include "args.h"
#include "dir.h"
#include "bufio.h"
#include "misc.h"


#define _POSIX_OPTION_ORDER
#define CUR_DIR "./"

extern char *optarg;
extern int optopt;
extern int opterr;


int main(int argc, char **argv) {

    if (argc < 3) {
        usage(basename(argv[0]));
        return EXIT_FAILURE;
    }

    char *pattern = (char *) malloc(strlen(argv[1]) + 1);
    strcpy(pattern, argv[1]);

    filenames_t *filenames = NULL;

    int opt;
    while ((opt = getopt(argc, argv, OPTIONS)) != EOI) {
        switch (opt) {
            case 'f':
                filenames = addFilename(filenames, optarg);
                break;

            case '.':
                if (filenames == NULL) {
                    filenames = getFilenames(CUR_DIR);
                }
                else if (filenames->count > 0) {
                    filenames = addFilenames(filenames, CUR_DIR);
                }
                break;
        }
    }

    openfiles(filenames, pattern);
    free(pattern);
    freeEntries(filenames);
    return 0;
}
