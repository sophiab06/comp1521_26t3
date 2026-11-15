// This program is going to go through + print all of the contents of a directory.
// Has both a recursive and non-recursive option!!

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#define PARENT_DIR_NAME ".."
#define SELF_DIR_NAME "."

#define MAX_CWD_PATH_NAME_LEN 1024

void print_dir_contents_recursive(char *curr_dir_name);

int main(int argc, char *argv[]) {
    // If called with no arguments, then prints the contents
    // of the CWD

    if (argc == 1) {
        // Get the cwd
        char cwd_name[MAX_CWD_PATH_NAME_LEN];
        getcwd(cwd_name, MAX_CWD_PATH_NAME_LEN);

        print_dir_contents_recursive(cwd_name);

    } else {
       for (int i = 1; i < argc; i++) {
            print_dir_contents_recursive(argv[i]);
        }
    }
}

// Prints the contents of a given directory recursively.
void print_dir_contents_recursive(char *curr_dir_name) {
    // Try to open the current directory up
    DIR *curr_dir = opendir(curr_dir_name);

    // Error checking
    if (curr_dir == NULL) {
        perror(curr_dir_name);
        exit(EXIT_FAILURE);
    }

    printf("Current dir: %s\n", curr_dir_name);

    // Loop through all of the directory elements + print if needed
    struct dirent *curr_entry = readdir(curr_dir);
    while (curr_entry != NULL) {

        // Special case - avoid printing out/touching the special . and .. directories!
        if (strcmp(curr_entry->d_name, PARENT_DIR_NAME) == 0 ||
        strcmp(curr_entry->d_name, SELF_DIR_NAME) == 0) {
            curr_entry = readdir(curr_dir);
            continue;
        }

        // Make a string containing the absolute file name!
        int file_name_len = strlen(curr_entry->d_name) + strlen(curr_dir_name) + 2;
        char *file_full_name = malloc(sizeof(char) * file_name_len);
        snprintf(file_full_name, file_name_len, "%s/%s", curr_dir_name, curr_entry->d_name);

        printf("%s\n", file_full_name);

        // If the file is a directory then recursively print its contents too!
        // NOTE - best practice is to make a stat call, NOT use the d_type field!
        // Latter isn't standardised!
        // Also, MUST use the full name of the file, else stat will fail if you're 
        // inside a directory!
        struct stat stat_info;
        stat(file_full_name, &stat_info);

        if (S_ISDIR(stat_info.st_mode)) {
            printf("\n");
            print_dir_contents_recursive(file_full_name);
        }

        free(file_full_name);
        curr_entry = readdir(curr_dir);
    }

    closedir(curr_dir);
    return;
}