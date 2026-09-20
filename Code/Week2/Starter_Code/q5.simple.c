// C code to turn into simple C, as part of the process of translation into MIPS!

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    int x, y;

    // TO DO - turn into simple C with gotos instead of regular if statements!

    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > SQUARE_MAX) {
        printf("square too big for 32 bits\n");
    } else {
        y = x * x;
        printf("%d\n", y);
    }

    return 0;
}