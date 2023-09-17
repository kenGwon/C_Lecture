#if 1 // p.408 13-challenge

#include <stdio.h>

void input_data(int *pa, int *pb);
void swap_data(void);
void print_data(int a, int b);

int a, b; // 전역변수 a, b

int main(void)
{
    input_data(&a, &b); // 전역변수에 정수값 입력
    swap_data(); // 두 변수 교환
    print_data(a, b); // 교환된 변숫값 출력

    return 0;
}

void input_data(int *pa, int *pb)
{
    printf("두 정수 입력: ");
    scanf("%d%d", pa, pb);
    printf("\n");
}

void swap_data(void)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void print_data(int a, int b)
{
    printf("두 정수 입력: %d, %d", a, b);
}
#endif

#if 0 // p.404 13-8

#include <stdio.h>

int* sum(int a, int b); // int형 변수의 "주소"를 반환하는 sum함수 선언

int main(void)
{
    int *resp;

    resp = sum(10, 20); // 반환된 주소를 주소에 저장
    printf("두 정수의 합: %d\n", *resp);

    return 0;
}

int* sum(int a, int b)
{    
    static int res;
    res = a + b;
    return &res;
}

#endif

#if 0 // p.402 13-7

#include <stdio.h>

void add_ten(int *pa);

int main(void)
{
    int a = 10;

    add_ten(&a);
    printf("a: %d\n", a);

    return 0;
}

void add_ten(int *pa)
{
    *pa = *pa + 10;
}

#endif

#if 0 // p.400 13-6

#include <stdio.h>

int add_ten(int a);

int main(void)
{
    int a = 10;

    a = add_ten(a);
    printf("a: %d\n", a);

    return 0;
}

int add_ten(int a)
{
    return a + 10;
}

#endif

#if 0 // p.394 13-5

#include <stdio.h>

int main(void)
{
    int sum = 0;

    for (register int i=0; i<10000;i++)
    {
        sum += 1;
    }

    printf("결과: %d", sum);

    return 0;
}

#endif

#if 0 // p.392 13-4

#include <stdio.h>

void auto_func(void);
void static_func(void);

int main(void)
{
    int i;

    printf("일반 지역 변수(auto)를 사용한 함수...\n");
    for (i=0; i<3; i++)
    {
        auto_func();
    }

    printf("정적 지역 변수(static)를 사용한 함수...\n");
    for (i=0; i<3; i++)
    {
        static_func();
    }

    return 0;
}

void auto_func(void)
{
    auto int a = 0;

    a++;
    printf("%d\n", a);
}

void static_func(void)
{
    static int a = 0;

    a++;
    printf("%d\n", a);
}

#endif

#if 0 // p.389 13-3

#include <stdio.h>

void assign10(void);
void assign20(void);
int a;

int main(void)
{
    printf("함수 호출 전 a값: %d\n", a);

    assign10();
    assign20();

    printf("함수 호출 후 a값: %d\n", a);

    return 0;
}

void assign10(void)
{
    a = 10;
}

void assign20(void)
{
    int a= 20;
}

#endif


#if 0 // p.387 13-2

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;
    
    printf("교환 전 a와 b의 값: %d, %d", a, b);
    {
        int temp;

        temp = a;
        a = b;
        b = temp;
    }
    printf("교환 후 a와 b의 값: %d, %d", a, b);

    return 0;
}

#endif


#if 0 // p.385 13-1

#include <stdio.h>

void assign(void);

int main(void)
{
    auto int a = 0;
    assign();

    printf("main 함수 a: %d\n", a);
    return 0;
}

void assign(void)
{
    int a;

    a = 10;
    printf("assign 함수 a: %d\n", a);
}

#endif
