// Completed implementation of question 8 from the Week 5 tutorial!

#include <stdint.h>
#include <stdio.h>

#define BINARY_PREFIX_STR "0b"
#define INT_NUM_BITS 32
#define WORD_NUM_BITS 32

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
    Word output_num = 0;

    // We want the 31st bit of output_num to be set to the
    // 0th bit of input_num, 30th bit of output to be 1st bit of
    // input, etc... If you follow this logic, we see that we want
    // the nth bit of input_num to set the 31 - nth bit of output_num!
    // Let's do this bit by bit
    for (int i = 0; i < WORD_NUM_BITS; i++) {
        Word curr_bit_mask = 0b1;

        // Get the nth bit from input_num
        curr_bit_mask = curr_bit_mask << i;
        curr_bit_mask = curr_bit_mask & input_num;
        curr_bit_mask = curr_bit_mask >> i;

        // Set the WORD_NUM_BITS - 1 - nth bit in output_num
        // to be that value!
        // Note: WORD_NUM_BITS = 32, so WORD_NUM_BITS - 1 = 31 like
        // we saw before.
        curr_bit_mask = curr_bit_mask << (WORD_NUM_BITS - 1 - i);
        output_num = output_num | curr_bit_mask;

    }
    
    return output_num;
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