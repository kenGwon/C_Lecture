#if 1
#include <stdio.h>

int main(void)
{
    char* ascii[40] = {"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", 
                        "ACK", "BEL", "BS", "HT", "LF", "VT",
                        "FF", "CR", "SO", "SI", "DLE", "DC1", 
                        "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
                        "CAN", "EM", "SUB", "ESC", "FS", "GS",
                        "RS", "US", "SP"};

    printf("%30s\n", "ASCII CODE TABLE\n"); 
    printf("%30s\n", "================\n");
    
    printf("%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s\n",
            "DEC", "HEX", "OCT", "CHAR",
            "DEC", "HEX", "OCT", "CHAR",
            "DEC", "HEX", "OCT", "CHAR",
            "DEC", "HEX", "OCT", "CHAR"); 
    printf("%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s\n",
            "===", "===", "===", "====",
            "===", "===", "===", "====",
            "===", "===", "===", "====",
            "===", "===", "===", "===="); 

    for (int i=0; i<32; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (i+(j*32) <= 32) printf("%10d%10.2x%10o%10s", i+(j*32), i+(j*32), i+(j*32), ascii[i+(j*32)]);
            else printf("%10d%10.2x%10o%10c", i+(j*32), i+(j*32), i+(j*32), i+(j*32));
        }
        printf("\n");
    }
    
    return 0;
}
#endif

#if 0 // p.55
#include <stdio.h>
int main(void)
{
    printf("Be Happy");
    printf("My friend");
    return 0;
}
#endif

#if 0 // p.57
#include <stdio.h>
int main(void)
{
    printf("Be happy\n");
    printf("1234567890\n");
    printf("My\tfriend\n");
    printf("Good\bd\tchance\n");
    printf("Cow\rW\a\n");

    return 0;
}
#endif

#if 0 // p.60
#include <stdio.h>
int main(void)
{
    printf("%d\n", 10);
    printf("%lf\n", 3.4);
    printf("%.1lf\n", 3.45);
    printf("%.10f\n", 3.4);

    printf("%d과 %d의 합은 %d입니다.\n", 10, 20 , 10 + 20);
    printf("%.1lf - %.1lf = %.1lf\n", 3.4, 1.2, 3.4 - 1.2);
    return 0;
}
#endif

#if 0 // p.63
#include <stdio.h>
int main(void)
{
    printf("%d을 %d로 나누면 %.6lf입니다.", 1, 2, 0.5);
    return 0;
}
#endif

#if 0 // p.66
#include <stdio.h>
int main(void)
{
    printf("%d\n", 12);
    printf("%d\n", 014);
    printf("%d\n", 0xc);
    return 0;
}
#endif

#if 0 // p.68
#include <stdio.h>
int main(void)
{
    printf("%.1lf\n", 1e6);
    printf("%.8lf\n", 3.14e-5);
    printf("%.le\n", 0.0000314);
    printf("%.2le\n", 0.0000314);

    return 0;
}
#endif

#if 0 // p.70
#include <stdio.h>
int main(void)
{
    printf("%c\n", 'A');
    printf("%s\n", "A");
    printf("%c은 %s입니다.\n", '1', "first");

    return 0;
}
#endif

#if 0 // p.78
#include <stdio.h>
int main(void)
{
    printf("학번: %d\n", 32165);
    printf("이름: %s\n", "홍길동");
    printf("학점: %c\n", '상수');

    return 0;
}
#endif

#if 0 // p.81 
#include <stdio.h>
int main(void)
{
    int a;
    int b, c;
    double da;
    char ch;

    a = 10;
    b = a;
    c = a + 20;
    da = 3.5;
    c = 'A';

    printf("변수 a의 값: %d\n", a);
    printf("변수 a의 값: %d\n", b);
    printf("변수 a의 값: %d\n", c);
    printf("변수 a의 값: %.1lf\n", da);
    printf("변수 a의 값: %c\n", ch);

    return 0;
}
#endif

#if 0 // p.85
#include <stdio.h>
int main(void)
{
    char ch1 = 'A';
    char ch2 = 65;

    printf("문자 %c의 아스키 코드 값 : %d\n", ch1, ch2);
    printf("아스키 코드 값이 %d인 문자 : %c\n", ch2, ch1);
    
    return 0;
}
#endif

#if 0 // p.86
#include <stdio.h>
int main(void)
{
    short sh = 32767;
    int in = 2147483647;
    long ln = 2147483647;
    long long lln = 123451234512345;

    printf("short형 변수 출력: %d\n", sh);
    printf("int형 변수 출력: %d\n", in);
    printf("long형 변수 출력: %d\n", ln);
    printf("long long형 변수 출력: %d\n", lln);

    return 0;
}
#endif

#if 0 // p.88
#include <stdio.h>
int main(void)
{
    unsigned int a;

    a = 4294967295;
    printf("%d\n", a);
    a = -1;
    printf("%u\n", a);

    return 0;
}
#endif

#if 0 // p.89
#include <stdio.h>
int main(void)
{
    float ft = 1.234567890123456789;
    double db = 1.234567890123456789;

    printf("float형 변수의 값: %.20f\n", ft);
    printf("double형 변수의 값: %.20f\n", db);

    return 0;
}
#endif

#if 0 // p.93
#include <stdio.h>
#include <string.h>
int main(void)
{

    char fruit[20] = "strawberry";

    printf("%s\n", fruit);
    strcpy(fruit, "banana");
    printf("%s\n", fruit);

    return 0;
}
#endif

#if 0 // p.94
#include <stdio.h>
int main(void)
{
    int income = 0;
    double tax;
    const double tax_rate = 0.12;

    income = 456;
    tax = income * tax_rate;
    printf("세금은 : %.1lf입니다.\n", tax);

    return 0;
}
#endif

#if 0 // p.99
#include <stdio.h>
int main(void)
{
    int a = 0;

    a = a + 1;
    a = a + 2;
    a = a + 3;
    printf("a : %d", a);

    return 0;
}
#endif

#if 0 // p.100
#include <stdio.h>
int main(void)
{
    int kor = 70;
    int eng = 80;
    int mat = 90;
    int tot;

    tot = kor + eng + mat;
    printf("국어: %d, 영어: %d, 수학: %d\n", kor, eng, mat);
    printf("총점: %d", tot);

    return 0;
}
#endif

#if 0 // p.109
#include <stdio.h>
int main(void)
{
    char fruit[20];
    int cnt;

    printf("좋아하는 과일: ");
    scanf("%s", &fruit);
    printf("몇 개: ");
    scanf("%d", &cnt);
    printf("%s를 %d개 드립니다.", fruit, cnt);

    return 0;
}
#endif

#if 0 // p.110
#include <stdio.h>
int main(void)
{
    char ch;

    printf("문자 입력: ");
    scanf("%c", &ch);
    printf("%c문자의 아스키코드 값은 %d입니다.\n", ch, ch);

    return 0;
}
#endif

