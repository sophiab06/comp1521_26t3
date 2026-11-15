// Incomplete implementation of a program that uses posix_spawn to
// get information, such as the current date and time!

#include <stdio.h>
#include <spawn.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    // AIM: Write a C program, now.c, which prints the following 
    // information:

    // The current date, using the command "date +%d-%m-%Y"
    // The current time, using the command "date +%T"
    // The current user, using the command "whoami"

    // Hint: all of these have the path /bin/<command name>
    // Alternatively, could use posix_spawnp and just the command name! 

    return 0;
}