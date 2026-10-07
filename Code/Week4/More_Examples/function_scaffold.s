# Written by Sophia Budkin (z5687506)
# Annotated skeleton of how to structure a function in MIPS.

some_function:
    # Frame:    [$ra, $s0, $s1]   
    # Uses:     [$ra, $s0, $s1, $t0, $t1, $a0]
    # Clobbers: [$t0, $t1, $a0]
    #
    # Locals:           
    #   - $t0 - scan loop counter, temp calculations
    #	- $t1 - offset calculations
    #	- $a0 - function calling arguments
    # 	- $s0 - int num
    #	- $s1 - int num_2
    #
    # Structure:        
    #   max
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


