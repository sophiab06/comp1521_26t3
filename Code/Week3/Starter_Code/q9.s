# Written by Sophia Budkin
# Incomplete implementation!

# CODE TO TRANSLATE:
# char *string = "....";
# char *s = &string[0];
# int   length = 0;
# while (*s != '\0') {
#    length++;  // increment length
#    s++;       // move to next char
# }

N_SIZE = 10

	.text
main:
	# Register allocations
	# $t0 - char *s
	# $t1 - int length

loop_init:
	la	$t0, string		# char *s = string;
	li	$t1, 0			# int length = 0;

	# TO DO: implement rest of loop!

loop_cond:

loop_body:

loop_step:

loop_end:
	li	$v0, 0			# return 0;	
	jr	$ra

	.data
string:
   .asciiz  "...."