
#if 1 // p.594 19-5

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

#if 0 // p.576 18-11

#include <stdio.h>

int main(void)
{
    FILE *afp, *bfp;
    int num = 10;
    int res;

    afp = fopen("doc\\test_a.txt", "wt"); // wt 로 열었다.
    fprintf(afp, "%d", num); // num의 값을 아스키코드로 변환해 write

    bfp = fopen("doc\\test_b.txt", "wb"); // wb 로 열었다.
    fwrite(&num, sizeof(num), 1, bfp);

    fclose(afp);
    fclose(bfp);

    bfp = fopen("test_b.txt", "rb");
    fread(&res, sizeof(res), 1, bfp);
    printf("%d", res);

    fclose(bfp);
    
    return 0;
}

#endif

#if 0 // p.574 18-10

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int age;
    char name[20];

    fp = fopen("doc\\test.txt", "r");

    fscanf(fp, "%d", &age);
    fgets(name, sizeof(name), fp);

    printf("나이: %d, 이름: %s", age, name);
    fclose(fp);

    return 0;
}

#endif

#if 0 // p.571 18-9

#include <stdio.h>

int main(void)
{
    FILE *ifp, *ofp;
    char name[20];
    int kor, eng, math;
    int total;
    double avg;
    int result;

    ifp = fopen("doc\\testinput.txt","r");
    if (ifp == NULL)
    {
        printf("입출력 파일을 열지 못했습니다.");
        return 1;
    }

    ofp = fopen("doc\\testoutput.txt", "w");
    if (ofp == NULL)
    {
        printf("출력 파일을 열지 못했습니다.");
        return 1;
    }

    while (1)
    {
        result = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);
        if (result == EOF) break;

        total = kor + eng + math;
        avg = total / 3.0;
        fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
    }
    
    fclose(ifp);
    fclose(ofp);

    return 0;
}

#endif