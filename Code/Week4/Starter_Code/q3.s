# Completed and commented out implementation of question 3 from the Week 4 tutorial!

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
	push	$ra

main__body:
        # WHAT WE HAD TO DO
        # - write the sum4 and sum2 functions
        # - implement the function calls.

	li	$a0, 11
	li	$a1, 13
	li	$a2, 17
	li	$a3, 19

	jal	sum_4			# $v0 holds sum4(11, 13, 17, 19)

        # Provided - the printing of the number at the end from $v0
        move	$a0, $v0
        li	$v0, PRINT_INT
        syscall				# printf("%d", result in $v0)

        li	$v0, PRINT_CHAR
        li	$a0, '\n'
        syscall				# putchar('\n')

main__epilogue:
	pop	$ra

        li	$v0, 0
        jr	$ra			# return 0


sum_4:
# Registers:			<- NOTE - good to keep even an informal list of these, even if not doing formal function header comment!
# - $s0: result_1
# - $s1: result_2
# - $s2: c
# - $s3: rd
sum_4__prologue:
	push	$ra
	push	$s0 		# result_1
	push	$s1		# result_2
	push	$s2 		# c
	push	$s3 		# d

sum_4__body:
	move	$s2, $a2 
	move	$s3, $a3

	jal	sum_2		# call sum2(a, b)
	move	$s0, $v0	# result_1 = sum2(a, b)

	move	$a0, $s2 
	move	$a1, $s3 

	jal	sum_2		# call sum2(c, d)
	move	$s1, $v0	# result_2 = sum2(c, d)

	move	$a0, $s0
	move	$a1, $s1

	jal	sum_2		# $v0 = sum2(result_1, result_2)

sum_4__epilogue:
	pop	$s3
	pop	$s2
	pop	$s1
	pop	$s0
	pop	$ra

	jr	$ra		# return sum2(result_1, result_2)


sum_2:
sum_2__prologue:
sum_2__body:
	add	$v0, $a0, $a1	# $v0 = x + y

sum_2__epilogue:
	jr	$ra		# return x + y