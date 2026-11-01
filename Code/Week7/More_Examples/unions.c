// Demonstration of a couple of properties of unions, aka
// "variable type" variables which can hold one thing
// at once!! 

#include <stdio.h>

union _all {
   int ival;
   char cval;
   char sval[4];
   float fval;
   unsigned int uval;
};

int main(void) {
    // Demonstration of address accessing of unions
    struct {
        int a;
        float b;
    } x1;
    union {
        int a;
        float b;
    } x2;

    printf("Struct vs union addresses:\n");
    printf("struct_1.a address: %p\n", &(x1.a));
    printf("struct_1.b address: %p\n", &(x1.b));
    printf("union_1.a address: %p\n", &(x2.a));
    printf("union_1.b address: %p\n", &(x2.b));
    printf("\n");

    // Demo of union contents
    // NOTE - MUST REMEMBER THAT SINCE MACHINES ARE LITTLE ENDIAN,
    // THIS IS STORED IN MEMORY AS 0x33 0x32 0x31 0x00
    union _all var;
    var.uval = 0x00313233;

    printf("Value inside the _all type union - 0x00313233 (stored as 0x33 0x32 0x31 0x00 "
    "in memory due to our computers being little-endian!)\n");
    printf("uval in hex (contents as unsigned ints): 0x%x\n", var.uval);
    printf("ival (contents as int): %d\n", var.ival);
    printf("cval (contents as one char): %c\n", var.cval);
    printf("sval (contents as 3 char + '\\0' string): %s\n", var.sval);

    // subnormal - actually v. close to 0 and just not printing well here.
    printf("fval (contents as float): %f\n", var.fval);
    printf("Note: above is subnormal (due to exponent being all 0s), very close but not 0.\n");
    printf("Also, on x86 architecture (like our computers), floats are also stored as little endian, like the ints!\n");
    printf("fval (contents as float, printed in exponential mode): %e\n", var.fval);

    return 0;
}