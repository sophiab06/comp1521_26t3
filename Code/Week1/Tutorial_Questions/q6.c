#include <stdio.h>

// Rewritten for loop version
int main(void) {
    // Since i is initialised inside the loop structure, once outside
    // the for loop we cannot access the contents of it again!
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }

    return 0;
}

// Original while loop version
int main_original(void) {
    // Note: since i is initialised outside of the loop, it can be 
    // accessed outside of the loop!
    int i = 0;
    while (i < 10) {
        printf("%d\n", i);
        i++;
    }
    return 0;
}