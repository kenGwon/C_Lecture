#if 1 // p.459 15-6

#include <stdio.h>

void print_ary(int (*pa)[4]);

int main(void)
{
    int ary[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    print_ary(ary); // 배열을 인수로 주고 함수 호출

    return 0;
}

void print_ary(int (*pa)[4]) // 매개 변수는 배열 포인터
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pa[i][j]);
        }

        printf("\n");
    }
}

#endif