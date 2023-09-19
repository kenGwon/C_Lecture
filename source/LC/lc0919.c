
#if 1

#include <stdio.h>

int sum(int *a, int *b, int *res);

int main(void)
{
    int a = 10, b = 20;
    int result;

    sum(&a, &b, &result);

    printf("result: %d\n", result);    

    return 0;
}

int sum(int *a, int *b, int *res)
{
    *res = *a + *b;
}

#endif

#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_binary(int a);

int main(void)
{
    char input_buffer[100];
    char a[4], b[4];
    int a_i = 0;
    int b_i = 0;

    while (1)
    {
        printf("비트 연산이 가능한 두 정수를 입력하시오: ");

        fgets(input_buffer, 100, stdin);

        if (strncmp(input_buffer, "9999", 4) == 0) break;

        strncpy(a, input_buffer, 2);
        strcpy(b, &input_buffer[3]);

        a_i = atoi(a);
        b_i = atoi(b);

        printf("a & b: %d %x ", a_i & b_i, a_i & b_i);
        print_binary(a_i & b_i); printf("\n");

        printf("a ^ b: %d %x\n", a_i ^ b_i, a_i ^ b_i);
        print_binary(a_i ^ b_i); printf("\n");

        printf("a | b: %d %x\n", a_i | b_i, a_i | b_i);
        print_binary(a_i | b_i); printf("\n");

        printf("~a: %d %x\n", ~a_i, ~a_i);
        print_binary(~a_i); printf("\n");

        printf("a << 1: %d %x\n", a_i << 1, a_i << 1);
        print_binary(a_i << 1); printf("\n");

        printf("a >> 2: %d %x\n", a_i >> 2, a_i >> 2);
        print_binary(a_i >> 2); printf("\n");
    }
    
    return 0;
}

void print_binary(int a)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", a >> i & 1); 
    }
}

#endif

// ASCII "33" ==> 0x33 0x33 ==> 0x3333 ==> 0011001100110011
#if 0 // 비트 쉬프트 연산을 활용하여 16진수를 2진수로 보이게 출력하기

#include <stdio.h>

int main(void)
{
    unsigned char x = 0x33; // char 0x00 ~ 0xff(255) 1바이트

    printf("%d --> %x\n", x, x); 
    // x >> 1 했을때 %d %08x
    printf("x >> 1 --> %d, %80x\n", x >> 1, x >> 1); // %80x : %0x로 헥사값을 출력하는데 8자리 완성해서 출력하라는 뜻
    printf("x >> 2 --> %d, %80x\n", x >> 2, x >> 2);
    printf("x << 2 --> %d, %80x\n", x >> 2, x << 2);


    return 0;
}

#endif

#if 0 // 비트 쉬프트 연산을 활용하여 16진수를 2진수로 보이게 출력하기

#include <stdio.h>

int main(void)
{
    unsigned char x = 0x93; // char 0x00 ~ 0xff(255) 1바이트
    unsigned short us = 0xf2ef; // short 0x0000 ~ 1111111111111111(65535) 2바이트

    for (int i = 7; i >= 0; i--)
    {
        printf("%d", x >> i & 1); 
    }
    printf("\n");

    for (int j = 15; j >= 0; j--)
    {
        printf("%d", us >> j & 1);
    }
    printf("\n");

    return 0;
}

#endif

#if 0

#include <stdio.h>

int main(void)
{
    for (int i = 5; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%s", "*");
        }
        printf("\n");
    }

    for (int i = 1; i < 6; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%s", "*");
        }
        printf("\n");
    }

    return 0;
}

#endif

#if 0

#include <stdio.h>

int main(void)
{
    printf("%-5s\n", "*");
    printf("%-5s\n", "**");
    printf("%-5s\n", "***");
    printf("%-5s\n", "****");
    printf("%-5s\n", "*****");
    printf("%5s\n", "*");
    printf("%5s\n", "**");
    printf("%5s\n", "***");
    printf("%5s\n", "****");
    printf("%5s\n", "*****");

    return 0;
}
#endif

#if 0

#include <stdio.h>

int main(void)
{
    for (int i = 2; i < 10; i++)
    {
        printf("=== %d단 ===\n", i);
        for (int j = 1; j < 10; j++)
        {
            printf("%d * %d = %d\t", i, j, i*j);
            if (j % 3 == 0) printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}

#endif

#if 0

#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 12;

    printf("a & b: %d\n", a & b);
    printf("a ^ b: %d\n", a ^ b);
    printf("a | b: %d\n", a | b);
    printf("~a: %d\n", ~a);
    printf("a << 1: %d\n", a << 1);
    printf("a >> 2: %d\n", a >> 2);

    return 0;
}

#endif

#if 0

#include <stdio.h>

#define MAX(a, b) (a > b) ? a : b

int main(void)
{
    int a = 10, b = 20, res;

    res = (a > b) ? a : b;
    /*
    if (a > b) res = a;
    else res = b;
    */
    printf("큰 값: %d\n", res);
    
    return 0;
}

#endif

#if 0 // modified code

#include <stdio.h>

int main(void)
{
    double a = 20.3, b = 3.3;
    int res;
    res = (int)a / (int)b;
    printf("a = %.1lf, b = %.1lf", a, b);
    printf("a / b의 결과: %d\n", res);

    a = (double)res;
    printf("(int)%.lf의 결과: %d\n", (double)res, (int)a);

    return 0;
}

#else // original code

// #include <stdio.h>

// int main(void)
// {
//     double a = 20.3, b = 3.3;
//     int res;
//     res = (int)a / (int)b;
//     printf("a = %.1lf, b = %.1lf", a, b);
//     printf("a / b의 결과: %d\n", res);
    
//     return 0;
// }

#endif