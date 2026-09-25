# Basic branching statement in MIPS practice, what we wrote in the tutorial but with more annotations!

SQUARE_MAX = 46340

	.text
main:
	li	$v0, 4
	la	$a0, enter_num_str
	syscall						# print("Enter a number: ");

	li	$v0, 5
	syscall
	move	$t0, $v0 				# scanf("%d", x)

	bgt	$t0, SQUARE_MAX, x_gt_square_max	# if (x > SQUARE_MAX)
	b	x_le_square_max	

x_gt_square_max:
	li	$v0, 4
	la	$a0, num_too_big_str
	syscall						# printf("square too big for 32 bits\n");
	b	x_conditions_rejoin

x_le_square_max:					# else
	mul	$t1, $t0, $t0				# y = x * x

	li	$v0, 1
	move	$a0, $t1
	syscall						# print("%d", y);

	li	$v0, 11
	li	$a0, '\n'
	syscall						# putchar('\n');

x_conditions_rejoin:
	li 	$v0, 0
	jr	$ra					# return 0;

	.data
enter_num_str:
	.asciiz "Enter a number: "

num_too_big_str:
	.asciiz "square too big for 32 bits\n"