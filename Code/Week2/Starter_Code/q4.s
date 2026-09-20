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

	.data
enter_num_str:
	.asciiz "Enter a number: "