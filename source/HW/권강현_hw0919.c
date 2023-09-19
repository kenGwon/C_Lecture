#if 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func(char operator, int a, int b);

int main(void)
{
    char input_buffer[100];
    char a[100], b[100];
    char operator;

    int operator_index;
    int equl_idex;
    
    int a_i, b_i;
    int result;

    while (1)
    {
        // 변수 초기화 
        for (int k = 0; k < sizeof(input_buffer)/sizeof(input_buffer[0]); k++) {input_buffer[k] = '\0';}
        for (int l = 0; l < sizeof(a)/sizeof(a[0]); l++) {a[l] = '\0'; b[l] = '\0';}
        operator_index = 0;
        equl_idex = 0;

        // 입력
        printf("사칙연산을 입력하세요(1+1=)(종료:999): ");
        fgets(input_buffer, 100, stdin);

        // 종료 입력
        if (strncmp(input_buffer, "999", 3) == 0) break;

        // 첫번째 수, 연산자 탐색
        for (int i = 0; i < sizeof(input_buffer)/sizeof(input_buffer[0]); i++)
        {
            if ((input_buffer[i] >= 0x30 && input_buffer[i] <= 0x39) == 0)
            {
                operator_index = i;
                strncpy(a, input_buffer, operator_index);
                operator = input_buffer[operator_index];
                break;
            }
        }

        // 두번째 수 탐색
        for (int j = operator_index; j < sizeof(input_buffer)/sizeof(input_buffer[0]); j++)
        {
            if (input_buffer[j] == 0x3D)
            {
                equl_idex = j;
                strncpy(b, input_buffer + operator_index + 1, equl_idex - operator_index - 1);
                break;
            }
        }

        // 형변환
        a_i = atoi(a);
        b_i = atoi(b);

        // 사칙연산
        result = func(operator, a_i, b_i);

        // 결과출력
        printf("%d %c %d = %d\n", a_i, operator, b_i, result);
    }

    return 0;
}

int func(char operator, int a, int b)
{
    int result;

    switch (operator)
    {
    case '+':
        result = a + b;
        break;

    case '-':
        result = a - b;
        break;

    case '*':
        result = a * b;
        break;

    case '/':
        result = a / b;
        break;
    
    default:
        break;
    }

    return result;
}

/*
< 실행결과 >

사칙연산을 입력하세요(1+1=)(종료:999): 1234-34=                                                                                                                                                                  사칙연산을 
1234 - 34 = 1200
사칙연산을 입력하세요(1+1=)(종료:999): 3*333=
3 * 333 = 999
사칙연산을 입력하세요(1+1=)(종료:999): 2+4=
2 + 4 = 6
사칙연산을 입력하세요(1+1=)(종료:999): 4444444/1111111=
4444444 / 1111111 = 4
사칙연산을 입력하세요(1+1=)(종료:999): 999
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 

*/
#endif