#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint16_t count_leading_zeros(uint64_t x){
    showbit(x);
    x |= (x >> 1);
    showbit(x);
    x |= (x >> 2);
    showbit(x);
    x |= (x >> 4);
    showbit(x);
    x |= (x >> 8);
    showbit(x);
    x |= (x >> 16);
    showbit(x);
    x |= (x >> 32);

    /* count ones (population count) */
    printf("0x5555555555555555:\n");
    showbit(0x5555555555555555);
    x -= ((x >> 1) & 0x5555555555555555 /* Fill this! */ );
    x = ((x >> 2) & 0x3333333333333333) + (x & 0x3333333333333333 /* Fill this! */);
    x = ((x >> 4) + x) & 0x0f0f0f0f0f0f0f0f;
    x += (x >> 8);
    x += (x >> 16);
    x += (x >> 32);

    return (64 - (x & 0x7f));
}

void showbit(uint64_t x){
    printf("0b");
    int show;
    for(int i=64; i>0;i--){
        show = x>>(i-1);
        if(show%2==0) printf("0");
        else printf("1");
    }
    printf("\n");
}

int main()
{
    printf("Hello Problem A 2023 Q1!\n");
    uint64_t input = 16;
    uint16_t output = count_leading_zeros(input);
    printf("result = %d\n", output);
    return 0;
}
