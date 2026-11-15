// This program spawns a process of the "cat" (print out file contents in terminal) command

#include <stdio.h>
#include <spawn.h>
#include <sys/wait.h>
#include <stdlib.h>

#define CAT_COMMAND_PATH "/bin/cat"
#define FILE_TO_CAT_PATH "hi.txt"

int main(void) {
    extern char **environ;

    // 1. Set up the needed *argv[]
    // and environment variables

    // First argument must be the name 
    // of the program like usual!! 
    char *cat_arguments[] = {"cat", FILE_TO_CAT_PATH, NULL};

    // 2. Call posix_spawn
    pid_t child_id;

    if (posix_spawn(&child_id, CAT_COMMAND_PATH, NULL, NULL, 
        cat_arguments, environ) != 0) {
        perror("posix_spawn");
        exit(EXIT_FAILURE);

    }

    // 3. Wait for the process to finish + check the 
    // exit state!
    int child_return_details;

    if (waitpid(child_id, &child_return_details, 0) == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }

    printf("\n\nOutput from the child process finished.\n");

    // Check exit state using provided macros (see the waitpid
    // man page!!)
    if (WIFEXITED(child_return_details)) {
        printf("Exit status: %d\n", 
        WEXITSTATUS(child_return_details));
    }

    return 0;
}