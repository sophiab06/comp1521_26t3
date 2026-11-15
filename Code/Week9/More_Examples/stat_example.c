// Written to demonstrate how to use the stat struct!!

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    // Prints the file size + modes for all files passed in
    // as command line args

    for (int i = 1; i < argc; i++) {
        char *curr_file_name = argv[i];

        // Stat struct doesn't necessarily need to be malloced - just 
        // needs to exist in some way
        struct stat stat_info;

        // This populates the stat struct, with error 
        // checking to be sure it works!
        if (stat(curr_file_name, &stat_info) != 0) {
            perror(curr_file_name);
            exit(EXIT_FAILURE);
        }

        // We can use the mode masks that come with sys/stat.h!
        uint16_t mode_mask = S_IRWXU | S_IRWXG | S_IRWXO;
        mode_mask = stat_info.st_mode & mode_mask;

        printf("File %s has size %ld bytes and "
        "has mode bits %3o\n", curr_file_name, 
        stat_info.st_size, mode_mask);
    }

    // Set the first command line argument file name's perms 
    // to readable, writeable, executable for all.
    if (argc > 1) {
        chmod(argv[1], 0777);
    }

    return 0;
}