#include <stdio.h>
#include <stdbool.h>

#include "aorb.h"

bool match(char *text, char *regex) {
    if (*regex == '\0')
        return true;

    if (*text == '\0')
        return false;

    if (*text == *regex)
        return match(text + 1, regex + 1);
    
    
    return match(text + 1);
}
