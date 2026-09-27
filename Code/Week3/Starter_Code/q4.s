# View this code in mipsy-web or using the Mipsy Editor Features debugger's "Memory" tab to see
# where everything is stored in memory!!

	.text
main:
	la   $t0, aa		# a) Address of label aa is loaded into $t0

	lw   $t0, bb		# b) Full contents of bb (666) loaded into $t0

	lb   $t0, bb		# c) Only first byte of bb loaded into 
				# $t0 - loads 0x9A (aka 154) in.

	lw   $t0, aa + 4	# d) Loads in 666 (loads 4 bytes after aa)

	la   $t1, cc
	lw   $t0, ($t1)		# e) Loads in from address in $t1, aka from cc. Loads in 1.

	la   $t1, cc
	lw   $t0, 8($t1)	# f) Loads in from address in $t1 + 8. Loads the number 5.

	li   $t1, 8		# g) The order doesn't much matter - addition is 
	lw   $t0, cc($t1)	# commutative. Also loads the number 5.

	la   $t1, cc
	lw   $t0, 2($t1)	# h) Breaks as the computer only accepts loading in a word
				# (a 4 byte element) starting from an address divisible by 4.

	li	$v0, 0		# return 0;
	jr	$ra
	
	.data
aa:  	.word 42
bb:  	.word 666
cc:  	.word 1
	.word 3
	.word 5
	.word 7