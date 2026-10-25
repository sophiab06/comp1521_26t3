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

    // Since terminals are just treated as custom files,
    // we can use standard file functions with the special
    // stdin (to get input) and stdout (to print non-error
    // output) file streams and it works!
    // Example as below.

    // Reads one element one byte in size from stdin, storing
    // in c
    fread(&c, 1, 1, stdin);

    // Writes one element one byte in size from c to stdout
    fwrite(&c, 1, 1, stdout);

    return 0;
}