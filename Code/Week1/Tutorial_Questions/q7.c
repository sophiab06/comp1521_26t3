#include <stdio.h>

int sum(int n);

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
    // Base case
    if (n == 0) {
        return 0;
    }

    // General case
    return n + sum(n - 1);
}

// // Original iterative solution
// int sum_iterative(int n) {
//     int result = 0;
//     for (int i = 0; i <= n; i++) {
//         result += i;
//     }
//     return result;
// }