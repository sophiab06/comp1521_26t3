// Task: Write a C program which is given one command-line argument, the name of a file, and which prints 
// the first line of that file to stdout. If given an incorrect number of arguments, or if there was an error 
// opening the file, it should print a suitable error message.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // TO DO: COMPLETE
    // Remember: argc counts the number of arguments, argv is a string array
    // we can use to access that. argv[0] is the called program's name!

    // Check correct num command line arguments
    if (argc != 2) {
        fprintf(stderr, "Needs 1 user-inputted argument");
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");

    // check that fopen worked
    if (file == NULL) {
        perror("main");
        exit(1);
    }

    char *input = malloc(sizeof(char) * 1024);
    fgets(input, 1024, file);

    printf("%s\n", input);

    fclose(file);

    return 0;
}