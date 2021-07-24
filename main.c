#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <dirent.h>
#include <string.h>

#include "args.h"
#include "dir.h"
#include "bufio.h"


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

    printFilenames(filenames);
    openfiles(filenames);
    freeEntries(filenames);
    return 0;
}
