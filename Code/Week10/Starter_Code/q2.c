// Completed implementation of a program that uses posix_spawn to
// get information, such as the current date and time!

#include <stdio.h>
#include <spawn.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    // AIM:
    // Write a C program, now.c, which prints the following information:

    // The current date, using the command "date +%d-%m-%Y"
    // The current time, using the command "date +%T"
    // The current user, using the command "whoami"

    // Hint: all of these have the path /bin/<command name>
    // Alternatively, could use posix_spawnp and just the command name! 

    // Getting the date!
    // 1. argv setup
    extern char **environ;

    char *date_argv[] = {"date", "+%d-%m-%Y", NULL};

    // 2. posix call
    pid_t curr_process;
    posix_spawn(&curr_process, "/bin/date", NULL, NULL, date_argv, environ);

    // 3. wait to return
    int process_return_info;
    waitpid(curr_process, &process_return_info, 0);

    printf("date returned %d\n", WEXITSTATUS(process_return_info));

    // Getting the time!
    // 1. arg list setup
    char *date_args_2[] = {"date", "+%T", NULL};

    // 2. process spawning
    posix_spawn(&curr_process, "/bin/date", NULL, NULL, date_args_2, environ);

    // 3. wait for finish
    waitpid(curr_process, NULL, 0);

    // The current user, using the command "whoami"
    // 1. argument list
    char *whoami_args[] = {"whoami", NULL};

    // 2 (spawn) + 3 (wait to finish)
    // Only need to use the name of the command since we're using posix_spawnp
    // (which we can since we're using a command in the bin folder), not the whole 
    // pathname of the executable file!
    posix_spawnp(&curr_process, "whoami", NULL, NULL, whoami_args, environ);
    waitpid(curr_process, NULL, 0);

    return 0;
}