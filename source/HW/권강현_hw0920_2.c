
#if 1 // 9-challenge

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(double *pa, double *pb);
void line_up(double *pmax, double *pmid, double *pmin);

int main(void)
{
    char input_buffer[100];
    char *token;

    double max, mid, min;
    int cnt;

    printf("실수 값 3개 입력: ");
    fgets(input_buffer, 100, stdin);
    
    token = strtok(input_buffer, " ");
    max = atof(token);
    token = strtok(NULL, " ");
    mid = atof(token);
    token = strtok(NULL, " ");
    min = atof(token);

    line_up(&max, &mid, &min);
    printf("결과: %.1lf, %.1lf, %.1lf", max, mid, min);

    return 0;
}

void swap(double *pa, double *pb)
{
    double temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void line_up(double *pmax, double *pmid, double *pmin)
{
    if (*pmax < *pmid) swap(pmax, pmid);
    if (*pmax < *pmin) swap(pmax, pmin);
    if (*pmid < *pmin) swap(pmid, pmin);
}

#endif

#if 0 // p.286 9-9

#include <stdio.h>

void swap(int x, int y);

int main(void)
{
    int a = 10, b = 20;

    swap(a, b); // 이 함수 안에 선언된 a,b에는 접근하지 못하는 함수임.. 자기들끼리 안에서 x,y로 바꿀뿐..
    printf("a: %d, b: %d\n", a, b);

    return 0;
} 


void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
} // 그저 x,y라는 복사본이 만들어졌을 뿐이다. 당연히 x, y는 이 함수안에서만 영향을 끼치는 것.
#endif

#if 0 // p.284 9-8

#include <stdio.h>

void swap(void);

int main(void)
{
    int a = 10, b = 20;

    swap(&a, &b);
    printf("a: %d, b: %d\n", a, b);

    return 0;
}


void swap(void)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}
#endif


#if 0 // p.282 9-7

#include <stdio.h>

void swap(int *pa, int *pb);

int main(void)
{
    int a = 10, b = 20;

    swap(&a, &b);
    printf("a: %d, b: %d\n", a, b);

    return 0;
}


void swap(int *pa, int *pb)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}
#endif

#if 0 // p.279 9-6

#include <stdio.h>

int main(void)
{
    double a = 10.4;
    double *p = &a;
    printf("%.3lf\n", *p);
    
    int *pd;
    pd = (int *)p;
    printf("%d\n", *pd);

    return 0;
}
#endif

#if 0 // p.277 9-5

#include <stdio.h>

int main(void)
{
    char ch;
    int in;
    double db;

    char *pch;
    int *pin;
    double *pdb;

    printf("char형 변수의 주소크기: %d\n", sizeof(&ch));
    printf("int형 변수의 주소크기: %d\n", sizeof(&in));
    printf("double형 변수의 주소크기: %d\n", sizeof(&db));
    
    printf("char 포인터의 크기: %d\n", sizeof(pch));
    printf("int 포인터의 크기: %d\n", sizeof(pin));
    printf("double 포인터의 크기: %d\n", sizeof(pdb));
    
    printf("char형 변수의 주소크기: %d\n", sizeof(*pch));
    printf("int형 변수의 주소크기: %d\n", sizeof(*pin));
    printf("double형 변수의 주소크기: %d\n", sizeof(*pdb));
    
    return 0;
}
#endif

#if 0 // p.272 9-4

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;
    const int *pa = &a;

    printf("변수 a값: %d\n", *pa);
    pa = &b;
    printf("변수 b값: %d\n", *pa);
    pa = &a;
    a = 20;
    printf("변수 a값: %d\n", *pa);
    // *pa = 40; // const로 선언하면 이게 안되는거다.

    return 0;
}

#endif

#if 0 // p.269 9-3

#include <stdio.h>

int main(void)
{
    int a = 10, b = 15, total;
    double avg;
    int *pa, *pb;
    int *pt = &total;
    double *pg = &avg;

    pa = &a;
    pb = &b;

    *pt = *pa + *pb;
    *pg = *pt / 2.0;

    printf("두 정수의 값: %d, %d\n", *pa, *pb);
    printf("두 정수의 합: %d\n", *pt);
    printf("두 정수의 평균: %.1lf\n", *pg);
    return 0;
}

#endif

#if 0 // p.266 9-2

#include <stdio.h>

int main(void)
{
    int a;
    int *pa;

    pa = &a;
    *pa = 10;

    printf("포인터로 a값 출력: %d\n", *pa);
    printf("변수명으로 a값 출력: %d\n", a);    

    return 0;
}

#endif

#if 0 // p.264 9-1

#include <stdio.h>

int main(void)
{
    int a;
    double b;
    char c;

    printf("int형 변수의 주소: %u\n", &a);
    printf("double형 변수의 주소: %u\n", &b);
    printf("char형 변수의 주소: %u\n", &c);

    return 0;
}

#endif