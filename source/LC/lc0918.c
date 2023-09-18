
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


#if 0
#include <stdio.h>
#include <string.h>

/*
[switch ~ case문으로 구현]
 A: Excellent
 B: Good
 C: Normal
 D: Bad
 E: Bad
 F
 exit: 프로그램 종료
*/
int main(void)
{
    char input_buffer[100];
    
    while (1)
    {
        printf("Enter score(A~F) exit: ");
        fgets(input_buffer, 100, stdin);

#if 0
        if (input_buffer[0]=='e' && input_buffer[1]=='x' && input_buffer[2]=='i' && input_buffer[3]=='t') break;
#else     
        if (strncmp(input_buffer, "exit", 4)==0) break; // input_buffer의 앞에서 4개 문자를 비교하여, -1,0,1 셋중 하나 출력
#endif

        switch (input_buffer[0])
        {
            case 'A':
                printf("Excellent\n");
                break;
            
            case 'B':
                printf("Good\n");
                break;
            
            case 'C':
                printf("Normal\n");
                break;

            case 'D':           // 이렇게 케이스 두개 연달아서 적어놓고 아래다가 행동할거 적으면 
            case 'E':           // 44, 45행의 case에 해당할 경우 둘다 46행으로 진입하게 됨.
                printf("Bad\n");
                break;
            
            default:
                break;
        }
    }
    
    return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h> // strcpy, strcat, ...
#include <stdlib.h> // atoi(ascii to int), atof(ascii to float), itoa(int to ascii), ...

// 입력조건: 학점 평점 영어 수학 이름 (A, 3.5, 100, 100, ken)
// 1. 만약에 학점이 F조건이면 프로그램 종료
// 2. 평점이 4.4이상이고, 영어가 95이상이고 수학이 95이상이면, "EXCELLENT A, 4.5, 100, 100, ken" 출력
// 3. 평점이 4.0이상이고, 영어가 90이상이고 수학이 90이상이면, "GOOD A 4.1 90 90 ken" 출력
// 4. 평점이 3.0이상이고, 영어가 85이상이고 수학이 85이상이면, "NORMAL A 3.5 95 85 ken" 출력
int main(void)
{
    char grade;
    char score[4];
    char eng[4];
    char math[4];
    char name[20];
    char in_buffer[100];
    double d_score;
    int i_eng;
    int i_math;

    while (1)
    {
        printf("학점 평점 영어 수학 이름(A 3.5 99 99 ken): ");
        fgets(in_buffer, 100, stdin);
        
        if (in_buffer[0] == 'F') break;
        grade = in_buffer[0];
        strncpy(score, in_buffer+2, 3);
        strncpy(eng, in_buffer+6, 2);
        strncpy(math, in_buffer+9, 2);
        strcpy(name, in_buffer+12);

        d_score = atof(score);
        i_eng = atoi(eng);
        i_math = atoi(math);
        
        if (d_score >= 4.4 && i_eng >= 95 && i_math >= 95)
        {
            printf("EXCELLENT %c %.1lf %d %d %s\n", grade, d_score, i_eng, i_math, name);
        }
        else if (d_score >= 4.0 && i_eng >= 90 && i_math >= 90)
        {
            printf("GOOD %c %.1lf %d %d %s\n", grade, d_score, i_eng, i_math, name);
        }
        else if (d_score >= 3.5 && i_eng >= 85 && i_math >= 85)
        {
            printf("NORMAL %c %.1lf %d %d %s\n", grade, d_score, i_eng, i_math, name);
        }
        else
        {
            printf("%c %.1lf %d %d %s\n", grade, d_score, i_eng, i_math, name);
        }
    }

    return 0;
}
#endif 

#if 0
#include <stdio.h>
#include <string.h> // strcpy, strcat, ...
#include <stdlib.h> // atoi(ascii to int), atof(ascii to float), itoa(int to ascii), ...

int main(void)
{
    char grade; // 학점
    double score; // 평점
    int english_score; // 영어성적
    char name[20]; // 이름
    
    char input_buffer[100]; // 100바이트 버퍼
    char i_score[4]; // 3.4\0
    char i_english_score[6];


    while(1)
    {
        printf("학점 평점 영어성적 이름(A 3.5 900 SIKWON): ");

        fgets(input_buffer, 100, stdin); // stdin == 키보드 입력을 말함(standard input) // stdout == 표준출력(모니터 화면)
        // scanf("%s%lf%s", &grade, &score, name);

        if (input_buffer[0] == 'F') break;

        grade = input_buffer[0]; // input[0]의 내용을 grade에 복사 
        
#if 1
        strncpy(i_score, input_buffer+2, 3);
#else
        i_score[0] = input_buffer[2]; 
        i_score[1] = input_buffer[3];
        i_score[2] = input_buffer[4];
        i_score[3] = '\0';
#endif
        score = atof(i_score); // 키보드를 통해 ascii값으로 들어온 값을 double score에 대입

        strncpy(i_english_score, &input_buffer[6], 3);
        english_score = atoi(i_english_score);

        strcpy(name, input_buffer+9); // 버퍼에서 \0을 만날 때까지(끝까지) 복사함

        printf("학점: %c\n", grade);
        printf("평점: %lf\n", score);
        printf("영어성적: %d\n", english_score);
        printf("이름: %s\n", name);
    }

    return 0;
}
#endif


/*
 1. macro(매크로): 사용자가 작성한 코드를 compiler가 compile시 사용자가 지정한 곳으로 대치 시킨다.(매그로 expension)
                   함수의 기능과 유사하나 함수는 호출에 의해서만 실행되지만 매크로는 전처리기에서 반드시 먼저 실행된다.
                   매크로 사용이유: 코드를 짧게 가독성 좋게 해주며, 잘만 사용하면 동작속도도 빨라질 수 있다.
 2. function(함수): 프로그램에서 자주 쓰는 공통된 기능을 모아놓은 코드. module 또는 subroutine 또는 prosedure라고도 한다. 
                    함수는 call한 뒤 되돌아온다. (stack operation)
*/

# if 0 // 중요한 내용이 꽤 많은 파트

#include <stdio.h>

#define SQUARE(x) ((x) * (x)) // 매크로 등록 함수는 대문자로 선언하는게 코딩 컨벤션
#define CUBE(x) (SQUARE(x) * (x)) 
#define SUN 0 // 여기에 선언된 SUN은 변수처럼 메모리를 차지하는 것이 아니다!!! 컴파일러가 컴파일 단계에서 값으로 대치시켜줄 뿐이다.
#define MON 1

// #define TUE WED THR FRI SAT 2, 3, 4, 5, 7 // 이렇게 다중으로 선언할수는 없음
enum Week {
    TUE=2, WED, THR, FRI, SAT=99
}; // 이렇게만 선언해도 enum에서는 다음 요소에 +1씩 되서 들어가게 된다.

int quad(int n);

int main(void)
{
    auto int num = 2;

    printf("Macro실행: %d의 제곱은: %d\n", num, SQUARE(num));
    printf("Macro실행: %d의 세제곱은: %d\n", num, CUBE(num));
    printf("Macro실행: %d의 네제곱은: %d\n", num, quad(num));
    
    // printf("SUN: %d\n", 0);
    // printf("MON: %d\n", 1);

    printf("SUN: %d\n", SUN);
    printf("MON: %d\n", MON);
    printf("TUE: %3d\nWED: %3d\nTHR: %3d\nFRI: %3d\nSAT: %3d\n", TUE, WED, THR, FRI, SAT);
    
    return 0;
}

int quad(int n)
{
    return CUBE(n) * n;
}

#endif