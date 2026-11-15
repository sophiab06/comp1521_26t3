// Shows how we can interact with environ both manually
// and using getenv()/setenv()!

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    // Making environ accessible as an external var
    // if we want to index into it
    extern char **environ;

    printf("The first environ element is %s\n",
    environ[0]);

    // getenv()/setenv() do not require
    // us to define environ above!
    printf("The name of the currently logged "
    "in user is %s\n", getenv("USER"));

    // setenv() can both create new environment variables
    // and overwrite old ones!
    // This adds an environment variable named CLASS
    // with the value COMP1521, and sets overwrite to be 0 (true).
    setenv("CLASS", "COMP1521", 1);
    printf("The current class is %s\n", getenv("CLASS"));

    // Fails to overwrite without the overwrite flag!
    setenv("CLASS", "COMP1531", 0);
    printf("Class after attempted overlap: %s\n", getenv("CLASS"));
    
    return 0;
}