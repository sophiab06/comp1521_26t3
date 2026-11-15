// Incomplete implementation of q3 from the Week 9 Tutorial, where
// we print out the file modes and file size of a bunch of given files
// using the stat() syscall!

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_some_file_info(char *filename);

int main(int argc, char *argv[]) {
        // Loop over command line arguments
        for (int arg = 1; arg < argc; arg++) {
                print_some_file_info(argv[arg]);
        }
}

// Prints out the file mode and information about whether the file
// is publicly readable/writeable, given a specific filename. Returns
// nothing.
void print_some_file_info(char *filename) {
        // Use stat to get file information
        struct stat s;

        // check that stat worked
        if (stat(filename, &s) != 0) {
                perror(filename);
                return;
        }

        // get the mode (permissions) of the file
        mode_t mode = s.st_mode;

        // check if the file is a directory
        if ((mode & S_IFDIR) == S_IFDIR) {
                printf("The directory '%s' has mode 0x%x == 0%o\n", filename, mode, mode);

        // check if the file is a regular file
        } else if (S_ISREG(mode)) {
                printf("The file '%s' has mode 0x%x == 0%o\n", filename, mode, mode);
        }

        // check if the file is publically readable
        if (mode & S_IROTH) {
                printf("%s is publically readable\n", filename);
        }

        // TO DO: Check if the file is writeable to by the group!
        // HINT: run "man inode" and scroll to the section detailing
        // st.mode...
}