
#if 1 // bubble sort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int *arr, int length);

int main(void)
{    
    int arr[10] = {24, 13, 8, 125, 77, 59, 35, 41, 45, 11};

    bubble_sort(arr, 10);

    for (int k = 0; k < 10; k++)
    {
        printf("%d ", arr[k]);
    }

    return 0;
}

void bubble_sort(int *arr, int length)
{
    int temp = 0;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {                
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

#endif

//////////////////////////////////////////////////////////////////////

#if 0 // bubble sort

#include <stdio.h>

void swap(int *pa, int *pb);

int main(void)
{
    int arr[10] = {24, 13, 8, 125, 77, 59, 35, 41, 45, 11};
    
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }

    for (int k = 0; k < 10; k++)
    {
        printf("%d ", arr[k]);
    }

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

//////////////////////////////////////////////////////////////////////

#if 0

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
    *t = num1 + num2;
    *av = *t / 2.0;
}

#endif

//////////////////////////////////////////////////////////////////////

#if 0

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