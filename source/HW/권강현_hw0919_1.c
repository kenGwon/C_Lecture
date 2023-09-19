
#if 1 // p.260 8-challenge

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char input_buffer[100];
    int cnt = 0;

    printf("문장 입력: ");
    fgets(input_buffer, 100, stdin);

    for (int i = 0; i < sizeof(input_buffer)/sizeof(input_buffer[0]); i++)
    {
        if (input_buffer[i] == '\0') break;
        if (input_buffer[i] >= 0x41 && input_buffer[i] <= 0x5A)
        {
            input_buffer[i] += 0x20;
            cnt++;
        }
    }

    printf("바뀐 문장: %s\n", input_buffer);
    printf("바뀐 문자 수: %d\n", cnt);

    return 0;
}

/*
<실행 결과>

문장 입력: DON'T Worry, Be Happy~
바뀐 문장: don't worry, be happy~
바뀐 문자 수: 7
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
*/
#endif

#if 0 // p.259

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80], str2[80];
    char temp[80];

    printf("두 문자열 입력: ");
    scanf("%s %s", str1, str2);
    printf("바꾸기 전: %s, %s\n", str1, str2);
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
    printf("바꾼 후: %s, %s\n", str1, str2);

    return 0;
}

#endif

#if 0 // p.244

#include <stdio.h>

int main(void)
{
    int score[5];
    int i;
    int total = 0;
    double avg;
    int count;

    count = sizeof(score)/sizeof(score[0]);

    for (i = 0; i < count; i++)
    {
        scanf("%d", score[i]);
    }

    for (i = 0; i < count; i++)
    {
        total += score[i];
    }
    avg = total / (double)count;

    for (i = 0; i < count; i++)
    {
        printf("%5d", score[i]);
    }
    printf("\n");

    printf("평균: %.1lf\n", avg);

    return 0;
}

#endif

#if 0 // p.234

#include <stdio.h>

int rec_func(int n);

int main(void)
{
    int result = 0;
    int n = 10;
    
    result = rec_func(10);
    printf("%d\n", result);

    return 0; 
}

int rec_func(int n)
{
    if (n > 0) return n + rec_func(n-1);
    else return n;
}

#endif

#if 0 // p.232

#include <stdio.h>

void my_sum(int n);

int main(void)
{
    my_sum(10);
    my_sum(100);

    return 0;
}

void my_sum(int n)
{
    int result = 0;
    for (int i = 0; i < n+1; i++) 
    {
        result += i;
    }
    printf("1부터 %d까지의 합은 %d입니다.\n", n, result);    
}

#endif

#if 0 // p.225

#include <stdio.h>

void print_line(void);

int main(void)
{
    print_line();
    printf("학번         이름          전공          학점\n");
    print_line();

    return 0;
}

void print_line(void)
{
    int i;

    for (i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\n");
}

#endif

#if 0 // p.223

#include <stdio.h>

void print_char(char ch, int count);

int main(void)
{
    print_char('@', 5);

    return 0;
}

void print_char(char ch, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%c", ch);
    }
}

#endif

#if 0 // p.221

#include <stdio.h>

int get_num(void);

int main(void)
{
    int result;

    result = get_num();
    printf("반환값: %d\n", result);

    return 0;
}

int get_num(void)
{
    int num;
    
    printf("양수 입력: ");
    scanf("%d", &num);

    return num;
}

#endif

#if 0 // p.219

#include <stdio.h>

double centi_to_meter(int centi);

int main(void)
{
    double result;

    result = centi_to_meter(187);
    printf("%.2lfm\n", result);

    return 0;
}

double centi_to_meter(int centi)
{
    double result;
    result = (double)centi / 100.0;
    return result;
}

#endif

#if 0 // p.218

#include <stdio.h>

double average(double a, double b);

int main(void)
{
    double res;
    res = average(1.5, 3.4);

    printf("%lf", res);
    return 0;
}

double average(double a, double b)
{
    return (a + b) / 2.0;
}

#endif

#if 0 // p.205

#include <stdio.h>

int main(void)
{
    int prime_number[100];
    int n;
    int valid;
    int cnt;
    
    printf("2 이상의 정수를 입력하세요: ");
    scanf("%d", &n);

    for (int i = 2; i <= n ; i++)
    {
        valid = 0;
        
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0) 
            {
                valid = 1; 
                break;
            }
        }

        if (valid == 0) 
        {
            printf("%5d", i); 
            cnt++;
            if(cnt % 5 == 0) printf("\n");
        }
    }

    return 0;
}

#endif

#if 0 // p.204

#include <stdio.h>

int main(void)
{   
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == j) printf("*");
            else if (i + j == 4) printf("*");
            else printf(" ");
        }
        printf("\n");
    }

    return 0;
}

#endif

#if 0 // p.199 6-5

#include <stdio.h>

int main(void)
{
    int i;
    int sum = 0;

    for (i = 1; i <= 10; i++)
    {
        sum += i;
        if (sum > 30) break;
    }

    printf("누적한 값: %d\n", sum);
    printf("마지막으로 더한 값: %d\n", i);

    return 0;
}

#endif

#if 0 // p.195 6-4

#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

#endif

#if 0 // p.193 

#include <stdio.h>

int main(void)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("$");        
    }

    return 0;
}

#endif

#if 0 // p.189 6-3

#include <stdio.h>

int main(void)
{
    int a = 1;

    do
    {
        a = a * 2;
    } while (a < 10);
    
    printf("a: %d\n", a);
}

#endif

#if 0 // p.187 6-2

#include <stdio.h>

int main(void)
{
    int a = 1;
    int i;

    for (i = 0; i < 3; i++)
    {
        a = a * 2;
    }
    printf("a: %d\n", a);

    return 0;
}

#endif

#if 0 // p.183 6-1

#include <stdio.h>

int main(void)
{
    int a = 1;
    while (a < 10)
    {
        a = a * 2;
    }
    printf("a: %d\n", a);

    return 0;
}

#endif