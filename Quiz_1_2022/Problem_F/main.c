#include <stdio.h>
#include <stdlib.h>

/*
 * Compute (int) f
 * If conversion causes overflow or f is NaN, return 0x80000000
 */
typedef unsigned float_bits;
int float_to_int(float_bits f);

static inline float u2f(unsigned u)
{
    return *(float *) &u;
}

int float_to_int(float_bits f)
{
    const unsigned sign = f >> 31;
    const unsigned exp = f >> 23 & 0xFF; /*F01 Fill Your Code */
    const unsigned frac = f & 0x7FFFFF /*F02 Fill Your Code */;
    const unsigned bias = 0x7F; //127
    int result;
    if (exp < bias) {
        /* the float number is less than 1 */
        result = 0;
    } else if (exp >= 31 + bias) { //int32_t
        /* overflow */
        result = 0x80000000;
    } else {
        /* normal */
        unsigned E = exp - bias;
        unsigned M = frac | 0x800000;
        if (E > 0 /*F03 Fill Your Code */) {
            result = M*(1<<E) /*F04 Fill Your Code */;
        } else {
            /* round to zero */
            result = F05 /* Fill Your Code */;
        }
    }
    return sign ? -result : result;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
