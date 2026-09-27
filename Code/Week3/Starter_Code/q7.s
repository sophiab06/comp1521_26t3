# Written by Sophia Budkin (z5687506)
# Commented out version of code written in class as practice of working with loops, array accessing and if statements.


N_SIZE = 10

	.text
main:
	# Register allocations
	# $t0 - i
	# $t1 - numbers[i]
	# $t2 - temporary offset calculations
loop_init:
	li	$t0, 0			# int i = 0;

loop_cond:
	bge	$t0, N_SIZE, loop_end	# while (i < N_SIZE)

loop_body:
	mul	$t2, $t0, 4		# Each element of numbers is 4 bytes long (array of words) - conversion of index into offset into array.
	lw	$t1, numbers($t2)	# $t1 holds numbers[i]

	blt	$t1, 0, num_i_is_neg	# if (numbers[i] < 0)
	j	loop_step

num_i_is_neg:
	addi	$t1, 42	
	sw	$t1, numbers($t2)	# numbers[i] += 42. Remember - must always store the value back in! Easy error to make!

loop_step:
	addi	$t0, 1			# i++;
	j	loop_cond

loop_end:

	li	$v0, 0			# return 0;
	jr	$ra

	.data
numbers:
	.word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9