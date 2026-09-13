#include <stdio.h>

// Rewritten for loop version
int main(void) {
    // TO DO:
    // rewrite the while loop in main_original(), using a for loop
    // instead!
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