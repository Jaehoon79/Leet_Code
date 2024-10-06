#include <stdio.h>
#include <stdlib.h>

uint32_t set_bit (uint32_t input, int bitpo) {
    return input | (0x1 << bitpo);
}

uint32_t clear_bit (uint32_t input, int bitpo) {
    return input & ~(0x1 << bitpo);
}

uint32_t togg_bit (uint32_t input, int bitpo) {
    return input^(0x1 << bitpo);
}

uint32_t reverse_bit (uint32_t input) {
    uint32_t revinput = 0;
    int bitCnt = 0;

    while (bitCnt <= 31)
        revinput = (revinput << 1) | ((input >> bitCnt++) & 0x1);

    return revinput;
}

int main (){
    uint32_t input1 = 0xFFFF0001;
    uint32_t input2 = 0xFFFF0010;

    printf("set_bit: 0x%x \n", set_bit(input1, 2));
    printf("set_bit: 0x%x \n", clear_bit(input1, 0));
    printf("set_bit: 0x%x \n", reverse_bit(input1));
    printf("set_bit: 0x%x \n", togg_bit(input1, 0));

    return 0;
}