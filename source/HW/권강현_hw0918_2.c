
#if 0 // p.180

// hw0918_1과 동일

#endif

#if 1 // p. 179

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char input_buffer[100];
    char age[4], chest[4];
    int age_i, chest_i;

    char size;

    while (1)
    {
        printf("나이와 가슴둘레를 입력하세요(25 95).. (종료:exit).. : ");
        fgets(input_buffer, 100, stdin);

        if (strncmp(input_buffer, "exit", 4) == 0) break;

        strncpy(age, input_buffer, 2);
        strncpy(chest, &input_buffer[3], 2);

        age_i = atoi(age);
        chest_i = atoi(chest);

        if (age_i < 20)
        {
            if (chest_i >= 95) size = 'L';
            else if (chest_i >= 85 && chest_i <95) size = 'M';
            else size = 'S';
        }
        else
        {
            if (chest_i >= 100) size = 'L';
            else if (chest_i >= 90 && chest_i <100) size = 'M';
            else size = 'S';
        }
        
        printf("사이즈는 %c입니다.\n", size);

    }
    return 0;
}
/*
나이와 가슴둘레를 입력하세요(25 95).. (종료:exit).. : 25 95
사이즈는 M입니다.
나이와 가슴둘레를 입력하세요(25 95).. (종료:exit).. : exit
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
*/
#endif

#if 0 // p. 178

#include <stdio.h>

int main(void)
{
    int n;
    printf("정수입력: ");
    scanf("%d", &n);

    switch (n % 3)
    {
    case 0:
        printf("거짓");
        break;
    
    case 1:
    case 2:
        printf("참");
        break;
    
    default:
        break;
    }
    return 0;
}
#endif

#if 0 // p.173 5-6

#include <stdio.h>

int main(void)
{
    int rank = 2, m = 0;

    switch (rank)
    {
    case 1:
        m = 300;
        break;
    
    case 2:
        m = 200;
        break;

    case 3:
        m = 100;
        break;

    default:
        m = 10;
        break;
    }

    printf("m: %d\n", m);

    return 0;
}
#endif

#if 0 // p.171 5-5

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;
    
    if (a < 0)
    {
        if (b > 0)
        {
            printf("ok");
        }
    }
    else
    {
        printf("ok");
    }

    return 0;
}

#endif

#if 0 // p.166

#include <stdio.h>

int main(void)
{
    int a = 20, b = 10;

    if (a > 10)
    {
        if (b >= 0)
        {
            b = 1;
        }
        else
        {
            b = -1;
        }
    }

    printf("a: %d, b: %d\n", a, b);

    return 0;
}
#endif

#if 0 // p.164

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char input_buffer[100];
    char height[6];
    char weight[6];
    
    double height_d, weight_d;

    while (1)
    {
        printf("키와 몸무게를 입력하세요(입력종료:exit): ");
        fgets(input_buffer, 100, stdin);

        if (strncmp(input_buffer, "exit", 4) == 0) break;

        strncpy(height, input_buffer, 5);
        strncpy(weight, input_buffer+6, 4);

        height_d = atof(height);
        weight_d = atof(weight);

        if (height_d >= 187.5 && weight_d < 80) printf("ok\n");
        else printf("cancel\n");    
    }

    return 0;
}
/*
키와 몸무게를 입력하세요(입력종료:exit): 179.5 75.0
cancel
키와 몸무게를 입력하세요(입력종료:exit): exit
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
*/
#endif

#if 0 // p.148

#include <stdio.h>
#define SQUARE(x) x * x

int main(void)
{
    double kg, cm;
    double bmi;
    
    printf("몸무게(kg)와 키(cm) 입력: ");
    scanf("%lf %lf", &kg, &cm);

    bmi = kg / SQUARE(cm);

    if (bmi >=20.0 && bmi < 25.0) printf("표준입니다.\n");
    else printf("체중관리가 필요합니다.\n");

    return 0;
}
/*
몸무게(kg)와 키(cm) 입력: 66 185.6
체중관리가 필요합니다.
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
*/
#endif

#if 0 // p.147

#include <stdio.h>

int main(void)
{
    int hour, min, sec;
    double time = 3.76;

    hour = (int)time;
    time = time - hour;
    min = (int)(time * 60.0);
    time = ((time*100.0) - min)/100;
    sec = (int)(time * 60.0);
    
    printf("3.76시간은 %d시간 %d분 %d초입니다.", hour, min, sec);
    return 0;
}
/*
입장률: 92.9
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
*/
#endif

#if 0 // p.146

#include <stdio.h>

int main(void)
{
    int seats = 70;
    int audience = 65;
    double rate;

    rate = (double)audience / (double)seats;
    printf("입장률: %.1lf\n", rate*100);

    return 0;
}
/*
입장률: 92.9
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
*/
#endif

#if 0 // p.146

#include <stdio.h>

int main(void)
{
    int res ;
    res = (sizeof(short) > sizeof(long));

    if (res == 1) printf("short");
    else printf("long"); 

    return 0;
}
#endif

#if 0 // p.127

#include <stdio.h>

int main(void)
{
    int kor = 3, eng = 5, mat = 4;
    int credits;
    int res;
    
    double kscore = 3.8, escore = 4.4, mscore = 3.9;
    double grade;

    credits = kor + eng + mat;
    grade = (kor + eng + mat) / 3.0;
    res = (credits >= 10) && (grade > 4.0);
    printf("%d\n", res);

    return 0;
}
#endif

#if 0 // p.126

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char input_buffer[100];
    char a[4], b[4];
    int a_i, b_i;
    
    int tot;
    double avg;

    while (1)
    {
        printf("두 과목의 점수: ");
        fgets(input_buffer, 100, stdin);
        if (strncmp(input_buffer, "exit", 4) == 0) break;

        strncpy(a, input_buffer, 2);
        strncpy(b, input_buffer+3, 2);

        a_i = atoi(a);
        a_i = atoi(b);

        tot = a_i + b_i;
        avg = tot / 2.0;

        printf("평균: %.1lf\n", avg);
    }
    
    return 0;
}
/*

*/
#endif

#if 0 // p.125

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char a[4], b[4];
    double a_b, b_b;
    char input_buffer[100];

    while (1)
    {
        printf("두 실수를 입력하시오: ");
        fgets(input_buffer, 100, stdin);

        if(strncmp(input_buffer, "exit", 4) == 0) break;

        strncpy(a, input_buffer, 3);
        strncpy(b, input_buffer+4, 3);

        a_b = atof(a);
        b_b = atof(b);
    
        printf("%.1lf + %.1lf = %.1lf\n", a_b, b_b, a_b + b_b);
        printf("%.1lf - %.1lf = %.1lf\n", a_b, b_b, a_b - b_b);
        printf("%.1lf * %.1lf = %.1lf\n", a_b, b_b, a_b * b_b);
        printf("%.1lf / %.1lf = %.1lf\n", a_b, b_b, a_b / b_b);
    }

    return 0;
}
/*
두 실수를 입력하시오: 4.0 1.2                                                                                                                                                                                                                      4.0 - 1.2
4.0 + 1.2 = 5.2                                                                                                                                                                                                                                    4.0 * 1.2
4.0 - 1.2 = 2.8                                                                                                                                                                                                                                    4.0 / 1.2
4.0 * 1.2 = 4.8                                                                                                                                                                                                                                    두 실수를
4.0 / 1.2 = 3.3
두 실수를 입력하시오: exit
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
*/
#endif

#if 0 // p.120 4-6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char a[4];
    int a_i;
    int result;

    char input_buffer[100];

    while (1)
    {
        printf("숫자를 하나 입력하시오: ");
        fgets(input_buffer, 100, stdin);
        if (strncmp(input_buffer, "exit", 4) == 0) break;

        strcpy(a, input_buffer);
        a_i = atoi(a);

        result = (a_i>10) && (a_i<20);
        printf("(a>10) && (a<20) : %d\n", result);
        result = (a_i>10) || (a_i<20);
        printf("(a>10) || (a<20) : %d\n", result);
        result = !(a_i>=30);
        printf("!(a>=30) : %d\n", result);
    }
    
    return 0;
}
/*
숫자를 하나 입력하시오: 30
(a>10) && (a<20) : 0
(a>10) || (a<20) : 1
!(a>=30) : 0
숫자를 하나 입력하시오: exit
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
*/
#endif

#if 0 // p.118 4-5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char a[4], b[4], c[4];
    int a_i, b_i, c_i;
    int result;

    char input_buffer[100];

    while (1)
    {
        printf("세 숫자를 입력하시오(10 20 30) 종료(exit): ");
        fgets(input_buffer, 100, stdin);

        if (strncmp(input_buffer, "exit", 4) == 0) break;

        strncpy(a, input_buffer, 3);
        strncpy(b, input_buffer+3, 3);
        strncpy(c, input_buffer+6, 3);

        a_i = atoi(a);
        b_i = atoi(b);
        c_i = atoi(c);
        printf("%5d%5d%5d\n\n", a_i, b_i, c_i);

        result = (a_i > b_i);
        printf("a_i > b_i: %d\n", result);
        result = (a_i >= b_i);
        printf("a_i >= b_i: %d\n", result);
        result = (a_i < b_i);
        printf("a_i < b_i: %d\n", result);
        result = (a_i <= b_i);
        printf("a_i <= b_i: %d\n", result);
        result = (a_i <= c_i);
        printf("a_i <= c_i: %d\n", result);
        result = (a_i == b_i);
        printf("a_i == b_i: %d\n", result);
        result = (a_i != c_i);
        printf("a_i != c_i: %d\n", result);
    }
    
    return 0;
}
/*
세 숫자를 입력하시오(10 20 30) 종료(exit): 10 20 10
   10   20   10                                                                                                                                                              
                                                                                                                                                                             
a_i > b_i: 0                                                                                                                                                                 
a_i >= b_i: 0                                                                                                                                                                
a_i < b_i: 1                                                                                                                                                                 
a_i <= b_i: 1                                                                                                                                                                
a_i <= c_i: 1                                                                                                                                                                
a_i == b_i: 0                                                                                                                                                                
a_i != c_i: 0
세 숫자를 입력하시오(10 20 30) 종료(exit): exit
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
*/
#endif

#if 0 // p.117 4-4

#include <stdio.h>

int main(void)
{
    int a = 5, b = 5;
    int pre, post;

    pre = (++a) * 3;
    post = (b++) * 3;

    printf("증감 연산 후 초깃값 a = %d, b = %d\n", a, b);
    printf("전위형: (++a) * 3 = %d, 후위형: post = (b++) * 3 = %d", pre, post);

    return 0;
}
/*
증감 연산 후 초깃값 a = 6, b = 6                                                                                        
전위형: (++a) * 3 = 18, 후위형: post = (b++) * 3 = 15            
*  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요
*/
#endif

#if 0 // p.113 4-1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char a[4], b[4];
    int a_i, b_i;

    char input_buffer[100];

    while (1)
    {
        printf("두 수를 입력(10 20) 종료(exit): ");
        fgets(input_buffer, 100, stdin);

        if (strncmp(input_buffer, "exit", 4) == 0) break;

        strncpy(a, input_buffer, 2);
        strncpy(b, input_buffer+3, 2);

        a_i = atoi(a);
        b_i = atoi(b);

        ++a_i;
        --b_i;
        
        printf("a: %d\n", a_i);
        printf("b: %d\n", b_i);
    }

    return 0;
    /*
    두 수를 입력(10 20) 종료(exit): 10 10
    a: 11
    b: 9
    두 수를 입력(10 20) 종료(exit): exit
    *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
    */
}

#endif

#if 0 // p.114 4-2

#include <stdio.h>

int main(void)
{
    double apple;
    int banana;
    int orange;

    apple = 5.0 / 2.0;
    banana = 5 / 2; 
    orange = 5 % 2;

    printf("apple: %.1lf\n", apple);
    printf("apple: %d\n", banana);
    printf("apple: %d\n", orange);

    return 0;
}
/*
apple: 2.5
apple: 2
apple: 1
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
 */
#endif

#if 0 // p.113 4-1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int sum, sub, mul, inv;
    char a[4], b[4];
    int a_i, b_i;

    char input_buffer[100];

    while (1)
    {
        printf("두 수를 입력(10 20) 종료(exit): ");
        fgets(input_buffer, 100, stdin);

        if (strncmp(input_buffer, "exit", 4) == 0) break;

        strncpy(a, input_buffer, 2);
        strncpy(b, input_buffer+2, 2);

        a_i = atoi(a);
        b_i = atoi(b);
        
        sum = a_i + b_i;
        sub = a_i - b_i;
        mul = a_i * b_i;
        inv = -a_i;
        
        printf("a의 값: %d, b의 값: %d\n", a_i, b_i);
        printf("덧셈: %d\n", sum);
        printf("뺄셈: %d\n", sub);
        printf("곱셈: %d\n", mul);
        printf("a의 음수연산: %d\n", inv);
    }

    return 0;
}

/*
두 수를 입력(10 20) 종료(exit): 10 20
a의 값: 10, b의 값: 2
덧셈: 12
뺄셈: 8
곱셈: 20
a의 음수연산: -10
두 수를 입력(10 20) 종료(exit): exit
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
*/
#endif