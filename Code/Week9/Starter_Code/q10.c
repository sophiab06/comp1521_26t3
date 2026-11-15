// Completed implementation of printing out the contents of the file \
// $HOME/.diary to the terminal!

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH_NAME_LEN 2048
#define DIARY_FILE_NAME ".diary"

void print_file_contents(FILE *file);

int main(void) {
    // TO DO: construct the true pathname of the $HOME/.diary file (by
    // getting the value of the $HOME environment variable), open
    // the file and print all of its contents!

    return 0;
}   


// Prints the contents of the file byte by byte using fgetc and fputc.
// Returns nothing.
void print_file_contents(FILE *file) {
    int curr_byte = fgetc(file);

    while (curr_byte != EOF) {
        fputc(curr_byte, stdout);
        curr_byte = fgetc(file);
    }
}