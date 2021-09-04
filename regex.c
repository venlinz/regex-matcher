#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

    if (regex[1] == '*')
        return matchstar(text, regex + 2, *regex);

    if (regex[1] == '+')
        return matchplus(text, regex + 2, *regex);

    if (*regex == '[') {
        int nextSymbolIdx = findIdxOfNxtSymbol(regex);
        if (*(regex + 2) == '-' && matchsetrange(text, regex))
            return matchhere(text + 1, regex + 5);
        else if (matchanychar(text, regex)) {
            return matchhere(text + 1, regex + nextSymbolIdx);
        }
    }

    if (*text != '\0' && (*text == *regex 
                || *regex == '.'))
        return matchhere(text + 1, regex + 1);

    return false;    
}


bool matchstar(char *text, char *regex, char c) {

    do {
        if (matchhere(text, regex))
            return true;
    } while (*text != '\0' && (*text++ == c || c == '.'));
    return false;
}


bool matchplus(char *text, char *regex, char c) {
    while (*text != '\0' && (*text++ == c)) {
        if (matchhere(text, regex))
            return true;
    }

    return false;
}

bool matchanychar(char *text, char *regex) {

    size_t strtIdxOfNxtSymbol = findIdxOfNxtSymbol(regex);
    if (!strtIdxOfNxtSymbol) {
        fprintf(stderr, "Invalid set match expression %s\n", regex);
        return false;
    }

    for (size_t i = 0; i < strtIdxOfNxtSymbol; ++i) {
        if (*(regex + i) == *text)
            return true;
    }
    return false; 
}


bool matchsetrange(char *text, char *regex) {

    int start, end;
    start = end = 0;
    start = (int) *(regex + 1);
    end = (int) *(regex + 3);
    if (end == ']') {
        fprintf(stderr, "Error set match expression %s\n", regex);
        return false;
    }
    int ti = (int) (*text);
    if (ti >= start && ti <= end) {
        return true;
    }
    return false;
}


size_t findIdxOfNxtSymbol(char *regex) {

    size_t i;
    for (i = 0; ; i++) {
        if (regex[i] == '\0')
            return 0;
        if (regex[i] == ']')
            break;
    }
    return i + 1;
}
