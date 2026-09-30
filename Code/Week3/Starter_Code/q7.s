# Written by Sophia Budkin (z5687506)
# Incomplete impementation!

# CODE TO TRANSLATE:
# #define N_SIZE 10

# int main(void) {
#     int i;
#     int numbers[N_SIZE] = {0, 1, 2, -3, 4, -5, 6, -7, 8, 9};

#     i = 0;
#     while (i < N_SIZE) {
#         if (numbers[i] < 0) {
#             numbers[i] += 42;
#         }
#         i++;
#     }
# }


N_SIZE = 10

	.text
main:
	# Register allocations
	# $t0 - i

loop_init:
	li	$t0, 0			# int i = 0;

loop_cond:
	bge	$t0, N_SIZE, loop_end	# while (i < N_SIZE)

loop_body:
	# TO DO: implement body of the loop!

loop_step:
	addi	$t0, 1			# i++;
	j	loop_cond

loop_end:

	li	$v0, 0			# return 0;
	jr	$ra

	.data
numbers:
	.word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9