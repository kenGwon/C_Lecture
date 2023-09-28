#if 1
/*
 [입력]
 ● 비트연산자를 수행할 두 개의 입력
 [출력]
 ● 입력 받은 두 정수 x, y에서 다음 비트 연상의 결과를 출력
 ■ x, y, x & y, x | y, x ^ y, x >> y, x << y, ~x, ~y, ~x + 1. ~y + 1 등을 출력
 ■ 이진수는 다음과 같이 4자리 출력 후 빈 공간 출력
 
 비트연산을 수행할 두 개의 정수를 입력하세요. >> 387 5
 387:                  0000 0000 0000 0000 0000 0001 1000 0011
 5:                    0000 0000 0000 0000 0000 0000 0000 0101
 387 & 5 = 1:          0000 0000 0000 0000 0000 0000 0000 0001
 387 | 5 = 391:        0000 0000 0000 0000 0000 0001 1000 0111
 387 ^ 5 = 390:        0000 0000 0000 0000 0000 0001 1000 0110
 387 >> 5 = 12:        0000 0000 0000 0000 0000 0000 0000 1100
 387 << 5 = 12384:     0000 0000 0000 0000 0011 0000 0110 0000
 ~387 = -388:          1111 1111 1111 1111 1111 1110 0111 1100
 ~ 5 = -6:             1111 1111 1111 1111 1111 1111 1111 1010
*/
#include <stdio.h>

typedef union Integer // 인텔cpu라서 리틀엔디안 방식으로 작동
{
    int iNum;  
    struct 
    {
        unsigned int b0: 1; unsigned int b1: 1; unsigned int b2: 1; unsigned int b3: 1; 
        unsigned int b4: 1; unsigned int b5: 1; unsigned int b6: 1; unsigned int b7: 1;
        unsigned int b8: 1; unsigned int b9: 1; unsigned int b10: 1; unsigned int b11: 1;
        unsigned int b12: 1; unsigned int b13: 1; unsigned int b14: 1; unsigned int b15: 1;
        unsigned int b16: 1; unsigned int b17: 1; unsigned int b18: 1; unsigned int b19: 1;
        unsigned int b20: 1; unsigned int b21: 1; unsigned int b22: 1; unsigned int b23: 1; 
        unsigned int b24: 1; unsigned int b25: 1; unsigned int b26: 1; unsigned int b27: 1; 
        unsigned int b28: 1; unsigned int b29: 1; unsigned int b30: 1; unsigned int b31: 1;
    };    
} t_Integer;

void printBinaryBit(t_Integer num);

int main(void)
{
    t_Integer x, y, result;

    while (1)
    {
        printf("비트연산을 수행할 두 개의 정수를 입력하세요. >> ");
        if (scanf("%d %d", &x.iNum, &y.iNum) < 0) break; // ctrl + z 입력하면 -1 반환하며 break;

        // x
        printf("%-20d: ", x.iNum); printBinaryBit(x); printf("\n");

        // y
        printf("%-20d: ", y.iNum); printBinaryBit(y); printf("\n");

        // x & y
        result.iNum = x.iNum & y.iNum;
        printf("%d & %d = %-10d: ", x.iNum, y.iNum, result.iNum); printBinaryBit(result); printf("\n");

        // x | y
        result.iNum = x.iNum | y.iNum;
        printf("%d | %d = %-10d: ", x.iNum, y.iNum, result.iNum); printBinaryBit(result); printf("\n");

        // x ^ y
        result.iNum = x.iNum ^ y.iNum;
        printf("%d ^ %d = %-10d: ", x.iNum, y.iNum, result.iNum); printBinaryBit(result); printf("\n");

        // x >> y
        result.iNum = x.iNum >> y.iNum;
        printf("%d >> %d = %-10d: ", x.iNum, y.iNum, result.iNum); printBinaryBit(result); printf("\n");

        // x << y
        result.iNum = x.iNum << y.iNum;
        printf("%d << %d = %-10d: ", x.iNum, y.iNum, result.iNum); printBinaryBit(result); printf("\n");

        // ~x
        result.iNum = ~x.iNum;
        printf("~%d = %-15d: ", x.iNum, result.iNum); printBinaryBit(result); printf("\n");

        // ~y
        result.iNum = ~y.iNum;
        printf("~%d = %-15d: ", y.iNum, result.iNum); printBinaryBit(result); printf("\n");

        // ~x + 1
        result.iNum = ~x.iNum + 1;
        printf("~%d + 1 = %-10d: ", x.iNum, result.iNum); printBinaryBit(result); printf("\n");

        // ~y + 1
        result.iNum = ~y.iNum + 1;
        printf("~%d + 1 = %-10d: ", y.iNum, result.iNum); printBinaryBit(result); printf("\n");
    }
    
    return 0;
}

void printBinaryBit(t_Integer num)
{
    printf("%d", num.b31); printf("%d", num.b30); printf("%d", num.b29); printf("%d", num.b28); printf(" ");
    printf("%d", num.b27); printf("%d", num.b26); printf("%d", num.b25); printf("%d", num.b24); printf(" ");
    printf("%d", num.b23); printf("%d", num.b22); printf("%d", num.b21); printf("%d", num.b20); printf(" ");
    printf("%d", num.b19); printf("%d", num.b18); printf("%d", num.b17); printf("%d", num.b16); printf(" ");
    printf("%d", num.b15); printf("%d", num.b14); printf("%d", num.b13); printf("%d", num.b12); printf(" ");
    printf("%d", num.b11); printf("%d", num.b10); printf("%d", num.b9); printf("%d", num.b8); printf(" ");
    printf("%d", num.b7); printf("%d", num.b6); printf("%d", num.b5); printf("%d", num.b4); printf(" ");
    printf("%d", num.b3); printf("%d", num.b2); printf("%d", num.b1); printf("%d", num.b0); printf(" ");
}

#endif