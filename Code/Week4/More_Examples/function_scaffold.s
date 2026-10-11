# Written by Sophia Budkin (z5687506)
# Annotated skeleton of how to structure a function in MIPS.

some_function:
    # Frame:    All registers pushed/popped - usually $ra and $s regs only (example: [$ra, $s0, $s1]) 
    # Uses:     All registers in either "frame" or "clobbers" (example: [$ra, $s0, $s1, $t0, $t1, $a0])
    # Clobbers: All registers whose contents are overwritten without pushing/popping (example: [$t0, $t1, $a0])
    #
    # Locals:         
    # List of all registers with what they were used for explained briefly. Example presented below!  
    #   - $t0 - scan loop counter, temp calculations
    #	- $t1 - offset calculations
    #	- $a0 - function calling arguments
    # 	- $s0 - int num
    #	- $s1 - int num_2
    #
    # Structure:
    # All of the labels in the program indented to show control flow/match the indentation
    # of original code!
    # E.g in the below example we can see that the if statement is outside of the scan loop!
    # some_function
    #   -> [prologue]
    #       -> body
    #	        -> scan_loop
    #               -> init
    #               -> cond
    #               -> body
    #               -> step
    #               -> end
    #           -> if_num_lt_num_2
    #           -> if_num_lt_num_2_rejoin
    #   -> [epilogue]

some_function__prologue:
        # Pushing $ra and any $s registers we want to push
        # because we're gonna overwrite their value goes
        # here!

        # NOTE: "begin" instruction isn't necessary, it's 
        # there for debugging.

        begin
        push	$ra
        push	$s0

some_function__body:
        # Whatever the function does goes here.

some_function__epilogue:
        # Popping any pushed registers happens here. MUST
        # POP IN REVERSE ORDER OF HOW PUSHED!! "end" only
        # necessary if "begin" instruction was at the top,
        # HOWEVER YOU MUST HAVE BOTH!!
        pop	$s0
        pop	$ra
        end

        # Returning also happens here - setting return value
        # may need to happen before popping, if the return value 
        # ends up in an $s register at the end of the function.
        li	$v0, 0
        jr	$ra


