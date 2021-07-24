#include <stdio.h>
#include <stdbool.h>

#include "aorb.h"

bool match(char *text) {
    if (*text == '\0')
        return false;

    if (*text == 'a')
        return true;
    
    if (*text == 'b')
        return true;
    
    return match(text + 1);
}
