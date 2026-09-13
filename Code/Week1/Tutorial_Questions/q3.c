#include <stdio.h>
#include <stdlib.h>

int *get_num_ptr(void);

int main(void) {
    int *num = get_num_ptr();
    printf("%d\n", *num);

    free(num);
}

int *get_num_ptr(void) {
    // Need to use malloc here so that the information 
    // stored at the pointer's location can still be
    // accessed after this function's stack frame is
    // destroyed post-returning!!
    int *x = malloc(sizeof(int));
    *x = 42;

    return x;
}