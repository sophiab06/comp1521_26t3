// Incomplete implementation of q5 of the tutorial, which changes the
// permissions of all given files to not be publically writeable!

#include <stdio.h>
#include <sys/stat.h>

void change_perms_if_needed(char *file_name);


int main(int argc, char *argv[]) {

    // Change permissions for all passed in files!
    for (int i = 1; i < argc; i++) {
        change_perms_if_needed(argv[i]);
    }

    return 0;
}

// Checks if the given file is publicly writeable, and if so,
// sets it to not be writeable anymore. Assumes the file exists
// and we have the permissions to change it (no error checking).
// Returns nothing.
void change_perms_if_needed(char *file_name) {
    // TO DO: Complete!
    
    // To make life saner, here are the print statements we will need
    // printf("removing public write from %s\n", ADD_SOMETHING);
    // printf("%s is not publically writable\n", ADD_SOMETHING);
}