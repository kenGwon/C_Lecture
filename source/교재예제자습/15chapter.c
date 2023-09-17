
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

#if 0 // p.455 15-5

#include <stdio.h>

int main(void)
{
    int ary[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int (*pa)[4]; // 여기가 이중 포인터가 되는 것이다(원래 배열명은 포인터인데 또 포인터를 씌웠으니까)
    int i, j;

    pa = ary; // pa는 
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pa[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

#endif

#if 0 // p.455 15-4

#include <stdio.h>

int main(void)
{
    int ary[5];

    printf("     ary의 값: %u\t", ary); 
    printf("ary의 주소 값: %u\n", &ary);
    printf("     ary + 1: %u\t", ary + 1);
    printf("    &ary + 1: %u\n", &ary + 1);
    
    return 0;
}

#endif

#if 0 // p.453 15-3

#include <stdio.h>

void print_str(char **pps, int cnt);

int main(void)
{
    char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrel"};
    int count;

    count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
    print_str(ptr_ary, count);
    
    return 0;
}

void print_str(char **pps, int cnt)
{
    int i;
    for (i=0; i<cnt; i++)
    {
        printf("%s\n", pps[i]);
    }
}

#endif

#if 0 // p.450 15-2

#include <stdio.h>

void swap_ptr(char **ppa, char **ppb);

int main(void)
{
    char *pa = "success";
    char *pb = "failure";

    printf("pa -> %s, pb -> %s\n", pa, pb);
    swap_ptr(&pa, &pb);
    printf("pa -> %s, pb -> %s\n", pa, pb);
    
    return 0;
}

void swap_ptr(char **ppa, char **ppb)
{
    char *ptemp;
    ptemp = *ppa;
    *ppa = *ppb;
    *ppb = ptemp;
}

#endif

#if 0 // p.445 15-1

#include <stdio.h>

int main(void)
{
    int a =10;
    int *pi;
    int **ppi;

    pi = &a;
    ppi = &pi;

    // printf 말고 디버거로 값이 어떻게 들어가는지 확인 완료

    return 0;
}

#endif