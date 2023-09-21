
#if 1 // 문자열 합치기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_func(char *output_buffer, char *str1, char *str2);

int main(void)
{
    char str1[80];
    char str2[80];
    char output_buffer[200];

    printf("첫번째 문자열 입력: "); // abcdefg
    fgets(str1, 80, stdin);
    printf("두번째 문자열 입력: "); // 11122342
    fgets(str2, 80, stdin);

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if 0 // 포인터로 만드는 spaceCheck

#include <stdio.h>
#include <string.h>

void spaceCheck(int *pi, char *pbuffer);

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
        spaceCheck(&i, input_buffer);
        num2 = input_buffer[i];

        printf("num1 = %c, num2 = %c\n", num1, num2);
    }
    
    return 0;
}

void spaceCheck(int *pi, char *pbuffer)
{
    for (int i = *pi; i < 100; i++)
    {
        if (pbuffer[i] != ' ') 
        {
            *pi = i;
            break;
        }
    }
}

/************************ < 실행결과 > ************************

두 수를 입력하세요(a b)(종료:exit):           7      9
num1 = 7, num2 = 9
두 수를 입력하세요(a b)(종료:exit): exit
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 

**************************************************************/

#endif