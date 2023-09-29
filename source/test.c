#include <stdio.h>

int main(void)
{
    unsigned i;

    i = 10;

    printf("%d\n", i);
    printf("%d\n", sizeof(i));
    printf("%s\n", type(i));

    return 0;
}

