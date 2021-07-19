#ifndef ARGS_H // Start of ARGS_H
#define ARGS_H

#include "dir.h"

#define OPTIONS "f:rv."
#define EOI EOF

void usage(char *);
filenames_t * addFilename(filenames_t *, char *);

#endif // end of ARGS_H
