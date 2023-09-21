
#if 1 // p.351 12-3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_func(char *output_buffer, char *str1, char *str2);

int main(void)
{
    char str1[80] = "asdfasdasdff";
    char str2[80] = "trertwrt";
    char output_buffer[200];

    // printf("첫번째 문자열 입력: "); // abcdefg
    // fgets(str1, 80, stdin);
    // printf("두번째 문자열 입력: "); // 11122342
    // fgets(str2, 80, stdin);

    merge_func(output_buffer, str1, str2);
    printf("합친 문자열: %s\n", output_buffer);

    return 0;
}

void merge_func(char *output_buffer, char *str1, char *str2)
{
    while (*str1 != '\n') // fgets()로 받은 문자열은 엔터로 입력을 마무리 짓기 때문에 문자열 마지막에 \n\0 이 붙어있다는 것을 잊지 말자.
    {
        *output_buffer++ = *str1++; // 포인터에 증감연산자를 붙여서 while조건에 걸릴 때까지 순회하는 방식은 생각보다 자주 쓰일지도?
    }
    while (*str2 != '\0') 
    {
        *output_buffer++ = *str2++; 
    }

}

#endif

#if 0

#include <stdio.h>

int main(void)
{
    char *dessert = "apple";

    printf("오늘 후식은 %s입니다.\n", dessert);
    dessert = "banana";
    printf("오늘 후식은 %s입니다.\n", dessert);

    printf("%u\n", dessert);
    printf("%u\n", *dessert);

    printf("%c", 98);

    char temp;
    temp = 98 - 0x20;
    // int temp2;
    // temp2 = 98 - 0x20;
    printf("%c", temp);
    // printf("%d", temp2);

    return 0;
}

#endif

#if 0

#include <stdio.h>

int main(void)
{
    double arr[5] = {1.2, 3.5, 7.4, 0.5, 10.0};
    double *pa = arr;
    double *pb = arr + 2;

    printf("pb - pa = %u\n", pb - pa); 

    return 0;
}

#endif

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
        spaceCheck(&i, input_buffer);
        num1 = input_buffer[i];
        i++; // 앞에 숫자 한자리 찾은 만치 뒤로 한칸 밀어줘야함;
        spaceCheck(&i, input_buffer + i);
        num2 = input_buffer[i];

        printf("num1 = %c, num2 = %c\n", num1, num2);
    }
    
    return 0;
}

int spaceCheck(int *pi, char *pbuffer)
{
    char *p = pbuffer; // 주소를 대피시켜놔야 한다.(원본에 피해가 가지 않도록)
    int i = *pi;

    while (*p++ == ' ')
    {
        i++; 
    }
    *pi = i;
}

#endif

#if 0
/*
ABCDEFGHIJKLMNOPQRSTUVWXYZ
BCDEFGHIJKLMNOPQRSTUVWXYZA
CDEFGHIJKLMNOPQRSTUVWXYZAB
DEFGHIJKLMNOPQRSTUVWXYZABC
...
ZABCDEFGHIJKLMNOPQRSTUVWXY
ABCDEFGHIJKLMNOPQRSTUVWXYZ
*/
#include <stdio.h>

void shift_alpha(char *alpha);

int main(void)
{
    char alpha[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; // 27bytes : 26문자 + \0

    printf("\n원본배열 생존? %s\n", alpha);

    shift_alpha(alpha);

    printf("\n원본배열 생존? %s\n", alpha);

    return 0;
}

void shift_alpha(char *alpha)
{
    char *p; // 변하지 않는 메모리상 alpha시작 주솟값을 알고 있어야함.
    char temp;

    for (int i = 0; i < 27; i++)
    {
        p = alpha; // 변하지 않는 메모리상 alpha시작 주솟값을 알고 있어야함.
        printf("%s\n", p);
        temp = *p;

        for (int j = 0; j < 25; j++)
        {
            *p = *(p + 1);
            p++;
        }
        *p = temp;
    }
}

#endif

#if 0 // p.299 10-3

#include <stdio.h>

void test_func(int *arr);

int main(void)
{
    int arr[3] = {10, 20, 30};

    test_func(arr);
    return 0;
}

void test_func(int *arr)
{
    int *pa = arr;
    int i;

    printf("배열의 값: ");
    for (i = 0; i < 3; i++)
    {
        printf("%d ", *pa++); // 이렇게 쓰는게 후위연산자를 제대로 활용하는 것이다.
                              // (연산 우선순위를 보면 *이 ++보다 앞서기 때문에 가능한 것이다! p.144)
        
        // pa++; // 이렇게 쓰는건 후위연산자를 제대로 활용하지 못한것이다.
    }
}

#endif


#if 0 // p.299 10-3

#include <stdio.h>

int main(void)
{
    int ary[3] = {10, 20, 30};
    int *pa = ary;
    int i;

    printf("배열의 값: ");
    for (i = 0; i < 3; i++)
    {
        printf("%d ", *pa);
        pa++; 
    }
    
    return 0;
}

#endif