
#if 1 // p.476 15-challenge

#include <stdio.h>
#include <string.h>

void swap(const char *type, void *pa, void *pb);

int main(void)
{
    int a1, a2;
    double h1, h2;

    printf("첫 번째 사람의 나이와 키 입력: ");
    scanf("%d%lf", &a1, &h1);
    getchar(); // 입력 버퍼를 비워야 엔터입력까지 버퍼에 넣어버리는 scanf의 문제점을 해결 가ㄴ능
    printf("두 번째 사람의 나이와 키 입력: ");
    scanf("%d%lf", &a2, &h2);

    swap("int", &a1, &a2);
    swap("double", &h1, &h2);

    printf("첫 번째 사람의 나이와 키: %d %.1lf\n", a1, h1);
    printf("두 번째 사람의 나이와 키: %d %.1lf\n", a2, h2);
    
    return 0;
}

void swap(const char *type, void *pa, void *pb)
{

    if (strcmp((char*)type, "int") == 0) // const char로 받은거 char로 형변환 해줘야 함
    {
        int temp_i;
        temp_i = *(int*)pa;
        *(int*)pa = *(int*)pb;
        *(int*)pb = temp_i;
    }
    else if (strcmp((char*)type, "double") == 0)
    {
        double temp_d;
        temp_d = *(double*)pa;
        *(double*)pa = *(double*)pb;
        *(double*)pb = temp_d;
    }
    else
    {}
}

// void swap(char *type, void **ppx, void *ppy)
// {
//     if (strcmp(type, "int") == 0)
//     {
//         int *temp;
//         temp = *ppx;
//         *ppx = *ppy;
//         *ppy = temp;
//     }
//     else if (strcmp(*type, "double") == 0)
//     {
//         double *temp;
//         temp = *(double*)ppx;
//         *(double*)ppx = *(double*)ppy;
//         *(double*)ppy = temp;
//     }
//     else {}

// }

/*********************************************************************************
// "이중 포인터"만 활용하고... "void포인터"와 "함수포인터"를 적용하지 못한 코드 

#include <stdio.h>


void int_swap_pointer(int **ppx, int **ppy);
void double_swap_pointer(double **ppx, double **ppy);

int main(void)
{
    int *pa1, *pa2;
    int a1, a2;

    double *ph1, *ph2;
    double h1, h2;

    printf("첫 번째 사람의 나이와 키 입력: ");
    scanf("%d %lf", &a1, &h1);
    printf("두 번째 사람의 나이와 키 입력: ");
    scanf("%d %lf", &a2, &h2);

    pa1 = &a1;
    pa2 = &a2;
    ph1 = &h1;
    ph2 = &h2;
    
    int_swap_pointer(&pa1, &pa2);
    double_swap_pointer(&ph1, &ph2);

    printf("첫 번째 사람의 나이와 키: %d %.1lf\n", *pa1, *ph1);
    printf("두 번째 사람의 나이와 키: %d %.1lf\n", *pa2, *ph2);
    
    return 0;
}

void int_swap_pointer(int **ppx, int **ppy)
{
    int *temp;
    temp = *ppx;
    *ppx = *ppy;
    *ppy = temp;
}

void double_swap_pointer(double **ppx, double **ppy)
{
    double *temp;
    temp = *ppx;
    *ppx = *ppy;
    *ppy = temp;
}
*********************************************************************************/

#endif

#if 0 // p.472 15-9

#include <stdio.h>

int main(void)
{
    int a = 10;
    double b = 3.5;
    void *vp;

    vp =  &a;
    printf("a: %d\n", *vp);

    vp = &b;
    printf("a: %.1lf\n", *(double*)vp);

    return 0;
}

#endif

#if 0 // p.469 15-8

#include <stdio.h>

void func(int (*fp)(int, int));
int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);

int main(void)
{
    int select;

    printf("01 두 정수의 합\n");
    printf("02 두 정수의 곱\n");
    printf("03 두 정수 중에서 큰 값 계산\n");
    printf("원하는 연산을 선택하세요: ");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
        func(sum); 
        break;

    case 2:
        func(mul); 
        break;

    case 3:
        func(max); 
        break;

    default:
        break;
    }

    return 0;
}

void func(int (*fp)(int, int))
{
    int a, b;
    int res;

    printf("두 정수의 값을 입력하세요: ");
    scanf("%d%d", &a, &b);
    res = fp(a, b);
    printf("결과값은: %d\n", res);
}

int sum(int a, int b)
{
    return a + b;
}

int mul(int a, int b)
{
    return a * b;
}

int max(int a, int b)
{
    if (a > b) return a;
    else return b;
}

#endif

#if 0 // p.467 15-7

#include <stdio.h>

int sum(int, int);

int main(void)
{    
    int (*pf)(int, int);
    int result;
    int result2;
    int result3;

    pf = sum;

    result = pf(10, 20);
    printf("result: %d\n", result);

    result2 = sum(10, 20);
    printf("result: %d\n", result2);

    result3 = (*sum)(10, 20);
    printf("result: %d\n", result3);

    return 0;
}

int sum(int a, int b)
{
    return a+b;
}

#endif

#if 0 // p.459 15-6

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