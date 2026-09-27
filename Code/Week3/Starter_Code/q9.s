# Written by Sophia Budkin
# Commented out version of code for pointer arithmetic in MIPS.

N_SIZE = 10

	.text
main:
	# Register allocations
	# $t0 - char *s
	# $t1 - int length
	# $t2 - value at s (*s)
loop_init:
	la	$t0, string		# char *s = string;
	li	$t1, 0			# int length = 0;

loop_cond:
	lb	$t2, ($t0)
	beq	$t2, '\0', loop_end	# while (*s != '\0)

loop_body:
	addi	$t1, 1			# length++;

loop_step:
	addi	$t0, 1			# s++;
	j	loop_cond		# Remember, pointer arithmetic depends on the size of the element the pointer corresponds 
					# to! E.g char pointer ++ incremements by 1 byte, int pointer ++ increments by 4.

loop_end:

	li	$v0, 0			# return 0;	
	jr	$ra

	.data
string:
   .asciiz  "...."