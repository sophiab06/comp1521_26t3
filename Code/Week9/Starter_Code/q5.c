// Completed implementation of q5 of the tutorial, which changes 

#include <stdio.h>
#include <sys/stat.h>

void change_perms_if_needed(char *file_name);


int main(int argc, char *argv[]) {
    // WHAT WE HAD TO DO:
    // For all of the files passed as command line args:
    // 1. Get the file's metadata
    // 2. Check if publicly writeable
    // 3. Print associated message
    // 4. Change to not be publically writeable if it was

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
    // Getting metadata
    struct stat st;
    stat(file_name, &st);

    // If publicly writeable
    if (st.st_mode & S_IWOTH) {
        printf("removing public write from %s\n", file_name);

        // S_IWOTH  = 0b 000 000 000 000 000 010
        // ~S_IWOTH = 0b 111 111 111 111 111 101 <- this as a mask keeps all the original 
        //                                          bit values in st.st_mode except the 
        //                                          write bit for others!

        mode_t new_mode = st.st_mode & ~S_IWOTH;

        // Must use this function to change perms!
        // Note - only works without error if we are the owner of the
        // file!
        chmod(file_name, new_mode);

    } else {
        printf("%s is not publically writable\n", file_name);
    }
}