# Commented up version of the loop printing the contents of an array of ints that we ran through in the tutorial!

N_SIZE = 10

	.text
main:
	# Register allocations:
	# $t0 - int i
	# $t1 - temporary offset calcs
	# $a0, $v0 - syscalls
loop_init:
	li	$t0, 0				# int i = 0;

loop_cond:
	bge	$t0, N_SIZE, loop_end		# while (i < N_SIZE)

loop_body:
	mul	$t1, $t0, 4 			# Each element in our array is 4 bytes in size - need to convert the index to an offset in bytes!
	lw	$a0, numbers($t1)		# $a0 holds numbers[i]

	li	$v0, 1
	syscall					# printf("%d", numbers[i]);

	li	$v0, 11
	li	$a0, '\n'
	syscall					# putchar('\n');

loop_step:
	addi	$t0, 1				# i++;
	j	loop_cond

loop_end:
	li	$v0, 0				# return 0;
	jr	$ra

	.data
numbers:
	.word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9