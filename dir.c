#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "dir.h"


filenames_t * getFilenames(char *dirname) {
    if (dirname == NULL) {
        perror("Invalid directory name");
        return NULL;
    }


    filenames_t *filenames = malloc(sizeof(filenames_t));
    if (filenames == NULL) {
        perror("Error on filenames_t struct allocation");
        return NULL;
    }

    dirlistcount_t *listingCount = countOfListing(dirname);
    if (listingCount == NULL) {
        return NULL;
    }
    size_t count = listingCount->files;
    free(listingCount);

    filenames->count = count;
    filenames->f_names = (char **) malloc(count * sizeof(char **));
    if (filenames->f_names == NULL) {
        perror("Error on filenames_t f_names struct allocation");
        return NULL;
    }

    DIR *dirstream = opendir(dirname);
    if (dirstream == NULL) {
        perror("Invalid directorystream pointer to stream");
        return NULL;
    }

    struct dirent *entry;
    for (size_t i = 0; (entry = readdir(dirstream)) && i < count; i++) {
        if (entry == NULL) {
            perror("Error on entry allocation");
            return NULL;
        }

        if(!isdir(entry)) {
            filenames->f_names[i] = (char *) malloc(strlen(entry->d_name));
            if (filenames->f_names[i] == NULL) {
                perror("Error on f_names allocation");
                return NULL;
            }
            strcpy(filenames->f_names[i], entry->d_name);
            //printf("f_names[%lu]: %s\n",i , filenames->f_names[i]);
        }
        else {
            i--;
        }
    } 
    closedir(dirstream);
    free(entry);

    return filenames;
}


dirlistcount_t * countOfListing(char *dirname) {

    DIR *dirstream = opendir(dirname);
    if (dirstream == NULL) {
        perror("Invalid directorystream pointer to stream");
        return 0;
    }

    size_t count = 0;
    size_t dircount = 0;
    struct dirent *entry = NULL;

    while ((entry = readdir(dirstream))) {
        if (entry == NULL) {
            perror("Error on dirent struct allocation");
            return 0;
        }
        char *name = entry->d_name;

        count++;
        if (isdir(entry)) {
            dircount++; 
            if (isSymbolicDirStructure(name)) {
                count--;
            }
        }
    }
    closedir(dirstream);
    dircount -= 2; // subracting . and .. entries.

    dirlistcount_t *cntOfList = malloc(sizeof(cntOfList));
    if (cntOfList == NULL) {
        perror("Error on dirlistcount_t allocation");
        return NULL;
    }
    cntOfList->total = count;
    cntOfList->files = count - dircount;
    cntOfList->dir = dircount;

    return cntOfList;
}


bool isdir(struct dirent *entry) {
    if (entry->d_type == DT_DIR) {
        return true;
    }
    return false;
}


/* returns true if dir is . or .. */
bool isSymbolicDirStructure(char *name) {  
    if (name[0] == '.') {
        if (name[1] == '\0') {
            return true;
        }
        else if (name[1] == '.' && name[2] == '\0') {
            return true;
        }
    }
    return false;
}
