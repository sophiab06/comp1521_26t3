// Task: Write a C program, print_file_bits.c, which given as a command line arguments the name of a file 
// contain 32-bit hexadecimal numbers, one per line, prints the low (least significant) bytes of each number 
// as a signed decimal number (-128..127).
// Note: expects the hexadecimal numbers to NOT be prefixed by 0x in the file when read in!

// To use, run with "test_hex_file.txt"!

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check correct num command line arguments
    if (argc != 2) {
        fprintf(stderr, "Needs 1 user-inputted argument - the input file name!\n");
        exit(1);
    }

    // Open the file with name given as command line arg 1
    // for reading
    FILE *file = fopen(argv[1], "r");

    // Error check - did fopen work?
    if (file == NULL) {
        perror("main");            
        exit(1);                    
    }                               

    // The file contains hexadecimal integers as text data, not just raw hex bytes!
    // To read these in correctly, the easiest approach is using fscanf() and the %x
    // format.
    
    uint32_t curr_int;

    while (fscanf(file, "%x", &curr_int) == 1) {
        // Mask off the least significant (right-most) byte
        uint32_t mask = 0b11111111;             // can also write this as uint32_t mask = 0xff;
        mask = mask & curr_int;

        // Print the byte as a signed integer!
        int8_t mask_signed = mask;
        printf("%d\n", mask_signed);
        
        // We could also use typecasting to write the above in one line!
        // printf("%d\n", (int8_t)mask_signed);   
        // The (int8_t) in brackets converts the type of mask_signed to int8_t before printing.
        // Generally, we avoid typecasting outside of numeric data types!
    }

    fclose(file);
    return 0;
}