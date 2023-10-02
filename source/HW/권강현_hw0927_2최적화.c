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
        unsigned int b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 1, b6 : 1, b7 : 1,
            b8 : 1, b9 : 1, b10 : 1, b11 : 1, b12 : 1, b13 : 1, b14 : 1, b15 : 1,
            b16 : 1, b17 : 1, b18 : 1, b19 : 1, b20 : 1, b21 : 1, b22 : 1, b23 : 1,
            b24 : 1, b25 : 1, b26 : 1, b27 : 1, b28 : 1, b29 : 1, b30 : 1, b31 : 1;
    };
} t_Integer;

void printBinaryBit(t_Integer num);

int main(void)
{
    t_Integer x, y, result;

    while (1)
    {
        printf("비트연산을 수행할 두 개의 정수를 입력하세요. >> ");
        if (scanf("%d %d", &x.iNum, &y.iNum) < 0)
            break; // ctrl + z 입력하면 -1 반환하며 break;

        // x
        printf("%-20d: ", x.iNum);
        printBinaryBit(x);
        printf("\n");

        // y
        printf("%-20d: ", y.iNum);
        printBinaryBit(y);
        printf("\n");

        // x & y
        result.iNum = x.iNum & y.iNum;
        printf("%d & %d = %-10d: ", x.iNum, y.iNum, result.iNum);
        printBinaryBit(result);
        printf("\n");

        // x | y
        result.iNum = x.iNum | y.iNum;
        printf("%d | %d = %-10d: ", x.iNum, y.iNum, result.iNum);
        printBinaryBit(result);
        printf("\n");

        // x ^ y
        result.iNum = x.iNum ^ y.iNum;
        printf("%d ^ %d = %-10d: ", x.iNum, y.iNum, result.iNum);
        printBinaryBit(result);
        printf("\n");

        // x >> y
        result.iNum = x.iNum >> y.iNum;
        printf("%d >> %d = %-10d: ", x.iNum, y.iNum, result.iNum);
        printBinaryBit(result);
        printf("\n");

        // x << y
        result.iNum = x.iNum << y.iNum;
        printf("%d << %d = %-10d: ", x.iNum, y.iNum, result.iNum);
        printBinaryBit(result);
        printf("\n");

        // ~x
        result.iNum = ~x.iNum;
        printf("~%d = %-15d: ", x.iNum, result.iNum);
        printBinaryBit(result);
        printf("\n");

        // ~y
        result.iNum = ~y.iNum;
        printf("~%d = %-15d: ", y.iNum, result.iNum);
        printBinaryBit(result);
        printf("\n");

        // ~x + 1
        result.iNum = ~x.iNum + 1;
        printf("~%d + 1 = %-10d: ", x.iNum, result.iNum);
        printBinaryBit(result);
        printf("\n");

        // ~y + 1
        result.iNum = ~y.iNum + 1;
        printf("~%d + 1 = %-10d: ", y.iNum, result.iNum);
        printBinaryBit(result);
        printf("\n");
    }

    return 0;
}

void printBinaryBit(t_Integer num)
{
    printf("%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d",
           num.b31, num.b30, num.b29, num.b28, num.b27, num.b26, num.b25, num.b24,
           num.b23, num.b22, num.b21, num.b20, num.b19, num.b18, num.b17, num.b16,
           num.b15, num.b14, num.b13, num.b12, num.b11, num.b10, num.b9, num.b8,
           num.b7, num.b6, num.b5, num.b4, num.b3, num.b2, num.b1, num.b0);
}

#endif