// A demonstration of how fgets and fputs can result in
// data loss! Assumes the ten_bytes_with_nulls file exists!

#include <stdio.h>
#include <stdlib.h>

#define BIN_FILE "ten_bytes_with_nulls"
#define OUTPUT_BIN_FILE "output_bin"
#define BIN_FILE_SIZE 10

int main(void) {
    FILE *bin_file = fopen(BIN_FILE, "r");
    FILE *output_file = fopen(OUTPUT_BIN_FILE, "w");

    char *contents = malloc(sizeof(char) * (BIN_FILE_SIZE + 1));
    fgets(contents, BIN_FILE_SIZE + 1, bin_file);

    // Print the contents that were read in - normally we can't do this
    // because we don't know how much was actually read in, and rely on a 
    // 0x00 ('\0') byte to indicate the end of the string, but in this very 
    // specific case we know that it was only 10 bytes!
    printf("Read in %d bytes of bin_file: 0x", BIN_FILE_SIZE);

    for (int i = 0; i < BIN_FILE_SIZE; i++) {
        printf("%02X ", (unsigned char)contents[i]);
    }
    putchar('\n');

    // Here's what happens when we try to work with this with
    // fputs!
    fputs(contents, output_file);
    fclose(output_file);
    FILE *output_post_write = fopen(OUTPUT_BIN_FILE, "r");

    printf("Bytes written by fputs when written to a file: 0x");
    int curr_byte = fgetc(output_post_write);

    while (curr_byte != EOF) {
        printf("%02X ", curr_byte);
        curr_byte = fgetc(output_post_write);
    }
    putchar('\n');

    // We can't use fputc or fwrite easily - we cannot tell
    // the number of bytes that were actually read in usually.

    // Please don't use fgets/fputs for binary data due to the
    // issue with null bytes.

    fclose(bin_file);
    fclose(output_post_write);

    return 0;
}