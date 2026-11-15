// Completed implementation of a function that infinitely keeps printing
// out "Hello world!" and the phrase "Bye world!" from two separate 
// threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void *print_infinitely(void *data);

int main(void) {
    // TO DO:
    // Write a C program that creates a thread that infinitely prints 
    // some message provided by main (eg. "Hello\n"), while the main (default) 
    // thread infinitely prints a different message (eg. "there!\n").

    // STEPS
    // 1. write a function for the thread to perform
    // 2. set up the thread that prints + when to rejoin it
    // 3. set up the main printing from our function
    // 4. Modify this for question 7 if you want!

    // Launch the thread
    pthread_t id;
    pthread_create(&id, NULL, print_infinitely, "Hello world!\n");

    while (1) {
        printf("Bye world!\n");
    }

    // Collect the thread (though not going to be hit due to the
    // while (1))
    pthread_join(id, NULL);
}

// Function takes in a pointer of any type, returns a
// pointer of any type, like we need for threads!
void *print_infinitely(void *data) {
    // We're expecting the input to be a char * (address 
    // of the start of a string) - we can typecast to start 
    // working with it as a string!
    char *input_string = data;

    while (1) {
        printf("%s", input_string);
    }

    // We technically never reach this due to the while (1)
    return NULL;
}