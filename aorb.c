#include <stdio.h>
#include <stdbool.h>

#include "aorb.h"

bool match(char *text, char *regex) {
    do {
        if (matchhere(text, regex)) 
            return true;
    } while (*text++ != '\0');
    return false;
}

bool matchhere(char *text, char *regex) {
    if (*regex == '\0')
        return true;

    if (*text != '\0' && *text == *regex)
        return matchhere(text + 1, regex + 1);

    return false;    
}
