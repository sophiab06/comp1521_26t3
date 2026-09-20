# Basic branching statement in MIPS practice!

# Code to translate:
# #define SQUARE_MAX 46340

# int main(void) {
#     int x, y;

#     printf("Enter a number: ");
#     scanf("%d", &x);

#     if (x > SQUARE_MAX) {
#         printf("square too big for 32 bits\n");
#     } else {
#         y = x * x;
#         printf("%d\n", y);
#     }

#     return 0;
# }


# TO DO - add a SQUARE_MAX constant!

	.text
main:
	# TO DO - translate!

	li 	$v0, 0
	jr	$ra					# return 0;

	.data
enter_num_str:
	.asciiz "Enter a number: "

num_too_big_str:
	.asciiz "square too big for 32 bits\n"