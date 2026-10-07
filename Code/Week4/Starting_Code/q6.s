## Code to translate:
# int max(int array[], int length) {
#     // 
#     int first_element = array[0];
#     if (length == 1) {
#         // Handle the base-case of the recursion, at the end of the array.
#         return first_element;
#     } else {
#         // Recurse on the rest of the array.
#         // Finds the largest element after first_element in the array.
#         int max_so_far = max(&array[1], length - 1);

#         // Compare this element with the largest element after it in the array.
#         if (first_element > max_so_far) {
#             max_so_far = first_element;
#         }
#         return max_so_far;
#     }
# }

SIZE_OF_INT = 4

NUMBERS_1_LEN = 7
NUMBERS_2_LEN = 3

PRINT_STRING = 4
PRINT_INT = 1
PRINT_CHAR = 11

	.text
main:
    # Frame:    [$ra]  
    # Uses:     [$ra, $a0, $a1, $v0, $t0]
    # Clobbers: [$a0, $a1, $v0, $t0]
    #
    # Locals:
    # 	- $a0 - syscalls, calling max()
    #	- $a1 - calling max()
    # 	- $v0 - function returns, syscalls
    #	- $t0 - temp holding of max() returns before printing
    #
    # Structure:        
    #   max
    #   -> [prologue]
    #       -> body
    #   -> [epilogue]
main__prologue:
	push	$ra

main__body:
	la	$a0, numbers_1
	li	$a1, NUMBERS_1_LEN
	jal	max			# call max(numbers_1, NUMBERS_1_LEN)

	move	$t0, $v0		# $t0 holds max of numbers_1

	li	$v0, PRINT_STRING
	la	$a0, max_num_1_str
	syscall				# printf("Maximum of numbers_1: ")

	li	$v0, PRINT_INT
	move	$a0, $t0
	syscall				# printf("%d", max(numbers_1, NUMBERS_1_LEN))

	li	$v0, PRINT_CHAR
	li	$a0, '\n'
	syscall				# putchar('\n')

	la	$a0, numbers_2
	li	$a1, NUMBERS_2_LEN
	jal	max			# call max(numbers_2, NUMBERS_2_LEN)

	move	$t0, $v0		# $t0 holds max of numbers_2

	li	$v0, PRINT_STRING
	la	$a0, max_num_2_str
	syscall				# printf("Maximum of numbers_2: ")

	li	$v0, PRINT_INT
	move	$a0, $t0
	syscall				# printf("%d", max(numbers_2, NUMBERS_2_LEN))

	li	$v0, PRINT_CHAR
	li	$a0, '\n'
	syscall				# putchar('\n')

main__epilogue:
	pop	$ra

	li	$v0, 0
	jr	$ra		 	# return 0

max:
    # Frame:    [...]   <-- FILL THESE OUT!
    # Uses:     [...]
    # Clobbers: [...]
    #
    # Locals:           <-- FILL THIS OUT!
    #   - ...
    #
    # Structure:        <-- FILL THIS OUT!
    #   max
    #   -> [prologue]
    #       -> body
    #   -> [epilogue]
max__prologue:

max__body:

max__epilogue:
	jr	$ra


	.data
numbers_1:
	.word 0, 1, 2, 3, 456, 7, 8

numbers_2:
	.word -100, -12, -10000

max_num_1_str:
	.asciiz "Maximum of numbers_1: "

max_num_2_str:
	.asciiz "Maximum of numbers_2: "