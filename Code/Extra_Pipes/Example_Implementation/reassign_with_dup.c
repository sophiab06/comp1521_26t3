// Pipe test - pipe output data into the print_from_stdin.c process via a given
// test file (just gonna make that a const because I do not hate myself).
// Want to make sure I get how pipes work.

#include <errno.h>
#include <sched.h>
#include <stdio.h>
#include <spawn.h>
#include <sys/wait.h>
#include <unistd.h>

#define INPUT_FILE_PATH "test_words.txt"
#define DCC_PATH "/usr/local/bin/dcc"
#define PRINT_FROM_STDIN_FILE_PATH "print_from_stdin.c"
#define PRINT_FROM_STDIN_NAME "print_from_stdin"
#define PRINT_FROM_STDIN_EXE_PATH "./print_from_stdin"

#define DCC_RENAME_FLAG "-o"

#define PIPE_READ_END 0
#define PIPE_WRITE_END 1

int main(void) {
    // Please note: the error handling is not comprehensive in all places, as this is
    // just a demo of how pipes work.

    // Part A - ensure we have an executable.
    // Run a process to run "dcc [PRINT_FROM_STDIN_FILE_PATH] -o 
    // [PRINT_FROM_STDIN_NAME]"
    pid_t dcc_pid;
    char *dcc_args[] = {DCC_PATH, PRINT_FROM_STDIN_FILE_PATH, DCC_RENAME_FLAG, 
    PRINT_FROM_STDIN_NAME, NULL};
    extern char **environ;

    if (posix_spawn(&dcc_pid, DCC_PATH, NULL, NULL, dcc_args, 
    environ) != 0) {
        perror("posix_spawn");
        return 1;
    }

    waitpid(dcc_pid, NULL, 0);

    // Part B - launch and pipe the executable.

    // Step 1 - files we need both in the parent and the child.
    // Set up the pipe between this process and the child print_from_stdin process
    int print_from_stdin_pipe_fds[2];

    if (pipe(print_from_stdin_pipe_fds) == -1) {
        perror("pipe");
        return 1;
    }

    // Step 2 - file actions we need done only in the child file.
    // Set up the file actions necessary to be performed between forking the 
    // process and executing the desired one. 
    posix_spawn_file_actions_t print_from_stdin_file_actions;

    if (posix_spawn_file_actions_init(&print_from_stdin_file_actions) != 0) {
        perror("posix_spawn_file_actions_init");
        return 1;
    }

    // Want to close the write end of the pipe on that side - only reading from
    // information we write over.
    if (posix_spawn_file_actions_addclose(&print_from_stdin_file_actions, 
    print_from_stdin_pipe_fds[PIPE_WRITE_END]) != 0) {
        perror("posix_spawn_file_actions_addclose");
        return 1;
    }

    // Want to make it so that the information sent through the pipe is then 
    // what is read in by the stdin - change the stdin file stream's associated
    // open file to that of the read end of the pipe.
    if (posix_spawn_file_actions_adddup2(&print_from_stdin_file_actions, 
    print_from_stdin_pipe_fds[PIPE_READ_END], fileno(stdin)) != 0) {
        perror("posix_spawn_file_actions_adddup2");
        return 1;
    }

    // Make the process - need to do this before closing the read end of the
    // pipe on our side since the table of file descriptors will be copied and
    // we need a copy of the read end on that side!!
    pid_t print_from_stdin_pid;
    char *print_from_stdin_args[] = {PRINT_FROM_STDIN_EXE_PATH, NULL};

    int print_process_success = posix_spawn(&print_from_stdin_pid, 
    PRINT_FROM_STDIN_EXE_PATH, &print_from_stdin_file_actions, NULL, 
    print_from_stdin_args, environ);

    if (print_process_success != 0) {
        perror("posix_spawn");
        return 1;
    }

    // Step 3 - actions that need to happen to the parent (current) process
    // only.
    // Close our unneeded read end.
    close(print_from_stdin_pipe_fds[PIPE_READ_END]);

    // Write as normal
    FILE *pipe_write = fdopen(print_from_stdin_pipe_fds[PIPE_WRITE_END], "w");
    FILE *input_file = fopen(INPUT_FILE_PATH, "r");

    int curr_byte = fgetc(input_file);

    while (curr_byte != EOF) {
        fputc(curr_byte, pipe_write);
        curr_byte = fgetc(input_file);
    }

    // Need to send over EOF when try to read - close our write end now!!
    // Without this, the program stalls.
    fclose(pipe_write);

    // Must wait for the process to finish, and let's output what the return value was
    int print_return;
    waitpid(print_from_stdin_pid, &print_return, 0);

    if (WIFEXITED(print_return)) {
        printf("\nExit status of the print_from_stdin funct: %d\n", 
        WEXITSTATUS(print_return));
    } 

    // Cleanup!
    fclose(input_file);
    posix_spawn_file_actions_destroy(&print_from_stdin_file_actions);

    return 0;
}