#include <stdio.h>

void main(void)
{
    long hell = 25, iter, val;

    for (iter = 2; hell % iter != 0 && hell > iter;iter++)
        ;
    printf("%d", iter);
}