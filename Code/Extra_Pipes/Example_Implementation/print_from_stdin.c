// Print the contents of stdin until EOF. Used as a test for how dup2 works for
// normal applications and for processes/pipe creation.

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define STDIN_FD 0
#define TEST_FILE_PATH "test_words.txt"

int main(void) {
    // Manipulation using file pointers
    int curr_byte = fgetc(stdin);

    while (curr_byte != EOF) {
        putchar(curr_byte);
        curr_byte = fgetc(stdin);
    }

    return 0;
}