// Partially completed implementation of question 4 from the Week 5 tutorial!

#include <stdint.h>
#include <stdio.h>

#define BINARY_PREFIX_STR "0b"
#define INT_NUM_BITS 32

uint32_t six_middle_bits(uint32_t input_num);
void print_bits_int(uint32_t input);

int main(void) {
    uint32_t num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    uint32_t middle_bits = six_middle_bits(num);

    printf("Original number in binary: ");
    print_bits_int(num);
    printf("Returned number in binary: ");
    print_bits_int(middle_bits);

    return 0;
}

// Function which returns the 6 middle bits (note - leaving them in the
// same position, i.e. something like 00...00XXXXXX00...00)
uint32_t six_middle_bits(uint32_t input_num) {
    // TO DO: complete!
    // HINT - define a custom mask, perhaps?
    return 0;
}

// Function which prints a 32 bit integer bit by bit on a new line!
void print_bits_int(uint32_t input) {
    printf("%s", BINARY_PREFIX_STR);

    for (int i = 0; i < INT_NUM_BITS; i++) {
        uint32_t mask = 1;

        // Fetch the current bit left to right!
        mask = mask << (INT_NUM_BITS - 1 - i);
        mask = mask & input;
        mask = mask >> (INT_NUM_BITS - 1 - i);

        printf("%d", mask);
    }

    putchar('\n');
    return;
}