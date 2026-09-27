# Written by Sophia Budkin (z5687506) to demonstrate how the .align directive
# works!!

# Usage explanation: demonstration of how different directives have different
# alignments in-built, and associated issues with misaligned data types.

# Run-through notes:
# Scenario 1: no .align + .space not .word - errors thrown.
# Scenario 2: no .align BUT .word - errors not thrown, works fine
# Scenario 3: .align and either - works fine (as long as aligned to >= 2)

PRINT_INT = 1
PRINT_STRING = 4
PRINT_CHAR = 11


	.text
main:
	# $t0 - used for temp loading in of the stored int to make sure 
	# everything worked well
	# $t1 - used for temp storage of immediate to be stored

	# This section always runs - just to show that the program is doing 
	# something

	li	$v0, PRINT_STRING
	la 	$a0, random_str
	syscall				# printf("%s", random_str);

	# Note: next section will fail if the random_int space allocated is 
	# unaligned!

	li	$t1, 42
	sw	$t1, random_int		# random_int = 42;

	lw	$t0, random_int		# loads $t0 = random_int;	

	li	$v0, PRINT_INT
	move	$a0, $t0
	syscall				# printf("%d", random_int);

	li	$v0, PRINT_CHAR
	li	$a0, '\n'
	syscall				# putchar('\n');

epilogue:
	li	$v0, 0
	jr	$ra			# return 0;


	.data
random_str:
	.asciiz "hello!!\n"
	.align	1

random_int:
	.space	4
	# .word	4

# Used to make transition clear when looking in debug view and using .space so the initial value of random_int is uninitialised
end_byte:
	.byte 1