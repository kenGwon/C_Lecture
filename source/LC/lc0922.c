#if 1 // 이게 switch case문을 쓰지 않은 command driven 코드

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(int x, int y);
void sub(int x, int y);
void mul(int x, int y);
void div_(int x, int y);

int main(void)
{
    char input[100];
    char *input_pointer;
    
    int select;
    int num1, num2;
    int result;
    void (*fp[])(int, int) = {add, sub, mul, div_}; // 함수 포인터 배열
    
    input_pointer = (char *)malloc(100 * sizeof(char));
    sprintf(input_pointer, "%s", "함수 포인터 배열 계산기");
    printf("%s: 시작\n", input_pointer);

    while(1)
    {
        printf("select(0: +. 1:-, 2:*, 3:/, 9:exit) ");
        scanf("%d", &select);

        if(select == 9) break;
        printf("두 수를 입력(num1, num2):");
        scanf("%d%d", &num1, &num2);
        fp[select](num1, num2); // switch case 안쓰고 깔끔하게 한줄로 들어감!!!!!!!!!!!
    }
    
    printf("%s: 종료\n", input_pointer);
    free(input_pointer);
    // printf("%s: 종료\n", input_pointer); // 이미 반환된 메모리에 접근하려고 하기 때문에 오류 발생

    return 0;
}

void add(int x, int y) {printf("%d + %d = %d\n", x, y, x+y);}
void sub(int x, int y) {printf("%d - %d = %d\n", x, y, x-y);}
void mul(int x, int y) {printf("%d * %d = %d\n", x, y, x*y);}
void div_(int x, int y) {printf("%d / %d = %d\n", x, y, x/y);}

#endif

/************************************************************************************/

#if 0 // 이게 switch case문을 쓰지 않은 command driven 코드

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(int x, int y);
void sub(int x, int y);
void mul(int x, int y);
void div_(int x, int y);

int main(void)
{
    char input[100];
    
    int select;
    int num1, num2;
    int result;
    
    void (*fp[])(int, int) = {add, sub, mul, div_}; // 함수 포인터 배열
    
    while(1)
    {
        printf("select(0: +. 1:-, 2:*, 3:/, 9:exit) ");
        scanf("%d", &select);

        if(select == 9) break;
        printf("두 수를 입력(num1, num2):");
        scanf("%d%d", &num1, &num2);
        fp[select](num1, num2); // switch case 안쓰고 깔끔하게 한줄로 들어감!!!!!!!!!!!
    }

    return 0;
}

void add(int x, int y) {printf("%d + %d = %d\n", x, y, x+y);}
void sub(int x, int y) {printf("%d - %d = %d\n", x, y, x-y);}
void mul(int x, int y) {printf("%d * %d = %d\n", x, y, x*y);}
void div_(int x, int y) {printf("%d / %d = %d\n", x, y, x/y);}

#endif

/************************************************************************************/

#if 0 // menu driven 방식의 코드

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func(char x, int a, int b);
void add();
void sub();
void mul();
void div_();

int main(void)
{
    char input[100];
    
    int select;
    int num1, num2;
    int result;
    
    // select(0: +. 1:-, 2:*, 3:/, 9:exit)
    // 두 수를 입력(num1, num2)
    // 출력: num1 + num2 = ??
    while(1)
    {
        printf("select(0: +. 1:-, 2:*, 3:/, 9:exit) ");
        scanf("%d", &select);

        if(select == 9) break;
        printf("두 수를 입력(num1, num2):");
        scanf("%d%d", &num1, &num2);

        switch (select)
        {
            case 0:
                add(num1, num2);
                break;

            case 1:
                sub(num1, num2);
                break;

            case 2:
                mul(num1, num2);
                break;

            case 3:
                div_(num1, num2);
                break;

            default:
                break;
        }

    }

    return 0;
}

void add(int x, int y)
{
    printf("%d + %d = %d\n", x, y, x+y);
}

void sub(int x, int y)
{
    printf("%d - %d = %d\n", x, y, x-y);
}

void mul(int x, int y)
{
    printf("%d * %d = %d\n", x, y, x*y);
}

void div_(int x, int y)
{
    printf("%d / %d = %d\n", x, y, x/y);
}

#endif

/************************************************************************************/

#if 0 // menu driven 방식의 코드
/*
=== MENU ===
1. add
2. sub
3. mul
4. div
9.exit

select: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum 
{
    ADD = 1, SUB, MUL, DIV, EXIT = 9
};

void add();
void sub();
void mul();
void div_();
void print_menu(char **menu);
void select_menu(char *input_buffer, int *exit_bool);

int main(void)
{
    char input_buffer[100];
    char *menu[] = {
        "=== MENU ===\n", "1. add\n", "2. sub\n", 
        "3. mul\n", "4. div\n", "9. exit\n"
    };

    int exit_bool = 0; // 이런 변수를 플래그 변수라고 한다

    while (exit_bool == 0) // while (!exit_bool) 이렇게 쓰는게 좀더 fancy
    {
        print_menu(menu);
        fgets(input_buffer, 100, stdin);
        select_menu(input_buffer, &exit_bool);
    }
    
    printf("프로그램을 종료합니다.\n");

    return 0;
}

void select_menu(char *input_buffer, int *exit_bool)
{
    switch (atoi(input_buffer))
        {
        case ADD:
            add();
            break;

        case SUB:
            sub();
            break;

        case MUL:
            mul();
            break;

        case DIV:
            div_();
            break;

        case EXIT:
            *exit_bool = 1;
            break;
        
        default:
            printf("잘못 선택했습니다!\n");
            break;
        }    
}

void print_menu(char **menu)
{
    int i;

    for (i = 0; i < 6; i++)
    {
        printf("%s", *(menu + i));
    }
    printf("선택하고 싶은 메뉴 숫자를 입력하세요: ");
}

void add()
{
    printf("add 메뉴를 선택했습니다.\n");
}

void sub()
{
    printf("sub 메뉴를 선택했습니다.\n");
}

void mul()
{
    printf("mul 메뉴를 선택했습니다.\n");
}

void div_()
{
    printf("div 메뉴를 선택했습니다.\n");
}
#endif