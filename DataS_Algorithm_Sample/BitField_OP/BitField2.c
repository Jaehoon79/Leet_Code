#include <stdio.h>
#include <inttypes.h>

void set_bit (uint32_t input, int setbit) {
    input |= (0x1 << setbit);
    printf("Set_bit: 0x%x \n", input);
}

void clear_bit (uint32_t input, int clrbit) {
    input &= ~(1U << clrbit);
    printf("Clear_bit: 0x%x \n", input);
}

void toggling_bit (uint32_t input, int rebit) {
    printf("0x%x \n", input^(1U << rebit));
    printf("Toggling_bit: 0x%x \n", input);
}

void reverse_bit (uint32_t input) {
    uint32_t revinput = 0;
    int bitCnt = 0;
    while (bitCnt <= 31)
        revinput = (revinput << 1) | ((input >> bitCnt++) & 0x1);

    printf("Reverse_bit: 0x%x \n", revinput);
}

int main () {
    uint32_t input = 0xFFFF0040;
    uint32_t input2 = 0xF0000001;
    set_bit(input, 2);
    toggling_bit(input, 6);
    clear_bit(input, 6);
    toggling_bit(input, 2);
    reverse_bit(input2);
}