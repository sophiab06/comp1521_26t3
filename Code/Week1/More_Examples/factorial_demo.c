// Written by Sophia Budkin for a quick demo explaining recursion + how to
// go about using/implementing it.

#include <stdio.h>

int factorial_iterative(int num);
int factorial_recursive(int num);

int main(void) {
    int num;
    printf("Please enter positive number to compute factorial of: ");
    scanf("%d", &num);

    printf("Result of iterative factorial calculation: %d\n", factorial_iterative(num));
    printf("Result of recursive factorial calculation: %d\n", factorial_recursive(num));

    return 0;
}

// Calculates factorial iteratively, i.e. using the method n! = 1 * 2 * ... * n
int factorial_iterative(int num) {
    int product = 1;
    
    for (int i = 1; i <= num; i++) {
        product *= i;
    }

    return product;

}

// Calculates factorial recursively, i.e. using the general method of 
// n! = n * (n - 1)! and the base case of 1!  = 1.
int factorial_recursive(int num) {
    // Base case - must be handled separately! You must have a base case in 
    // recursive implementations to give you a point where you actually stop
    // calling the recursive function.
    if (num == 1) {
        return 1;
    }

    // General case
    return num * factorial_recursive(num - 1);
}