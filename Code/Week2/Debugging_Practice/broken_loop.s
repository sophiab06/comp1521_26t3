# Written by Sophia Budkin as a debugging demo on how to use the debug mode to debug issues with loops!
# Wanted behaviour: read in an integer, then calculate the nth triangular number and prints it.

# Use the Mipsy Editor Features debugging tool to identify the source of the error by stepping through the code!
# (Keeping an eye on the "variables" tab would be particularly helpful here.)

PRINT_STRING = 4
READ_INT = 5
PRINT_INT = 1
PRINT_CHAR = 11

	.text
main:
	# Register allocation notes
	# $t0 - int n (what triangular number to calculate to)
	# $t1 - int i
	# $t2 - int curr_tri (current triangular number)

	li	$v0, PRINT_STRING
	la	$a0, enter_num_str
	syscall					# printf("Enter a number...");

	li	$v0, READ_INT
	syscall
	move	$t0, $v0			# scanf("%d", &n);

triangle_loop:
triangle_loop__init:
	li	$t1, 0				# int i = 0;
	li	$t2, 0				# int curr_tri = 0;

triangle_loop__cond:
	bgt	$t1, $t0, triangle_loop__end	# while (i < n)

triangle_loop__body:
	add	$t2, $t2, $t1			# curr_tri += i;

triangle_loop__step:
	addi	$t1, $t1, 1			# i++;
	j	triangle_loop__init

triangle_loop__end:
	li	$v0, PRINT_STRING		# printf("The calculated triangular...");
	la	$a0, triangular_num_str
	syscall

	li	$v0, PRINT_INT			# printf("%d", curr_tri);
	move	$a0, $t2
	syscall

	li	$v0, PRINT_CHAR			# putchar('\n');
	li	$a0, '\n'
	syscall

	li	$v0, 0				# return 0;
	jr	$ra


	.data
enter_num_str:
	.asciiz "Enter a number n to compute the nth triangular number (starting with the 0th number is 0): \n"

triangular_num_str:
	.asciiz "The calculated triangular number is: "