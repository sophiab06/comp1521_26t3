// Demonstrates how floating point numbers can eventually be inaccurate due to 
// issues stemming from rounding!!

#include <stdio.h>

int main(void) {
    float i = 16777210;
    char input;

    printf("Type in any non-whitespace char to try to add 1 to the float!\n");
    printf("This will stop incrementing at 16777216.0, aka 1.000000000000000000000000 x 2^(24).\n");
    printf("Trying to add 1 brings it to 1.000000000000000000000001 x 2^(24), but that's 24 bits - too long to store accurately in the 23 bit fraction!\n");
    printf("Type in q to quit.\n");

    while (scanf(" %c", &input) > 0 && input != 'q') {
        printf("%f\n", i);
        i += 1;
    }

    return 0;
}