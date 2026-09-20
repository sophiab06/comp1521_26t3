// Written by Sophia Budkin, to present an example of how you can
// try to decompose C code into more easy to translate instructions
// if you are feeling unsure how to go about coding in MIPS!

#include <stdio.h>

// Original code
int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int num = (a + b) * (c - 2 / a);
    printf("The number generated from the inputs is"
    " %d. Was this expected?\n", num);

    return 0;    
}

// Simplified version of the code - not necessary to make, but useful if you
// are struggling with how to decompose C code into assembly and want a
// guide as to how to do it!!
int main_simplified(void) {
    int a;
    int b;
    int c;

    // Split up scanning as we can only scan in one int 
    // per syscall!
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    int num = a + b;
    int temp = 2 / a;
    temp = c - temp;        // temp = c - 2 / a;
    num = num * temp;       // num = (a + b) * (c - 2 / a);

    // Split up printf as printing strings + printing integers 
    // require different syscalls!!
    printf("The number generated from the inputs is ");
    printf("%d", num);
    printf(". Was this expected?\n");

    return 0;
}


