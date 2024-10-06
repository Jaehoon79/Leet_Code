#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define MASK_BIT(m, n)  (((0x1 << m) -1) << n)

typedef union Register {
    uint8_t a;
    uint8_t b;
    uint16_t c;
} Register;

typedef struct sRegister {
    uint32_t a : 8;
    uint32_t b : 8;
    uint32_t c : 16;
}sRegister;

int main () {
    Register r;
    sRegister * sr = (sRegister *)malloc(sizeof(sRegister));
    sRegister tsr;
    uint32_t test = 0xFFFF0804;

    r.a = (test & MASK_BIT(8, 0)) >> 0;
    printf("a = 0x%x \n", r.a);

    r.b = (test % MASK_BIT(8, 8)) >> 8;
    printf("b = 0x%x \n", r.b);

    r.c = (test & MASK_BIT(16, 16)) >> 16;
    printf("b = 0x%x \n", r.c);

    printf("toggle: 0x%x \n", test^(0x1 << 0));

    uint32_t reverse = 0;
    uint32_t test1 = 0xFF00000F;
    for (int i = 0; i < 32; i++) {
        reverse = (reverse << 1) | ((test1 >> i) & 0x1);
    }
    printf("Test: 0x%x, Reverse: 0x%x \n", test, reverse);

    char *nums = "16";
    unsigned int numsi = atoi(nums);
    printf("atoi: 0x%x \n", numsi);
    
    numsi = 100;
    
    sr = (sRegister *)&test;
    printf("sr.a: 0x%x, sr.b: 0x%x, sr.c: 0x%x \n", sr->a, sr->b, sr->c);


    
    return 0;
}