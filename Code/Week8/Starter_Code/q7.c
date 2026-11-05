// Completed task: Write a C program, append_line.c, which is given one command-line argument, the name of a 
// file, and which reads a line from stdin and appends it to the specified file.

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    // Check correct num command line arguments
    if (argc != 2) {
        fprintf(stderr, "Needs 1 user-inputted argument - the output file name!\n");
        exit(1);
    }

    // Open the file with name given as command line arg 1
    // for appending
    FILE *file = fopen(argv[1], "a");

    // Error check - file opened correctly?
    if (file == NULL) {
        perror("main");
        exit(1);
    }

    // Get a line from stdin, with error-checking!
    printf("Enter a string to write to %s: ", argv[1]);

    char *str_buffer = malloc(sizeof(char) * (MAX_LINE_LENGTH + 1));
    if (fgets(str_buffer, MAX_LINE_LENGTH + 1, stdin) == NULL) {
        fprintf(stderr, "fgets: failed to read in string to append\n");
        exit(1);
    }

    // Writes read in string to file, with error-checking!
    if (fputs(str_buffer, file) == EOF) {
        fprintf(stderr, "fputs: failed to append to file\n");
    }

    fclose(file);

    return 0;
}