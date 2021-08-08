#ifndef REGEX_H
#define REGEX_H

#include <stdbool.h>


bool match(char *, char *);
bool matchhere(char *text, char *regex);
bool matchsetrange(char *text, char *regex);
size_t findIdxOfNxtSymbol(char *regex);
bool matchanychar(char *text, char *regex);

#endif
