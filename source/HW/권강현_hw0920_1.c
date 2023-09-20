#if 1

#include <stdio.h>
#include <string.h>

void string_check(char *input_buffer, int *total, int *upper, int *lower);

int main(void)
{
    char input_buffer[100];
    int  total;
    int  upper;
    int  lower;
   
   
    while(1)
    {
        total=upper=lower=0;
        printf("임의의 문자열을 입력(종료: exit): ");
        fgets(input_buffer, 100, stdin);

        if (strncmp(input_buffer, "exit", 4) == 0) break;

        printf("초기data: %s\n", input_buffer);

        for (int i = 0; i < sizeof(input_buffer) / sizeof(input_buffer[0]); i++)
        {
            if (input_buffer[i] == '\0')
            {
                total = i;
                break;
            }
        }

        string_check(input_buffer, &total, &upper, &lower);
        
        // 대문자-->소문자 소문자 --> 대문자  
        printf("변경data: %s\n", input_buffer);    
        printf("총 글자수: %d\n", total);
        printf("대문자 수: %d\n", upper);
        printf("소문자 수: %d\n", lower);        
    }
    return 0;
}

void string_check(char *input_buffer, int *total, int *upper, int *lower)
{  
    for (int i =0; i < *total; i++)
    {
        if (*(input_buffer+i) >= 0x41 && *(input_buffer+i) <= 0x5A)
        {
            *(input_buffer+i) += 0x20;
            *upper += 1;
        }
        else if (*(input_buffer+i) >= 0x61 && *(input_buffer+i) <= 0x7A)
        {
            *(input_buffer+i) -= 0x20;
            *lower += 1;
        }
    }
}

#endif