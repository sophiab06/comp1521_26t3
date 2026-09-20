// Simple C translation of Q6 - using two methods for handling the logical && statement!

#include <stdio.h>

int main_alternative(void)

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x <= 100) goto x_size_is_small_or_big;      // Option 1: treating if (CONDITION_A && CONDITION_B) { do thing 1 } else { do thing 2 }
    if (x >= 1000) goto x_size_is_small_or_big;     // as if (!CONDITION_A || !CONDITION_B) { do thing 2 } else { do thing 1 }
    goto x_size_is_medium;

x_size_is_small_or_big:
    printf("small/big\n");
    goto x_size_rejoin;

x_size_is_medium:
    printf("medium\n");
    goto x_size_rejoin;

x_size_rejoin:
    return 0;
}

int main_alternative(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 100) goto x_size_test_2;        // Option 2: breaking down && into nested if statements.
    goto x_size_is_small_or_big;            // Can be easier to rewrite the if statements without ||/&&, but
                                            // requires more labels when using goto or assembly!
x_size_test_2:
    if (x < 1000) goto x_size_is_medium;
    goto x_size_is_small_or_big;

x_size_is_small_or_big:
    printf("small/big\n");
    goto x_size_rejoin;

x_size_is_medium:
    printf("medium\n");
    goto x_size_rejoin;

x_size_rejoin:
    return 0;
}