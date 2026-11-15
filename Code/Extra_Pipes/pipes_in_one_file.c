// A demonstration of how pipe files work within one process.
// Note how read gets anything we write into the write end!

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int pipe_1[2];

    // Sets up the pipe in the system-wide file table;
    // sets two file descriptors in this process to refer
    // to the read and write end; puts read end in pipe_1[0],
    // write end in pipe_1[1].
    pipe(pipe_1);

    // Using this you can now treat both ends as normal
    // using the stdio functions!
    FILE *read_end = fdopen(pipe_1[0], "r");    // read end is pipe_1[0]
    FILE *write_end = fdopen(pipe_1[1], "w");   // write end is pipe_1[1] 

    // Anything we write in the write end we get back in the read end.
    fputs("hello from the other side", write_end);
    fputs("... i must have called a thousand times...\n", write_end);

    // Let's close the pipe - if the write end stays open,
    // we never get EOF, so things go sideways.
    fclose(write_end);
    
    // We're expecting the same stuff as was in the pipe to
    // come through now! (note - only going to read until a new 
    // line char/EOF)
    char *pipe_output = malloc(sizeof(char) * 128);
    fgets(pipe_output, 128, read_end);

    printf("Message received from write end of pipe: %s", pipe_output);

    fclose(read_end);

    return 0;
}