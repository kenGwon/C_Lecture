#if 1
#include <stdio.h>

// A 3.5 SIKWON
int main(void)
{
    char grade[4]; // 학점
    double score; // 평점
    char name[20]; // 이름

    while(1)
    {
        printf("학점 평점 이름(A 3.5 SIKWON): ");
        scanf("%s%lf%s", &grade, &score, name);

        if (grade == "F") break;

        printf("학점: %c\n", grade);
        printf("평점: %.1lf\n", score);
        printf("이름: %s\n", name);
    }

    return 0;
}
#endif

#if 0
#include <stdio.h>
int main(void)
{
    int i;
    printf("%30s\n", "ASCII CODE TABLE\n"); // 총 30bytes를 출력하고 나머지는 space로 채운다.
    printf("%30s\n", "================\n");
    
    for (i=0; i<128; i++)
    {
        if (i % 32 == 0) 
        {
            printf("%10s%10s%10s\n","DEC", "HEX", "OCT", "CHAR"); // 왼쪽 정렬이 아닌 오른쪽 정렬 하고 싶으면
            printf("%10s%10s%10s\n","===", "===", "===", "===="); // %-10s%-10s%-10s라고 입력하면 됨.
        }
        printf("%10d%10.2x%10o%10c\n", i, i, i, i);
    }
    
    return 0;
}
#endif

#if 0
#include <stdio.h>
int main(void)
{
    int i = 108;

    // 100을 decimal로 출력
    printf("decimal i: %d\n", i);
    // 100을 octal로 출력
    printf("octal i: %o\n", i);
    // 100을 hexa로 출력
    printf("hexa i: %0x\n", i);

    // floating point 처리(디폴트는 소숫점 6자리까지임)
    double j = 3.141592;
    // printf("%lf\n", j);
    // printf("%.1lf\n", j);
    // printf("%.2lf\n", j);
    // printf("%.30lf\n", j);
    printf("%lf\n %.1lf\n %.3lf\n %.30lf\n", j,j,j,j);

    char c;
    int ch[2];

    c = 'A'; // ASCII코드 hexa값으로 0x41 // 이진수로 01000001
    // c = "A"; // A\0 // 쌍따옴표로 하면 문자열이기 때문에 자동으로 뒤에 널문자가 들어가서 2바이트가 된다.
    ch[0] = 'A';
    ch[0] = 0x41; 
    ch[0] = 0b01000001;
    ch[1] = '\0'; // 이게 ch = "A"하면 컴파일 나는거에 대한 답이 되겠다.

    printf("c: %c\n", c);
    printf("ch: %s\n", ch);

    return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h> // strlen() strcpy() strcat()
int main(void)
{   
    char c[6] = "abcd";
    // c[0] = 'a' c[1] = 'b' c[2] = 'c' c[3] = 'd' c[4] = 0 (널문자\0) 
    unsigned char uc[] = "abcde";
    // 그냥 uc[]로 선언하면 컴파일러가 초기값 갯수만큼 메모리를 확보함
    // c[0] = 'a' c[1] = 'b' c[2] = 'c' c[3] = 'd' c[4] = 'e' c[5] = 0 (널문자\0) 

    int i[10];
    long l[6];


    // 각 변수가 차지하는 메모리가 총 몇 바이트인지 확인.
    printf("sizeof c:%d\n", sizeof(c));
    printf("sizeof uc:%d\t이게 왜 6바이트인지 헷갈리면 안됨(널문자)\n", sizeof(uc));
    printf("sizeof i:%d\n", sizeof(i));
    printf("sizeof l:%d\n", sizeof(l));

    // 변수에 들어있는 문자열의 수를 확인하기. strlen()은 당연히 마지막\0 빼고 리턴한다.
    printf("c의 문자수: %d\n", strlen(c));

    return 0;
}
#endif

#if 0
#include <stdio.h>
int main(void)
{
    ////////////////////////////////////////////////////////////////////
    // 1바이트 = 8비트 = 4비트씩 끊어서 16진수로 읽을수 있음
    ////////////////////////////////////////////////////////////////////
    // signed char에서 -1에서 0으로 넘어가는 방식은
    // 이진수11111111 + 이진수1 = 이진수 10000000이 되는 것이다.
    ////////////////////////////////////////////////////////////////////
    
    short s; // short: 2byte를 저장하는 메모리 공간
    unsigned short us; // 0~65535 // 0xffff 두 바이트니까 ff(1바이트) ff(1바이트) 
    
    int i; // int: 4byte를 저장하는 메모리 공간 // -0x7fffffff ~ 0x7fffffff
    long l; // long: 4byte // -0x7fffffff ~ 0x7fffffff

    char c; // char: 문자가 아니라 1byte를 저장하는 메모리 공간 -127~127
            // 부호비트 자리도 수 표현으로 변환하여 더 넓은 라운드 사용 0~255
    unsigned char uc1 = 0xff; // 0x : HEXA 16진수
    unsigned char uc2 = 0b11111111; // 0b : Binary 2진수
    unsigned char uc333 = 255; // 10진수
    
    printf("%d\n", uc333);
    printf("%0x\n", uc333);
    // printf("%0b\n", uc333); // %0b는 구현되어 있지 않은 상태이다. 이걸 구현해볼 수 있을까


    // sizeof() - 나중에 실습용으로 MCU를 받았을 때 몇바이트를 잡아먹는지 확인할 때 이게 필요할 것
    printf("char: \t%d\n", sizeof(char));
    printf("unsigned char: \t%d\n", sizeof(unsigned char));
    printf("short: \t%d\n", sizeof(short));
    printf("long: \t%d\n", sizeof(long));
    printf("int: \t%d\n", sizeof(int));
    printf("int: \t%d\n", sizeof("int: \t%d\n"));

    return 0;
}
#endif

#if 0 // 조건부 컴파일
/* 블럭단위 주석문은 "//"이 아니고 이렇게 표기
 1. PROGRAM NAME: test.c
 2. Ver: 1.0
 3. 작성자: ken
 4. 기능: c언어 기본 test program
*/ 
#include <stdio.h>

int main(void) 
{
    printf("hello, ken\n\a");

    return 0; // 에러없이 메인이 끝났으니까 main함수를 종료하고 os로 리턴한다는 것.
}
#endif