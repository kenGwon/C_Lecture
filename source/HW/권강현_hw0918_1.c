#if 1
#include <stdio.h>
#include <string.h> // strncmp strcpy ...
#include <stdlib.h> // atoi atof atol ioa ftoa ...

/*
    [입력] 계산식 입력(1+1=, 종료: exit)
    [출력] 1+1=2 3-1=2 2*3=6 9/3=3 9%2=1 ...
    
    조건1. 숫자입력 필드에 0~9까지 존재해야 하는데, 다른 문자나 특수문자가 들어가면 
           잘못된 입력이라고 사용자에게 알려주고 다시 입력한다.
           printf("invalid input data: %s", invalid_input);
*/
int main(void)
{
    char input_buffer[100];
    char a[2], b[2];
    
    int i_a, i_b;
    int valid_1, valid_2;
    
    while (1)
    {   
        printf("입력(1+1=, 종료:exit): ");
        fgets(input_buffer, 100, stdin);

        if (strncmp(input_buffer, "exit", 4) == 0) break; 

        strncpy(a, input_buffer, 1);
        strncpy(b, input_buffer+2, 1);

        valid_1 = 0;
        valid_2 = 0;
        if ((a[0]>=0x30 && a[0]<0x40) == 0) valid_1 = 1;
        if ((b[0]>=0x30 && b[0]<0x40) == 0) valid_2 = 1;

        if (valid_1 == 1) printf("invalid input data: %c\n", a[0]);
        if (valid_2 == 1) printf("invalid input data: %c\n", b[0]);
        if (valid_1 == 1 || valid_2 == 1) continue; 
        
        i_a = atoi(a);
        i_b = atoi(b);

        switch (input_buffer[1])
        {
            case '+':
                printf("%d + %d = %d\n", i_a, i_b, i_a + i_b);
                break;
            
            case '-':
                printf("%d - %d = %d\n", i_a, i_b, i_a - i_b);
                break;
            
            case '*':
                printf("%d * %d = %d\n", i_a, i_b, i_a * i_b);
                break;

            case '/':
                printf("%d / %d = %d\n", i_a, i_b, i_a / i_b);
                break;
                
            case '%':
                printf("%d 나머지 %d = %d\n", i_a, i_b, i_a % i_b);
                break;
            
            default:
                break;
        }
    }
    
    return 0;
}
#endif
/*
입력(1+1=, 종료:exit): 2+9=
2 + 9 = 11
입력(1+1=, 종료:exit): 3/t=
invalid input data: t
입력(1+1=, 종료:exit): y*3=
invalid input data: y
입력(1+1=, 종료:exit): t-e=
invalid input data: t
invalid input data: e
입력(1+1=, 종료:exit): 9%2=
9 나머지 2 = 1
입력(1+1=, 종료:exit): exit
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
*/