#ifndef BUFIO_H
#define BUFIO_H

#include <stdio.h>

#include "dir.h"

char * readfile(filenames_t *);
char * readline(FILE *);
int openfiles(filenames_t *, char *);

#endif
