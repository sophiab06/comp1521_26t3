// Completed task: Write a C program, write_line.c, which is given one command-line argument, the name of a
// file, and which reads a line from stdin, and writes it to the specified file; if the file exists, it  
// should be overwritten.

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    // Check correct num command line arguments
    if (argc != 2) {
        fprintf(stderr, "Needs 1 user-inputted argument - the output file name!\n");
        exit(EXIT_FAILURE);
    }

    // Open the file with name given as command line arg 1
    // for writing
    FILE *file = fopen(argv[1], "w");

    // Error check - file opened correctly?
    if (file == NULL) {
        perror("main");
        exit(EXIT_FAILURE);
    }

    // Get a line from stdin, with error-checking!
    printf("Enter a string to write to %s: ", argv[1]);

    char *str_buffer = malloc(sizeof(char) * (MAX_LINE_LENGTH + 1));
    if (fgets(str_buffer, MAX_LINE_LENGTH + 1, stdin) == NULL) {
        fprintf(stderr, "fgets: failed to read in string to write\n");
        exit(EXIT_FAILURE);
    }

    // Writes read in string to file, with error-checking!
    if (fputs(str_buffer, file) == EOF) {
        fprintf(stderr, "fputs: failed to write to file\n");
    }

    fclose(file);
    free(str_buffer);

    return 0;
}