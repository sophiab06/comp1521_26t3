## Code to translate:
# #include <stdio.h>

# #define FLAG_ROWS 6
# #define FLAG_COLS 12

# char flag[FLAG_ROWS][FLAG_COLS] = {
#     {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
#     {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
#     {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
#     {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
#     {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
#     {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'}
# };

# int main(void) {
#     for (int row = 0; row < FLAG_ROWS; row++) {
#         for (int col = 0; col < FLAG_COLS; col++) {
#             printf("%c", flag[row][col]);
#         }
#         printf("\n");
#     }
# }

FLAG_ROWS = 6
FLAG_COLS = 12

SIZE_OF_CHAR = 1

PRINT_CHAR = 11

	.text

main:
# Registers:
# - $t0 - int row
# - $t1 - int col
# - $t2 - offset calculations into flag array
# - $t3 - flag[row][col]

main__prologue:
main__body:
outer_loop:
outer_loop_init:
	li	$t0, 0					# int row = 0

outer_loop_cond:
	bge	$t0, FLAG_ROWS, outer_loop_end		# while (row < FLAG_ROWS)

outer_loop_body:
inner_loop:
inner_loop_init:
	li	$t1, 0					# int col = 0

inner_loop_cond:
	bge	$t1, FLAG_COLS, inner_loop_end		# while (col < FLAG_COLS)

inner_loop_body:
	# TO DO: translate printf("%c", flag[row][col]);

inner_loop_step:
	addi	$t1, 1					# col += 1
	j	inner_loop_cond

inner_loop_end:
	li	$v0, PRINT_CHAR
	li	$a0, '\n'
	syscall						# putchar('\n')

outer_loop_step:
	addi	$t0, 1					# row += 1
	j	outer_loop_cond

outer_loop_end:
main__epilogue:
	li	$v0, 0
	jr	$ra		# return 0;

	.data
flag:
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'