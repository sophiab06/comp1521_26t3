// Basic implementation of pipes used to redirect the stdin of
// a child process to be the current process (this code).

#include <stdio.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>

int main(void) {
    extern char **environ;

    // 1. Actions that need to occur in both the
    // parent and child process - making the pipe!

    int pipe_fds[2];
    pipe(pipe_fds);

    // 2. Actions that need to occur in only the child process - 
    // redirection of stdin and closing the unused write end of the pipe.
    posix_spawn_file_actions_t file_actions;
    posix_spawn_file_actions_init(&file_actions);

    // close write end of pipe in child
    posix_spawn_file_actions_addclose(&file_actions, pipe_fds[1]);  

    // redirect stdin's file descriptor to refer to
    // the pipe's read end instead
    posix_spawn_file_actions_adddup2(&file_actions, pipe_fds[0], fileno(stdin));

    // Actually spawn the process
    pid_t child_id;
    char *child_args[] = {"./print_from_stdin", NULL};
    posix_spawn(&child_id, "./print_from_stdin", &file_actions, NULL, child_args, environ);

    // 3. Actions that need to occur only in the parent process - 
    // closing the unused read end!
    close(pipe_fds[0]);

    // DO WHATEVER YOU WANT
    FILE *pipe_write = fdopen(pipe_fds[1], "w");
    fputs("hello from the pipe\n", pipe_write);

    // Terminating - close last open end of pipe here to send EOF signals
    // appropriately to the child process!
    fclose(pipe_write);                     // MUST USE fclose, not close, to avoid errors!
    waitpid(child_id, NULL, 0);

    posix_spawn_file_actions_destroy(&file_actions);

    return 0;
}