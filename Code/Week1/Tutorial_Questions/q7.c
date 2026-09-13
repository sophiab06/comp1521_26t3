#include <stdio.h>

int sum(int n);
int sum_iterative(int n);

int main(int argc, char *argv[]) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = sum(n);
    printf("Sum of all numbers up to %d = %d\n", n, result);

    return 0;
}

// Implemented recursive solution
int sum(int n) {
    // TO DO:
    // Implement a recursive summing function with the same behaviour
    // as sum_iterative.
}

// Original iterative solution
int sum_iterative(int n) {
    int result = 0;
    for (int i = 0; i <= n; i++) {
        result += i;
    }
    return result;
}