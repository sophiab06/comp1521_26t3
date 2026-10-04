# Written by Sophia Budkin (z5687506)
# An implementation of Wk3 Tutorial question 5, commented to help guide how
# to approach indexing into arrays for loading/storing.

N_SIZE = 10

SIZE_OF_INT = 4

READ_INT = 5
PRINT_INT = 1
PRINT_CHAR = 11
PRINT_STRING = 4

	.text
main:
	li	$v0, PRINT_STRING
	la	$a0, take_input_str
	syscall					# printf("Please enter integers to populate the numbers array:\n");

scan_loop:
scan_loop_init:
	li	$t0, 0				# int i = 0;

scan_loop_cond:
	bge	$t0, N_SIZE, scan_loop_end	# while (i < N_SIZE)

scan_loop_body:
	li	$v0, READ_INT
	syscall
	move	$t1, $v0			# $t1 holds the scanned in integer.

	# 1. Calculate the needed index into the array - in this case, i.
	move	$t2, $t0

	# 2. Multiply the index into the array by the size of an array
	# element to convert the index into an offset in bytes
	mul	$t2, $t2, SIZE_OF_INT

	# 3. Choose your preferred address-specifying syntax.
	# (I prefer the array_start_label(register containing offset)
	# syntax!)
	sw	$t1, numbers($t2)

scan_loop_step:
	addi	$t0, 1				# i++;
	j	scan_loop_cond

scan_loop_end:
	li	$v0, PRINT_STRING
	la	$a0, expected_output_str
	syscall					# printf("Printing values stored in numbers array:\n");

print_loop:					# Printing loop not in OG task - so we see the altered version!
print_loop_init:	
	li	$t0, 0				# int i = 0;

print_loop_cond:
	bge	$t0, N_SIZE, print_loop_end	# while (i < N_SIZE)

print_loop_body:
	mul	$t2, $t0, 4			# Conversion from index to offset
	lw	$a0, numbers($t2)		# Loads numbers[i] into $a0 for printing

	li	$v0, PRINT_INT
	syscall					# printf("%d", numbers[i]);

	li	$v0, PRINT_CHAR
	li	$a0, '\n'
	syscall					# putchar('\n');

print_loop_step:
	addi	$t0, 1				# i++;
	j	print_loop_cond		

print_loop_end:
	li	$v0, 0				# return 0;
	jr	$ra


	.data
numbers:
	.word 0:N_SIZE		# if you need to have an array initialised to many instances of the
				# same number, you can use the syntax value:number of times to copy.

take_input_str:
	.asciiz	"Please enter integers to populate the numbers array:\n"

expected_output_str:
	.asciiz "\nPrinting values stored in numbers array:\n"