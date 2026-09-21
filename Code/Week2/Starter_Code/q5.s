# Basic branching statement in MIPS practice!

# #include <stdio.h>

# #define SQUARE_MAX 46340

# int main(void) {
#     int x, y;

#     printf("Enter a number: ");
#     scanf("%d", &x);

#     if (x > SQUARE_MAX) goto x_gt_square_max;
#     goto x_le_square_max;

# x_gt_square_max:
#     printf("square too big for 32 bits\n");
#     goto x_conditions_rejoin;                   // NOTE: remember, need this here, otherwise the 
#                                                 // execution will "fall through" + start executing 
#                                                 // things in the else statement!
# x_le_square_max:
#     y = x * x;
#     printf("%d\n", y);

# x_conditions_rejoin:

#     return 0;
# }

SQUARE_MAX = 46340

# TO DO - add a SQUARE_MAX constant!

	.text
main:
	# TO DO - translate!
	li	$v0, 4
	la	$a0, enter_num_str
	syscall

	li	$v0, 5
	syscall
	move	$t0, $v0

	bgt	$t0, SQUARE_MAX, x_gt_square_max
	j	x_le_square_max

x_gt_square_max:
	li	$v0, 4
	la	$a0, num_too_big_str
	syscall

	j	x_conditions_rejoin
    
x_le_square_max:
	mul	$t1, $t0, $t0

	li	$v0, 1
	move	$a0, $t1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

	j	x_conditions_rejoin

x_conditions_rejoin:
	li 	$v0, 0
	jr	$ra					# return 0;

	.data
enter_num_str:
	.asciiz "Enter a number: "

num_too_big_str:
	.asciiz "square too big for 32 bits\n"