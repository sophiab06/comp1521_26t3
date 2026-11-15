// Completed implementation of q8 in the Week 9 tutorial, which aims
// to count the number of codepoints in an assumed valid UTF-8 string.

#include <stdio.h>
#include <string.h>

// When working with UTF-8 sequences, best style is to
// use constants for the masks (not needed in labs/exams)!

#define ASCII_BYTE_MASK 0b10000000
#define ASCII_BYTE_OUTPUT 0
#define TWO_BYTE_HEADER_MASK 0b11100000
#define TWO_BYTE_HEADER_OUTPUT 0b11000000
#define THREE_BYTE_HEADER_MASK 0b11110000
#define THREE_BYTE_HEADER_OUTPUT 0b11100000

int count_num_codepoints(char *utf_string);

int main(int argc, char *argv[]) {
    // Assumes the first user-given command-line argument
    // is the UTF-8 string!
    printf("There are %d codepounts in string \"%s\"!\n", 
        count_num_codepoints(argv[1]), argv[1]);

    return 0;
}

// Counts the number of codepoints in a UTF 8 string. Assumes all
// of the codepoints are valid. Returns the number of codepoints.
int count_num_codepoints(char *utf_string) {
    int index = 0;      // index of current byte
    int count = 0;      // number of codepoints

    while (utf_string[index] != '\0') {
        char curr_byte = utf_string[index];

        // Check if ASCII byte - in form 0xxx xxxx
        if ((curr_byte & ASCII_BYTE_MASK) == ASCII_BYTE_OUTPUT) {
            index++;
        } 
        // Check if two-byte sequence - header byte in form 110x xxxx
        else if ((curr_byte & TWO_BYTE_HEADER_MASK) == TWO_BYTE_HEADER_OUTPUT) {
            index += 2;
        } 
        // Check if three-byte sequence - header byte in form 1110 xxxx
        else if ((curr_byte & THREE_BYTE_HEADER_MASK) == THREE_BYTE_HEADER_OUTPUT) {
            index += 3;
        } 
        // Only other option (assuming valid sequence) is four-byte 
        // sequence - header byte in form 1111 0xxx
        else {
            index += 4;
        }

        // Read one codepoint per loop.
        count++;
    }

    return count;
}