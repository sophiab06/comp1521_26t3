# Written by Sophia Budkin as a debugging practice
# Want: for this program to read in a character, assuming its a letter, + print the uppercase version of it.

# Use the Mipsy Editor Features debugging tool to step through the code and find the source of the error!
# (Don't forget about the "Variables" tab on the side - would recommend using it!)

PRINT_CHAR = 11
READ_CHAR = 12
PRINT_STRING = 4

	.text
main:
	li	$v0, PRINT_STRING
	la	$a0, enter_char_str
	syscall				# printf("Please enter a char to print the uppercase version of: \n");

	li	$v0, READ_CHAR
	syscall
	move	$t0, $v0		# scanf("%c", &x);

	sub	$t0, $t0, 42		# Conversion to uppercase char by subtracting offset between uppen and lower case chars

	li	$v0, PRINT_CHAR
	move	$a0, $t0
	syscall				# print char

	li	$a0, '\n'
	syscall				# print("%c", \n);

	li	$v0, 0
	jr	$ra			# return 0;

	.data
enter_char_str:
	.asciiz	"Please enter a char to print the uppercase version of: \n"