# Written by Sophia Budkin (z5687506)
# Commented out version of code written in class as practice of working with loops, array accessing and if statements.

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

PRINT_INT = 1
PRINT_STRING = 4
PRINT_CHAR = 11

	.text
main:
	# Register allocations
	# $t0 - i
	# $t1 - numbers[i]
	# $t2 - temporary offset calculations

loop_init:
	li	$t0, 0				# int i = 0;

loop_cond:
	bge	$t0, N_SIZE, loop_end		# while (i < N_SIZE)

loop_body:
	mul	$t2, $t0, 4			# Each element of numbers is 4 bytes long (array of words) - conversion of index into offset into array.
	lw	$t1, numbers($t2)		# $t1 holds numbers[i]

	blt	$t1, 0, num_i_is_neg		# if (numbers[i] < 0)
	j	loop_step

num_i_is_neg:
	addi	$t1, 42	
	sw	$t1, numbers($t2)		# numbers[i] += 42. Remember - must always store the value back in! Easy error to make!

loop_step:
	addi	$t0, 1				# i++;
	j	loop_cond

loop_end:
	li	$v0, PRINT_STRING
	la	$a0, expected_output_str_1	# printf("Input data is 0, 1, 2, -3, 4, -5, 6, -7, 8, 9.\n");
	syscall					

	la	$a0, expected_output_str_2	# printf("Loop should add 42 to any entries less than 0, and store it back.\n");
	syscall

	la	$a0, expected_output_str_3	# printf("Expected output: 0, 1, 2, 39, 4, 37, 6, 35, 8, 9 (with each on a new line!).\n\n")
	syscall

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
	.word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9

expected_output_str_1:
	.asciiz "Input data is 0, 1, 2, -3, 4, -5, 6, -7, 8, 9.\n"

expected_output_str_2:
	.asciiz	"Loop should add 42 to any entries less than 0, and store it back.\n"

expected_output_str_3:
	.asciiz	"Expected output: 0, 1, 2, 39, 4, 37, 6, 35, 8, 9 (with each on a new line!).\n\n"