#if 1 // p.621 19-challenge
/*
 사칙연산 수식을 입력하면 그 결과를 출력하는 프로그램을 작성합니다.
 단, 수식을 입력하는 함수와 사칙연산 함수를 매크로 함수로 작성하세요.
*/
#include <stdio.h>

#define SUM(a, b) ((a) + (b))
#define SUB(a, b) ((a) - (b))
#define MUL(a, b) ((a) * (b))
#define DIV(a, b) ((a) / (b))
#define INPUT_FORMULA(a, op, b) scanf("%d %c %d", &a, &op, &b)

int main(void)
{
    int x, y, result;
    char op;

    while (1)
    {
        printf("수식 입력(종료 Ctrl+Z) : ");
        if(INPUT_FORMULA(x, op, y) < 0) break;

        switch (op)
        {
        case '+':
            result = SUM(x, y);
            break;
        
        case '-':
            result = SUB(x, y);
            break;

        case '*':
            result = MUL(x, y);
            break;

        case '/':
            result = DIV(x, y);
            break;

        default:
            printf("invalild input!\n");
            break;
        }

        printf("%d %c %d = %d\n", x, op, y, result);
    }
    
    return 0;
}

#endif

#if 0 // p.582 18-challenge
/*
 텍스트에서 등록되지 않은 단어를 찾아 새로운 파일에 출력합니다. 
 모든 단어의 길이는 최대 20자, 등록 단어 수는 최대 10개로 제한하며 검출 대상 단어 수에는 제한이 없습니다. 
 다음 실행결과는 b.txt에서 a.txt에 등록되지 않은 단어를 찾아 c.txt에 출력합니다.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fap, *fbp, *fcp;
    char input_buffer[22];
    char file_a_memory[10][22] = {'\0'};
    int i, cnt, flag;

    fap = fopen("source\\HW\\a.txt", "r");
    if (fap == NULL)
    {
        printf("파일을 열지 못했습니다.\n");
        return 1;
    }

    fbp = fopen("source\\HW\\b.txt", "r");
    if (fbp == NULL)
    {
        printf("파일을 열지 못했습니다.\n");
        return 1;
    }

    fcp = fopen("source\\HW\\c.txt", "w");
    if (fcp == NULL)
    {
        printf("파일을 열지 못했습니다.\n");
        return 1;
    }

    rewind(fap);
    i = 0;
    while (1)
    {
        fgets(file_a_memory[i++], sizeof(file_a_memory[0]), fap);
        if (feof(fap)) break;
    }
    cnt = i - 1;

    rewind(fbp);
    rewind(fcp);
    i = 0;
    flag = 0;
    while(1)
    {
        fgets(input_buffer, sizeof(input_buffer), fbp);
        if (feof(fbp)) break;

        for (i = 0; i < cnt; i++)
        {
            if (strcmp(input_buffer, file_a_memory[i]) == 0) flag = 1;
        }
        if (flag == 0) fputs(input_buffer, fcp);
        else flag = 0;
    }

    fclose(fap);
    fclose(fbp);
    fclose(fcp);

    return 0;
}

#endif