// An example of how you can use errno to check for the exact reason
// a function that sets it has failed!

#include <stdio.h>
#include <errno.h>

int main(void) {
    FILE *file = fopen("nonexistent.txt", "r");

    // Error checking - fopen returns NULL on error
    if (file == NULL) {
        if (errno == ENOENT) {
            // NOTE: other library functions can 
            // change errno
            printf("file didn't open; doesn't "
            "exist\n");
        }

        // Pass a string to perror to print with 
        // the error reason!
        perror("error reason: ");
        
    } else {
        fclose(file);
    }

    return 0;
}

