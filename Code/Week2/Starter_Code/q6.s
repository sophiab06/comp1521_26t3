# More complicated branching practice!

# Code to translate:
# int main(void) {
#     int x;
#     printf("Enter a number: ");
#     scanf("%d", &x);

#     if (x > 100 && x < 1000) {
#         printf("medium\n");
#     } else {
#         printf("small/big\n");
#     }
# }

	.text
main:
	# TO DO - translate!

	li 	$v0, 0
	jr	$ra					# return 0;


	.data
enter_num_str:
	.asciiz "Enter a number: "

num_small_or_big_str:
	.asciiz "small/big\n"

num_medium_str:
	.asciiz "medium\n"