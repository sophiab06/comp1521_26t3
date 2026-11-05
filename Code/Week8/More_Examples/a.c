#include <stdio.h>
#include <stdint.h>

#define FILE_NAME "24_bit_ints.bin"

int main(void) {

    FILE *file = fopen(FILE_NAME, "w");

    uint32_t num;
    while (scanf("%d", &num) == 1) {
        // store them as little endian on purpose
        fputc(num & 0xff, file);
        fputc((num & 0xff00) >> 8, file);
        fputc((num & 0xff0000) >> 16, file);
        fputc((num & 0xff000000) >> 24, file);
    }

    fclose(file);
    return 0;
}