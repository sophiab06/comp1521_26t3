# More complicated branching practice - what we wrote in the tutorials but with more annotations!

	.text
main:
	li	$v0, 4
	la	$a0, enter_num_str
	syscall						# print("Enter a number: ");

	li	$v0, 5
	syscall
	move	$t0, $v0 				# scanf("%d", x)

	ble	$t0, 100, x_small_or_big
	bge	$t0, 1000, x_small_or_big
	j	x_medium				# if (x > 100 && x < 1000) go to medium, else small/big.

x_medium:
	li	$v0, 4
	la	$a0, num_medium_str
	syscall						# printf("medium\n");

	j	x_conditions_rejoin

x_small_or_big:
	li	$v0, 4
	la	$a0, num_small_or_big_str
	syscall						# printf("small/big\n");

	j	x_conditions_rejoin

x_conditions_rejoin:
	li 	$v0, 0
	jr	$ra					# return 0;


	.data
enter_num_str:
	.asciiz "Enter a number: "

num_small_or_big_str:
	.asciiz "small/big\n"

num_medium_str:
	.asciiz "medium\n"