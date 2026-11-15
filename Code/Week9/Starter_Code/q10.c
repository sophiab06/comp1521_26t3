// Completed implementation of printing out the contents of the file \
// $HOME/.diary to the terminal!

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH_NAME_LEN 2048
#define DIARY_FILE_NAME ".diary"

void print_file_contents(FILE *file);

int main(void) {
    // WHAT WE NEED TO DO:
    // 1. get the home environment var
    char *home_dir = getenv("HOME");
    int malloced_path_buff = 0;

    // Error check - in case this somehow broke, let's use the current working dir
    // as the home directory!
    if (home_dir == NULL) {
        home_dir = malloc(sizeof(char) * (MAX_PATH_NAME_LEN + 1));
        getcwd(home_dir, MAX_PATH_NAME_LEN + 1);

        malloced_path_buff = 1;
    }

    // 2. construct the diary file name
    char *diary_file_name = malloc(sizeof(char) * (strlen(home_dir) + strlen(DIARY_FILE_NAME) + 2));
    snprintf(diary_file_name, strlen(home_dir) + strlen(DIARY_FILE_NAME) + 2, "%s/%s", 
             home_dir, DIARY_FILE_NAME);

    // 3. Open the file + print the contents (we can't assume it's just text data though!!)
    FILE *diary_file = fopen(diary_file_name, "r");

    if (diary_file == NULL) {
        perror(diary_file_name);
        exit(EXIT_FAILURE);
    }

    print_file_contents(diary_file);
    
    // 4. free needed memory!
    fclose(diary_file);
    free(diary_file_name);

    if (malloced_path_buff) {
        free(home_dir);
    }

    return 0;
}   


// Prints the contents of the file byte by byte using fgetc and fputc.
// Returns nothing.
void print_file_contents(FILE *file) {
    int curr_byte = fgetc(file);

    while (curr_byte != EOF) {
        fputc(curr_byte, stdout);
        curr_byte = fgetc(file);
    }
}