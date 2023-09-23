
#if 1 // p.599 19-7

#include <stdio.h>

#pragma pack(push, 1) // 바이트 얼라이먼트를 1로 바꿈
typedef struct 
{
    char ch;
    int in;
} Sample1_t;
#pragma pack(pop) // 바꾸기 전의 바이트 얼라이먼트 적용
typedef struct 
{
    char ch;
    int in;
} Sample2_t;

int main(void)
{
    printf("sample1 구조체 크기: %d바이트\n", sizeof(Sample1_t));
    printf("sample2 구조체 크기: %d바이트\n", sizeof(Sample2_t));

    return 0;
}

#endif

#if 0 // p.595 19-6

#include <stdio.h>
#define VER 7
#define BIT16

int main(void)
{
    int max ; 

#if VER > 6
    printf("버전 %d입니다.\n", VER);
#endif

#ifdef BIT16
    max = 32767;
#else
    max = 123456789;
#endif
    
    printf("int형 변수의 최댓값: %d\n", max);

    return 0;
}


#endif

#if 0 // p.594 19-5

#include<stdio.h>
#define PRINT_EXPR(x) printf(#x "= %d\n", x)
#define NAME_CAT(x, y) (x ## y)

int main(void)
{
    int a1, a2;

    NAME_CAT(a, 1) = 10;
    NAME_CAT(a, 2) = 20;
    PRINT_EXPR(a1 + a2);
    PRINT_EXPR(a2 - a1);

    return 0;
}

#endif

#if 0 // p.592 19-4

#include <stdio.h>

void func(void);

int main(void)
{
    printf("컴파일 날짜와 시간: %s, %s\n\n", __DATE__, __TIME__);
    printf("파일명: %s\n", __FILE__);
    printf("함수명: %s\n", __FUNCTION__);
    printf("행번호: %d\n", __LINE__);

#line 100 "macro.c"
    func();
    
    return 0;
}

void func(void)
{
    printf("파일명: %s\n", __FILE__);
    printf("함수명: %s\n", __FUNCTION__);
    printf("행번호: %d\n", __LINE__);
}

#endif

#if 0 // p.590 19-3

#include <stdio.h>
#define SUM(a, b) ((a) + (b))
#define SUB(a, b) ((a) - (b))
#define MUL(a, b) ((a) * (b))

int main(void)
{
    int a= 10, b = 20;
    int x = 30, y = 40;
    int result;

    printf("a + b = %d\n", SUM(a, b));
    printf("x - y = %d\n", SUB(x, y));
    result = 30/(MUL(2, 5));
    printf("result: %d\n", result);
    
    return 0;
}

#endif

#if 0 //p.588 19-2

#include <stdio.h>
#define PI 3.14159
#define LIIMIT 100.0
#define MSG "passed!"
#define ERR_PRINT printf("허용 범위를 버어났습니다!\n")

int main(void)
{
    double radius, area;
    
    printf("반지름을 입력하세요(10 이하): ");
    scanf("%lf", &radius);
    area = PI * radius;
    if(area > LIIMIT) ERR_PRINT;
    else printf("원의 면적: %.1lf (%s)\n", area, MSG);

    return 0;   
}

#endif

#if 0 // p.585 19-1

#include <stdio.h>
#include ".\19student.h"

int main(void)
{
    Student_t a = {315, "홍길동"};

    printf("%d, %s\n", a.num, a.name);

    return 0;
}

#endif