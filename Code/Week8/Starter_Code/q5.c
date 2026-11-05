// Completed Task: Write a C program which is given one command-line argument, the name of a file, and which 
// prints the first line of that file to stdout. If given an incorrect number of arguments, or if there was  
// an error opening the file, it should print a suitable error message.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

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
        perror("main");             // prints the error reason indicated by errno under the hood (set by fopen)!
        exit(1);                    // exit(); is often better than return - completely exits the program at the point
    }                               // the error occured, even if it's 10 function call deep! Results in neater code.

    // Reads in the first line of the opened text file, with error-checking!
    char *input = malloc(sizeof(char) * (MAX_LINE_LENGTH + 1));
    if (fgets(input, MAX_LINE_LENGTH + 1, file) == NULL) {
        fprintf(stderr, "fgets: failed to read in string from file\n");
        exit(1);
    }

    // We don't need an extra new line except for if we have fully filled the buffer, as
    // fgets reads in up until a new line inclusive!
    printf("%s", input);

    if (strlen(input) == MAX_LINE_LENGTH && input[MAX_LINE_LENGTH - 1] != '\n') {
        putchar('\n');
    }

    fclose(file);

    return 0;
}