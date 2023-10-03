#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
float absf(float x)
{
    uint32_t mask = 0x7FFFFFFF;
    union {
        uint32_t i;
        float f;
    } u = {.f = x};
    u.i &= mask;
    return u.f;
}

int main()
{

    printf("Hello world!\n");
    printf("%f", absf(-70.65));
    return 0;
}
