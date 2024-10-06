#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct tests {
    uint8_t header : 8;
    uint8_t subheader : 8;
    uint16_t msg;
};

void test(void* msg) {
    struct tests *tmsg = (struct tests *)msg;
    printf("0x%x \n", *(uint32_t *)msg);
    printf("Sizeof Structure: %lu \n", sizeof(struct tests));
    printf("header: 0x%x, subheader: 0x%x, msg: 0x%x \n", (uint8_t *)tmsg->header, (uint8_t *) tmsg->subheader, (uint16_t *)tmsg->msg);
}

int main() {
    struct tests size_st;
    struct tests *msg = (int *)calloc(sizeof(struct tests), 1);
    msg->header = 0x1;
    msg->subheader = 0x11;
    msg->msg = 0x4567;
    test((void *)msg);
    return 0;
}