// Written as a reminder of the fact that you don't need to
// manually somehow convert something into hex or binary
// when you print it!

// When a function returns an integer, for example, it doesn't matter
// if it's returning it as a decimal, hex or binary value - it's all stored
// exactly the same as binary under the hood! The only differences happen
// when we print and with the format specifier we use, which changes
// nothing about the underlying data but just formats it in a specific 
// way.

#include <stdio.h>

int main(void) {
    int num = 343;

    // Note - there are never any modifications to how num is stored
    // under the hood!!
    printf("Decimal: %d\n", num);
    printf("Hex: 0x%x\n", num);
    printf("Octal: 0%o\n", num);

    return 0;
}