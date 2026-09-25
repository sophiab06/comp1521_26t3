// Simple C code for question 5 of the tutorial!

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    int x, y;

    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > SQUARE_MAX) goto x_gt_square_max;
    goto x_le_square_max;

x_gt_square_max:
    printf("square too big for 32 bits\n");
    goto x_conditions_rejoin;                   // NOTE: remember, need this here, otherwise the 
                                                // execution will "fall through" + start executing 
                                                // things in the else statement!
x_le_square_max:
    y = x * x;
    printf("%d\n", y);

x_conditions_rejoin:

    return 0;
}