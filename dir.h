#ifndef DIR_H
#define DIR_H

#include <dirent.h>
#include <stdbool.h>

typedef struct {
    char **f_names;
    size_t count;
} filenames_t;

typedef struct {
    char **direntries;
    size_t count;
} dirlistnames_t;

typedef struct {
    int total;
    int files;
    int dir;
} dirlistcount_t;

dirlistnames_t * getDirEntries(char *dirname);
filenames_t * getFilenames(char *dirname);
dirlistcount_t * countOfListing(char *dirname);
bool isdir(struct dirent *);
bool isSymbolicDirStructure(char *name);

#endif
