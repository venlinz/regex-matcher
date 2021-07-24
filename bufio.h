#ifndef BUFIO_H
#define BUFIO_H

#include <stdio.h>

#include "dir.h"

char * readfile(filenames_t *);
char * readline(char *, FILE *);
int openfiles(filenames_t *);

#endif