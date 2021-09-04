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

dirlistnames_t * getDirEntries(char *);
filenames_t * getFilenames(char *);
dirlistcount_t * countOfListing(char *);
filenames_t * addFilenames(filenames_t *, char *);
bool isdir(struct dirent *);
bool isSymbolicDirStructure(char *name);
void printFilenames(const filenames_t *filenames);

bool freeEntries(filenames_t *);


#endif
