#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
/* Return a value in which the order of the bytes in 4-byte arguments is reversed. */
static inline uint32_t end_bswap32(uint32_t __x)
{
    return (__x >> 24) | (__x >> 8 & 0x0000ff00) | (__x << 8 & 0x00ff0000) |
           (__x << 24);
}

/* Host to Big Endian 32-bit */
static inline uint32_t end_htobe32(uint32_t n)
{
    union {
        int i;
        char c;
    } u = {1};
    return u.c ? 0 : 1;
}

/* Host to Little Endian 32-bit */
static inline uint32_t end_htole32(uint32_t n)
{
    union {
        int i;
        char c;
    } u = {1};
    return u.c ? 1 : 0;
}

int main()
{
    uint32_t i = 0x12345678;
    printf("%x\n",i);
    printf("%x\n",end_bswap32(i));


    printf("Hello world!\n");
    return 0;
}
