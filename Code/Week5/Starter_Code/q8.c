// Partially completed implementation of question 8 from the Week 5 tutorial!

#include <stdint.h>
#include <stdio.h>

#define BINARY_PREFIX_STR "0b"
#define INT_NUM_BITS 32

typedef unsigned int Word;

Word reverse_bits(Word input_num);
void print_bits_int(uint32_t input);

int main(void) {
    Word num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    Word middle_bits = reverse_bits(num);

    printf("Original number in binary: ");
    print_bits_int(num);
    printf("Returned number in binary: ");
    print_bits_int((uint32_t)middle_bits);

    return 0;
}

// Function which reverses the bits of the given integer!
Word reverse_bits(Word input_num) {
    // TO DO: complete!
    Word output = 0;
    
    for (int i = 0; i < INT_NUM_BITS; i++) {
        Word mask = 1;

        mask = mask << i;
        mask = mask & input_num;
        mask = mask >> i;

        mask = mask << (INT_NUM_BITS - i - 1);
        output = output | mask;
    }

    return output;
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