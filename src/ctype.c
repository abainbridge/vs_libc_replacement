#ifndef _DEBUG

#include <ctype.h>

#define LOWER_CASE_MASK ('a' - 'A')

int isdigit(int c) {
    return c >= '0' && c <= '9';
}


int isalpha(int c) {
    c |= LOWER_CASE_MASK;
    return c >= 'a' && c <= 'z';
}

int isalnum(int c) {
    return isdigit(c) || isalpha(c);
}

int isalnum(int c) {
    return isalpha(c) | isdigit(c);
}


int isupper(int c) {
    return !(c & LOWER_CASE_MASK);
}


int tolower(int c) {
    return c | LOWER_CASE_MASK;
}


int isspace(int c) {
    return c == ' ' || c == '\t';
}

#endif
