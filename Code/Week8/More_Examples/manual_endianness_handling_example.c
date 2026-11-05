// Example of how to handle endianness manually!

// This example reads in a file of 32-bit integers of unknown endianness using fread, 
// a function that reads in 32-bit integers assuming they are big endian, and one that
// reads in 32-bit integers assuming they are little endian instead!

// Note how on little endian machines the little endian func has the same output as using fread - on
// big endian machines, fread will have the same output as the big endian func, but the little endian
// function will still read in numbers the same way!

// Designed to work with the file 32_bit_ints.bin, which is known to contain 12 32-bit integers.
// (You can easily make a function to account for varied sizes of the file, using either fseek/ftell
// to get the size, or the stat() function to get file metadata (more next week!))

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>

#define FOUR_BYTE_INT_FILE "32_bit_ints.bin"
#define BYTES_PER_INT 4
#define BITS_IN_BYTE 8
#define INTS_IN_FILE 12

#define FILE_FUNC_FAILED -1

#define PRINT_DEC 'd'
#define PRINT_HEX 'x'

void print_contents_using_fread(FILE *file);
void print_int_array(uint32_t *array, int size, char print_mode);
void fseek_with_error(FILE *stream, long offset, int whence);

void print_contents_using_bigend(FILE *file);
uint32_t read_bigend_32_bit_int(FILE *file);

void print_contents_using_litend(FILE *file);
uint32_t read_litend_32_bit_int(FILE *file);

int main(void) {
    // opens int file with error-checking
    FILE *int_file = fopen(FOUR_BYTE_INT_FILE, "r");

    if (int_file == NULL) {
        perror("main");
        exit(EXIT_FAILURE);
    }
    
    // Prints using fread + seeks back to start of file
    print_contents_using_fread(int_file);
    fseek_with_error(int_file, 0, SEEK_SET);

    // Prints using custom big-endian function + seeks back to start of file
    print_contents_using_bigend(int_file);
    fseek_with_error(int_file, 0, SEEK_SET);

    // Prints using custom little-endian function + seeks back to start of file
    print_contents_using_litend(int_file);
    fseek_with_error(int_file, 0, SEEK_SET);

    fclose(int_file);
    return 0;
}

// Reads in the contents of the given file using fread(), then
// prints all of them!
void print_contents_using_fread(FILE *file) {
    uint32_t *array = malloc(sizeof(uint32_t) * INTS_IN_FILE);

    // Reads in and fills the array, complete with error-checking!
    if (fread(array, sizeof(uint32_t), INTS_IN_FILE, file) != INTS_IN_FILE && ferror(file)) {
        fprintf(stderr, "print_contents_using_fread: Failed to read full array in.\n");
        exit(EXIT_FAILURE);
    }

    // Prints the array
    printf("Values read in using fread (matches the output of custom little-endian reader"
        " on little-endian machines, and big-endian reader on big-endian machines):\n");
    printf("\tAs decimals: ");
    print_int_array(array, INTS_IN_FILE, PRINT_DEC);

    printf("\tAs hexadecimals: ");
    print_int_array(array, INTS_IN_FILE, PRINT_HEX);
    putchar('\n');

    free(array);
}

// Prints the given integer array. Returns nothing.
void print_int_array(uint32_t *array, int size, char print_mode) {
    for (int i = 0; i < size; i++) {
        // Prints either in decimal or hex, depending on the
        // specified print mode!
        if (print_mode == PRINT_HEX) {
            printf("0x%08x", array[i]);
        } else {
            printf("%d", array[i]);
        }

        if (i < size - 1) {
            printf(", ");
        } else {
            printf(".\n");
        }
    }
}

// Performs fseek with error-checking, exiting early if an error occurs.
void fseek_with_error(FILE *stream, long offset, int whence) {
    if (fseek(stream, offset, whence) == FILE_FUNC_FAILED) {
        perror("fseek_with_error");
        exit(EXIT_FAILURE);
    }
}

// Prints the contents of the file using the custom big-endian reading-in function.
// Returns nothing.
void print_contents_using_bigend(FILE *file) {
    uint32_t *array = malloc(sizeof(uint32_t) * INTS_IN_FILE);

    // Reads in and fills the array!
    for (int i = 0; i < INTS_IN_FILE; i++) {
        array[i] = read_bigend_32_bit_int(file);
    }

    // Prints the array
    printf("Values read in using custom big-endian reading function:\n");
    printf("\tAs decimals: ");
    print_int_array(array, INTS_IN_FILE, PRINT_DEC);
    
    printf("\tAs hexadecimals: ");
    print_int_array(array, INTS_IN_FILE, PRINT_HEX);
    putchar('\n');

    free(array);
}

// Reads in a 32-bit big endian integer byte by byte,
// returning it. (It assumes that an integer is stored in big-endian
// mode, regardless of the mode used by the computer's CPU!)
uint32_t read_bigend_32_bit_int(FILE *file) {
    uint32_t output = 0;

    for (int i = 0; i < BYTES_PER_INT; i++) {
        // Gets the next byte with error-checking
        int curr_byte = fgetc(file);

        if (curr_byte == EOF) {
            fprintf(stderr, "read_bigend_32_bit_int: failed to read\n");
            exit(EXIT_FAILURE);
        }

        // Big endian stores the largest byte first: each loop, this
        // moves the previously read-in bytes to the front, and adds
        // the new one on the back. Typecasting used to ensure that
        // curr_byte and output have the same size before OR-ing in!
        output = output << BITS_IN_BYTE;
        output = output | (uint32_t)curr_byte;
    }

    return output;
}

// Prints the contents of the file using the custom little-endian 
// reading-in function. Returns nothing.
void print_contents_using_litend(FILE *file) {
    uint32_t *array = malloc(sizeof(uint32_t) * INTS_IN_FILE);

    // Reads in and fills the array!
    for (int i = 0; i < INTS_IN_FILE; i++) {
        array[i] = read_litend_32_bit_int(file);
    }

    // Prints the array
    printf("Values read in using custom little-endian reading function:\n");
    printf("\tAs decimals: ");
    print_int_array(array, INTS_IN_FILE, PRINT_DEC);

    printf("\tAs hexadecimals: ");
    print_int_array(array, INTS_IN_FILE, PRINT_HEX);
    putchar('\n');

    free(array);
}

// Reads in a 32-bit little endian integer byte by 
// byte, returning it. (It assumes that an integer is 
// stored in little-endian mode, regardless of the mode 
// used by the computer's CPU!)
uint32_t read_litend_32_bit_int(FILE *file) {
    uint32_t output = 0;

    for (int i = 0; i < BYTES_PER_INT; i++) {
        // Gets the next byte with error-checking
        int curr_byte = fgetc(file);

        if (curr_byte == EOF) {
            fprintf(stderr, "read_litend_32_bit_int: failed to read\n");
            exit(EXIT_FAILURE);
        }


        // Little endian has the last byte stored first.
        // We need to shift the current read in byte to the
        // front of the output by i bytes, the OR it in!
        uint32_t curr_byte_shifting = (uint32_t)curr_byte;
        curr_byte_shifting = curr_byte_shifting << (i * BITS_IN_BYTE);
        output = output | curr_byte_shifting;
    }

    return output;
}
