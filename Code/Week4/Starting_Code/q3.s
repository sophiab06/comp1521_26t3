## Code to translate:
# #include <stdio.h>

# int sum4(int a, int b, int c, int d);
# int sum2(int x, int y);

# int main(void) {
#     int result = sum4(11, 13, 17, 19);
#     printf("%d\n", result);
#     return 0;
# }

# int sum4(int a, int b, int c, int d) {
#     int res1 = sum2(a, b);
#     int res2 = sum2(c, d);
#     return sum2 (res1, res2);
# }

# int sum2(int x, int y) {
#     return x + y;
# }

PRINT_INT = 1
PRINT_CHAR = 11

main:
main__prologue:
main__body:
        # WHAT WE HAVE TO DO
        # - write the sum4 and sum2 functions
        # - implement the function calls.

        # Provided - the printing of the number at the end from $v0
        move	$a0, $v0
        li	$v0, PRINT_INT
        syscall				# printf("%d", result in $v0)

        li	$v0, PRINT_CHAR
        li	$a0, '\n'
        syscall				# putchar('\n')

main__epilogue:
        li	$v0, 0
        jr	$ra			# return 0


sum_4:
sum_4__prologue:
sum_4__body:
sum_4__epilogue:

sum_2:
sum_2__prologue:
sum_2__body:
sum_2__epilogue: