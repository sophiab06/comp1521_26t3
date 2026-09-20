# Written by Sophia Budkin (z5687506)
# Scaffold for how a loop can be set up well in MIPS, strongly referencing the lecture's preferred scaffold!

main:
loop_name: 		# label isn't necessary here, however having empty labels 
	   		# for organisation purposes can be a good idea!

loop_name_init:		# any loop-related initialisations, e.g setting i. Doesn't need sep label!
	li	$t0, 0	# int i = 0

loop_name_cond:				# The condition to be checked - needs a separate label!!
	bge	$t0, 10, loop_name_end	# Need to reverse the while(condition A) - branch only when condition A fails!
					# e.g this is equivalent to while (i < 10)

loop_name_body:				# Doesn't necessarily need separate label but good to have for consistency!
	# whatever happens in the body of the loop

loop_name_step:				# Doesn't necessarily need separate label but good to have for consistency!
	addi	$t0, $t0, 1		# incrementing i
	j	loop_name_cond		# Don't forget to jump back to the condition!!

loop_name_end:				# Outside of the loop - needs separate label so we can jump here!
	li	$v0, 0
	jr	$ra