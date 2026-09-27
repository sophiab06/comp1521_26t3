# Written by Sophia Budkin (z5687506)
# An incomplete implementation of Wk 3 Tutorial question 5.

# CODE TO IMPLEMENT:
# #define N_SIZE 10

# #include <stdio.h>

# int main(void) {
#     int i;
#     int numbers[N_SIZE] = {0};

#     i = 0;
#     while (i < N_SIZE) {
#         scanf("%d", &numbers[i]);
#         i++;
#     }
# }

N_SIZE = 10

SIZE_OF_INT = 4
READ_INT = 5

	.text
main:
	# Register allocations:
	# $t0 - int i

scan_loop:
scan_loop_init:
	li	$t0, 0				# int i = 0;

scan_loop_cond:
	bge	$t0, N_SIZE, scan_loop_end	# while (i < N_SIZE)

scan_loop_body:
	# TO DO: implement scanf("%d", &numbers[i]);

scan_loop_step:
	addi	$t0, 1				# i++;
	j	scan_loop_cond

scan_loop_end:
	li	$v0, 0
	jr	$ra				# return 0;


	.data
numbers:
	.word 0:N_SIZE		# if you need to have an array initialised to many instances of the
				# same number, you can use the syntax value:number of times to copy.