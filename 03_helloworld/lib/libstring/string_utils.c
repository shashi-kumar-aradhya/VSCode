#include "string_utils.h"
#include <string.h>

char* reverse_string(const char* str) {
    static char reversed[100];
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0';  // Null-terminate the string
    return reversed;
}

