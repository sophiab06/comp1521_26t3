// Written by Sophia Budkin, as a demo of how you can try to simplify if statements using goto!!
#include <stdio.h>

int main_simplified(void);

int main(void) {
    int num;
    printf("Please enter a number: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("The number is even.\n");
    } else {
        printf("The number is odd.\n");
    }

    return 0;
}

int main_simplified(void) {
    int num;
    printf("Please enter a number: ");
    scanf("%d", &num);

    if (num % 2 == 0) goto num_div_by_two_true;
    goto num_div_by_two_false;

num_div_by_two_true:
    printf("The number is even.\n");
    goto num_div_conditions_rejoin;     // NOTE: must have this, otherwise the code will continue to just 
                                        // "fall through" the labels and execute the false portion as well!
num_div_by_two_false:
    printf("The number is not divisible by 2 or 3.\n");
    goto num_div_conditions_rejoin;     // This goto isn't necessary, but can be good to have in case you add
                                        // more cases below to prevent future bugs!!

num_div_conditions_rejoin:
    return 0;
}