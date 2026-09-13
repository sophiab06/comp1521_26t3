#include <stdio.h>

int main(void) {
    char str[10];
    str[0] = 'H';
    str[1] = 'i';

    // Null terminator is necessary so the end of the string
    // is properly signified!
    str[2] = '\0'

    printf("%s", str);
    return 0;
}