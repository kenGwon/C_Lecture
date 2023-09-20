
#if 1

#include <stdio.h>

void test_func(int num1, int num2, int *t, double *av);

int main(void)
{
    int a = 150 , b = 15, total;
    double avg;

    test_func(a, b, &total, &avg);

    printf("두 정수의 값: %d, %d\n", a, b);
    printf("두 정수의 합: %d\n", total);
    printf("두 정수의 평균: %.1lf\n", avg);

    return 0;
}

void test_func(int num1, int num2, int *t, double *av)
{
    printf("t의 주소: %u\n", t); // 6422308
    printf("av의 주소: %u\n", av); // 6422296
 
    *t = num1 + num2;
    *av = *t / 2.0;
    // *(int*)6422308 = num1 + num2; // 임베디드에서 많이 사용하게 될 형식!!!(데이터 시트 보고 주소상수 직접 지정)
    // *(double*)6422296 = *t / 2.0; // 임베디드에서 많이 사용하게 될 형식!!!(데이터 시트 보고 주소상수 직접 지정)
}

#endif

#if 0

#include <stdio.h>

void test_func(int *pa);

int main(void)
{
    int a = 10;
    
    printf("a의 주소: %u\n", &a);
    printf("변경 전 a값 출력: %d\n", a);

    test_func(&a);
    printf("변경 후 a값 출력: %d\n", a);

    return 0;
}

void test_func(int *pa)
{
    *pa = 200;
    printf("pa값(a의 주소): %u\n", pa);
    printf("pa자체의 주소: %u\n", &pa);

}

#endif

#if 0 // 내가 혼자 고민한 포인터 spaceCheck

#include <stdio.h>
#include <string.h>

int spaceCheck(int *pi, char *pbuffer);

int main(void)
{
    char input_buffer[100]; 
    char num1, num2;
    int i;

    while (1)
    {
        printf("두 수를 입력하세요(a b)(종료:exit): "); //  1           7
        fgets(input_buffer, 100, stdin);

        if (strncmp(input_buffer, "exit", strlen("exit")) == 0) break;
        
        i = 0;  
        i = spaceCheck(&i, input_buffer);
        num1 = input_buffer[i];
        i++; // 앞에 숫자 한자리 찾은 만치 뒤로 한칸 밀어줘야함;
        i = spaceCheck(&i, input_buffer);
        num2 = input_buffer[i];

        printf("num1 = %c, num2 = %c\n", num1, num2);
    }
    
    return 0;
}

int spaceCheck(int *pi, char *pbuffer)
{
    int result;
    for (int i = *pi; i < 100; i++)
    {
        if (pbuffer[i] != ' ') 
        {
            result = i;
            break;
        }
    }

    return result;
}

#endif

#if 0

#include <stdio.h>
#include <string.h>

char input_buffer[100]; // 전역변수(global variable).
                        // 프로그램이 돌고 있는동안 항상 메모리(RAM)을 차지하고 있게 됨.(항상 read/write가능)
                        // 전역변수를 과도하게 점유하고 있으면 다른 프로그램 동작에 영향을 줌.
                        // 이 짓거리 안할라고 포인터 필요.

int spaceCheck(int i);

int main(void)
{
    char num1, num2;
    int i;
    int *pi;

    while (1)
    {
        printf("1111+11(종료:exit): "); //  1           7
        fgets(input_buffer, 100, stdin);

        if (strncmp(input_buffer, "exit", strlen("exit")) == 0) break;
        
        i = 0;
        i = spaceCheck(i);
        num1 = input_buffer[i];
        i++;
        i = spaceCheck(i);
        num2 = input_buffer[i];

        printf("num1 = %c, num2 = %c\n", num1, num2);
    }
    
    return 0;
}

int spaceCheck(int i)
{
    int temp;

    temp = i;

    for (; temp < 100; temp++)
    {
        if (input_buffer[temp] != '+') break;
    }

    return temp;
}

#endif

#if 0

#include <stdio.h>
#include <string.h>

char input_buffer[100]; // 전역변수(global variable).
                        // 프로그램이 돌고 있는동안 항상 메모리(RAM)을 차지하고 있게 됨.(항상 read/write가능)
                        // 전역변수를 과도하게 점유하고 있으면 다른 프로그램 동작에 영향을 줌.
                        // 이 짓거리 안할라고 포인터 필요.

int spaceCheck(int i);

int main(void)
{
    char num1, num2;
    int i;
    int *pi;

    while (1)
    {
        printf("두 수를 입력하세요(a b)(종료:exit): "); //  1           7
        fgets(input_buffer, 100, stdin);

        if (strncmp(input_buffer, "exit", strlen("exit")) == 0) break;
        
        i = 0;
        i = spaceCheck(i);
        num1 = input_buffer[i];
        i++;
        i = spaceCheck(i);
        num2 = input_buffer[i];

        printf("num1 = %c, num2 = %c\n", num1, num2);
    }
    
    return 0;
}

int spaceCheck(int i)
{
    int temp;

    temp = i;

    for (; temp < 100; temp++)
    {
        if (input_buffer[temp] != ' ') break;
    }

    return temp;
}

#endif

#if 0 // 포인터를 쓰지 않아서 전역변수를 쓰게된 코드

#include <stdio.h>
#include <string.h>

char input_buffer[100]; // 전역변수(global variable).
                        // 프로그램이 돌고 있는동안 항상 메모리(RAM)을 차지하고 있게 됨.(항상 read/write가능)
                        // 전역변수를 과도하게 점유하고 있으면 다른 프로그램 동작에 영향을 줌.
                        // 이 짓거리 안할라고 포인터 필요.

int i;

void spaceCheck(void);

int main(void)
{
    char num1, num2;
    int *pi;

    while (1)
    {
        printf("두 수를 입력하세요(a b)(종료:exit): "); //  1           7
        fgets(input_buffer, 100, stdin);

        if (strncmp(input_buffer, "exit", strlen("exit")) == 0) break;
        
        i = 0;
        spaceCheck();
        num1 = input_buffer[i];
        i++;
        spaceCheck();
        num2 = input_buffer[i];

        printf("num1 = %c, num2 = %c\n", num1, num2);
    }
    


    return 0;
}

void spaceCheck(void)
{
    for (; i < 100; i++)
    {
        if (input_buffer[i] != ' ') break;

    }

    return; // 가독성을 위해서 void형 함수에도 마지막 줄에 return;을 써주는게 좋다.
}

#endif