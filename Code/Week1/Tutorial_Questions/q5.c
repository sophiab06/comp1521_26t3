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