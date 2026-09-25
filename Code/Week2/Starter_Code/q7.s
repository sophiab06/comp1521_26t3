# Written together in the tutorial, an implementation of a simple for loop in MIPS. More comments added in post!

main:
loop_init:
	li	$t0, 24			# int i = 24;

loop_cond:
	bge	$t0, 42, loop_end	# while (i < 42)

loop_body:
	li	$v0, 1
	move	$a0, $t0
	syscall				# print("%d", i);

	li	$v0, 11
	li	$a0, '\n'
	syscall				# putchar('\n');

loop_step:
	addi	$t0, $t0, 3		# i += 3;
	b	loop_cond

loop_end:
	li	$v0, 0			# return 0;
	jr	$ra