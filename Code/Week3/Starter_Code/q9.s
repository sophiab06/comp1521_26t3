# Written by Sophia Budkin
# Commented out version of code for pointer arithmetic in MIPS.

N_SIZE = 10

PRINT_STRING = 4
PRINT_INT = 1

	.text
main:
	# Register allocations
	# $t0 - char *s
	# $t1 - int length
	# $t2 - value at s (*s)

loop_init:
	la	$t0, string_counted	# char *s = string;
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
	li	$v0, PRINT_STRING
	la	$a0, calc_length_str_1
	syscall				# printf("The calculated length of the string \"");

	la	$a0, string_counted
	syscall				# printf("%s", string_counted);

	la	$a0, calc_length_str_2
	syscall				# printf("\" is ");

	li	$v0, PRINT_INT
	move	$a0, $t1
	syscall				# printf("%d", length);

	li	$v0, PRINT_STRING
	la	$a0, calc_length_str_3
	syscall				# printf(".\n");


	li	$v0, 0			# return 0;	
	jr	$ra

	.data
string_counted:
   	.asciiz  "...."

calc_length_str_1:
	.asciiz	"The calculated length of the string \""

calc_length_str_2:
	.asciiz	"\" is "

calc_length_str_3:
	.asciiz	".\n"
