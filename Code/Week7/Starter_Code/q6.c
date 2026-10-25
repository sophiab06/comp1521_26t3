#include <stdio.h>

int main(void) {
    // Consider the following:
    unsigned char c;
    scanf("%c", &c);
    printf("%c", c);

    // It reads in one byte (since char is one byte in size),
    // without trimming out whitespace like spaces/new lines 
    // (note the lack of space before the %c in scanf) and 
    // prints it immediately.

    // TO DO: rewrite the above using fread() and fwrite()!

    return 0;
}