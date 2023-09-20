
#if 1 // p. 502 16-challenge

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_prime(int *n); // 소수면 1, 아니면 0

int main(void)
{
    int *pi = { 0 }; // 동적 할당 영역 각각을 연결해줄 포인터 
    unsigned n;
    int cnt = 0;

    printf("양수 입력: ");
    scanf("%d", &n);

    pi = (int *)malloc((n-2) * sizeof(int));
    
    if (pi == NULL)
    {
        printf("메모리 부족..\n");
        exit(1);
    }

    for (int i = 2; i < n + 1; i++)
    {
        if (check_prime(&i) == 1) // 소수면
        {
            pi[i-2] = i;            
        }
        else if (check_prime(&i) == 0) // 소수가 아니면
        {
            pi[i-2] = 0x58; // 'X'
        }
    }

    for (int j = 0; j < n-2; j++)
    {
        if (pi[j] == 0x58) printf("%5c ", pi[j]);
        else printf("%5d ", pi[j]);
        
        cnt++; // 줄바꿈 체크
        
        if (cnt % 5 == 0) printf("\n");
    }
    
    free(pi); // 메모리 반환

    return 0;
}

int check_prime(int *n)
{
    int valid;

    for (int i = 2; i <= *n ; i++)
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
    }

    if (valid == 1) return 0; // 소수가 아니면 0
    else return 1; // 소수면 1
}

#endif

#if 0 // p.494 16-5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char **ps);

int main(void)
{
    char input_buffer[100];
    char *str[21] = { 0 }; 
    int i = 0;

    while(i < 20)
    {
        printf("문자열을 입력하세요: ");
        fgets(input_buffer, 100, stdin);

        if (strncmp(input_buffer, "exit", 4) == 0) break;

        str[i] = (char*)malloc(strlen(input_buffer) + 1);
        strcpy(str[i], input_buffer);
        i++;
    }

    print_str(str);

    for (i = 0; str[i] != NULL; i++)
    {
        free(str[i]);
    }

    return 0;
}

void print_str(char **ps)
{
    while (*ps != NULL)
    {
        printf("%s\n", *ps);
        ps++;
    }
}

#endif

#if 0 // p.492 16-4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char temp[80]; // 임시 char 배열
    char *str[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("문자열을 입력하세요: ");
        gets(temp);
        str[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(str[i], temp);
    }

    for (i = 0; i < 3; i++)
    {
        printf("%s\n", str[i]);
    }

    for (i = 0; i < 3; i++)
    {
        free(str[i]);
    }
    
    return 0;
}

#endif

#if 0 // p.484 16-3

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi;
    int size = 5;
    int cnt = 0;

    int num, i;

    pi = (int*)calloc(size, sizeof(int));
    while (1)
    {
        printf("양수만 입력하세요: ");
        scanf("%d", &num);
        if (num <= 0) break;
        ///////////////////////////////////////////////////
        if (cnt == size)
        {
            size += 5; 
            pi = (int*)realloc(pi, size * sizeof(int));
        }
        ///////////////////////////////////////////////////
        pi[cnt++] = num;
    }
    
    for (int i = 0; i < cnt; i++)
    {
        printf("%5d", pi[i]);
    }
    
    free(pi);

    return 0;
}

#endif

#if 0 // p.482 16-2

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi; // 동적할당 연결용 포인터
    int i, sum = 0;

    pi = (int *)malloc(sizeof(int) * 5);
    if (pi == NULL)
    {
        printf("메모리가 부족합니다.\n");
        exit(1);
    }

    printf("다섯명의 나이를 입력하세요: ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &pi[i]);
        sum += pi[i];
    }
    printf("다섯명의 평균 나이: %.1lf\n", (sum / 5.0));
    
    free(pi);

    return 0;
}

#endif

#if 0 // p.479 16-1

#include <stdio.h>
#include <stdlib.h> // malloc

int main(void)
{
    int *pi;
    double *pd;

    pi = (int*)malloc(sizeof(int) * 1);
    if(pi == NULL) // p.481 주의1: malloc()함수의 반환값이 널포인터인지 반드시 확인
    {
        printf("# 메모리가 부족합니다.\n");
        exit(1); // 매개변수 1: EXIT_FAILURE // 0: EXIT_SUCCESS
    }
    pd = (double*)malloc(sizeof(double) * 1);

    *pi = 10;
    *pd = 3.4;

    printf("정수형으로 사용: %d\n", *pi);
    printf("실수형으로 사용: %.1lf\n", *pd);

    free(pi);
    free(pd);

    return 0; // == exit(0);
}

#endif