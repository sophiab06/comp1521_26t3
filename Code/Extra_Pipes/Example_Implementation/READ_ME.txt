reaasign_with_dup.c spawns a process to recompile print_from_stdin.c, then launches a pipe to redirect print_from_stdin to read from it instead, and feeds it the content of test_words.txt.
