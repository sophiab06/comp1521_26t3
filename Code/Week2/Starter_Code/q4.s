# Basic MIPS + syscalls question!

# Code to translate:
# int main(void) {
#     int x, y;

#     printf("Enter a number: ");
#     scanf("%d", &x);

#     y = x * x;

#     printf("%d\n", y);

#     return 0;
# }
	
	.text
# TO DO - translate!

# Hint: what's the first basic building block of a program we need to have in MIPS to get
# it to run?
main:
	# reg allocations:
	# int x - $t0
	# int y  - $t1

	li	$v0, 4
	la	$a0, enter_num_str
	syscall

	li	$v0, 5
	syscall
	move	$t0, $v0

	mul	$t1, $t0, $t0

	li	$v0, 1
	move	$a0, $t1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

	li	$v0, 0
	jr	$ra

	.data
enter_num_str:
	.asciiz "Enter a number: "