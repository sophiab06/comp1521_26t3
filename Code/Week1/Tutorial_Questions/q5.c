// Implementation of q5.c - a program that counts the number
// of chars read in. Implemented using getchar()!

#include <stdio.h>

int main(void) {
    int count = 0;
    int curr_char;

    // Remember, can use manual to look up info on unknown functions!
    while ((curr_char = getchar()) != EOF) {
        count++;
    }

    printf("Num chars read in: %d\n", count);

    return 0;
}