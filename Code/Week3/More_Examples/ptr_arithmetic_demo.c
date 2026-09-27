// Written by Sophia Budkin (z5687506) to demostrate that in C, pointer
// arithmetic depends on the pointer type!
#include <stdio.h>
#include <stdlib.h>

struct demo_struct {
    int num_field;      // 4 bytes
    char char_field;    // 1 byte
    int num_field_2;    // 4 bytes but is also aligned under the hood 
};                      // (extra 3 bytes in front).

int main(void) {
    // Initialise the pointers to any random value that isn't NULL (pointer
    // arithmetic is not defined for a NULL pointer!)
    int *int_ptr = malloc(sizeof(int));
    char *char_ptr = malloc(sizeof(char));
    struct demo_struct *demo_struct_ptr = malloc(sizeof(struct demo_struct));

    printf("Initial int pointer stored value: %p\n", int_ptr);
    printf("Initial char pointer stored value: %p\n", char_ptr);
    printf("Initial demo struct pointer stored value: %p\n", demo_struct_ptr);
    printf("\n");

    int *old_int_ptr = int_ptr;
    char *old_char_ptr = char_ptr;
    struct demo_struct *old_demo_struct_ptr = demo_struct_ptr;

    // Note - these are incrementing/walking into memory we haven't yet allocated
    // and can't write/read from safely yet! DON'T DO THIS usually, since I just
    // need to show the difference when incrementing and won't actually be doing
    // anything else with the pointer it doesn't matter here.
    int_ptr++;
    char_ptr++;
    demo_struct_ptr++;

    printf("Post-increment int pointer stored value: %p\n", int_ptr);
    printf("Post-increment char pointer stored value: %p\n", char_ptr);
    printf("Post-increment demo struct pointer stored value: %p\n", demo_struct_ptr);
    printf("\n");

    // Note: need to typecast the pointers to an integer type first, otherwise
    // it would return the number of elements it moved along (i.e. 1 for all), not
    // the number of bytes moved along! Pointer arithmetic defaults to the number of
    // elements of that type that have been traversed, not the number of bytes.
    printf("Number of bytes moved along in int_ptr++ step: %ld\n", (long)int_ptr - (long)old_int_ptr);
    printf("Number of bytes moved along in char_ptr++ step: %ld\n", (long)char_ptr - (long)old_char_ptr);
    printf("Number of bytes moved along in demo_struct_ptr++ step: %ld\n", (long)demo_struct_ptr - (long)old_demo_struct_ptr);

    // Need to free originals, not the incremented versions - need to free the memory
    // at the same address as we malloced from!
    free(old_int_ptr);
    free(old_char_ptr);
    free(old_demo_struct_ptr);

    return 0;
}