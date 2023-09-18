#if 0 // 9-challenge
#include <stdio.h>

void swap(double *pa, double *pb);
void line_up(double *pmax, double *pmid, double *pmin);



int main(void)
{
    double max, mid, min;

    printf("실수 값 3개 입력: ");
    scanf("%lf%lf%lf", &max, &mid, &min);

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

#if 0 // 9-9
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

#if 0 // 9-7
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

#if 0 // 9-6
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

#if 0 // 9-5
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