# Implementation of question 5 from Week 4! (note - will do nothing when ran due to absence
# of main function calling it!)

## Code to translate:
# void change (int nrows, int ncols, int M[nrows][ncols], int factor)
# {
#     for (int row = 0; row < nrows; row++) {
#         for (int col = 0; col < ncols; col++) {
#             M[row][col] = factor * M[row][col];
#         }
#     }
# }

change:
# Registers:
# - $t0 - int row
# - $t1 - int col
# - $t2 - index into the 2D array
# - $t3 - M[row][col]

change__prologue:
change__body:
change__outer_loop:
change__outer_loop__init:
	li	$t0, 0 					# int row = 0

change__outer_loop__cond:
	bge	$t0, $a0, change__outer_loop__end	# while (row < nrows)

change__outer_loop__body:
change__inner_loop:
change__inner_loop__init:
	li	$t1, 0 					# int col = 0;

change__inner_loop__cond:
	bge	$t1, $a1, change__inner_loop__end	# while (col < ncols)

change__inner_loop__body:
	mul	$t2, $t0, $a1 				# index = row * ncols
	add	$t2, $t2, $t1				# index += col

	mul	$t2, $t2, 4				# conversion to offset
	add	$t2, $t2, $a2				# get absolute address via M's 
							# address + offset into M

	lw	$t3, ($t2)				# $t3 holds M[row][col]
	mul	$t3, $t3, $a3 				# $t3 = factor * M[row][col];
	sw	$t3, ($t2)				# M[row][col] = factor * M[row][col]

change__inner_loop__step:
	addi	$t1, 1					# col += 1;
	j	change__inner_loop__cond

change__inner_loop__end:
change__outer_loop__step:
	addi	$t0, 1					# row += 1;
	j	change__outer_loop__cond

change__outer_loop__end:
change__epilogue:
	jr	$ra					# return;