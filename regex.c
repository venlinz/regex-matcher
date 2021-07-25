#include <stdio.h>
#include <stdbool.h>

#include "regex.h"

bool match(char *text, char *regex) {
    if (*regex == '^')
        return matchhere(text, regex + 1);

    do {
        if (matchhere(text, regex)) 
            return true;
    } while (*text++ != '\0');
    return false;
}

bool matchhere(char *text, char *regex) {
    if (*regex == '\0')
        return true;

    int start, end;
    start = end = 0;
    if (*regex == '[') {
        start = (int) *(regex + 1);
        end = (int) *(regex + 3);
        for (int i = start; i <= end; i++) {
            if (*text == (char) i) 
                return matchhere(text + 1, regex + 5);
        }
    }

    if (*text != '\0' && (*text == *regex 
                || *regex == '.'))
        return matchhere(text + 1, regex + 1);

    return false;    
}
