

#if 0 // p.375 12-13

#include <stdio.h>

char *my_strcpy(char *pd, char *ps);
char *my_strcat(char *pd, char *ps);
int my_strlen(char *ps);
int my_strcmp(char *pa, char *pb);

int main(void)
{
    char str[80] = "strawberry";

    printf("바꾸기 전 문자열: %s\n", str);
    my_strcpy(str, "apple");
    printf("바꾼 후 문자열: %s\n", str);
    printf("다른 문자열 대입: %s\n", my_strcpy(str, "kiwi"));

    return 0;
}

char *my_strcpy(char *pd, char *ps)
{
    char *po = pd;

    while (*ps != '\0')
    {
        *pd = *ps;
        pd++;
        ps++;
    }
    *pd = '\0';

    return po;
}

char *my_strcat(char *pd, char *ps)
{
    char *po = pd;

    while (*pd != '\0')
    {
        pd++;
    }
    while (*ps != '\n')
    {
        *pd = *ps;
        pd++;
        ps++;
    }
    *pd = '\0';

    return po;
}

int my_strlen(char *ps)
{
    int cnt = 0;
    while (*ps != '\0')
    {
        cnt++;
        ps++;
    }
    return cnt;
}

int my_strcmp(char *pa, char *pb)
{
    while ((*pa == *pb) && (*pa != '\0'))
    {
        pa++;
        pb++;
    }

    if (*pa > *pb) return 1;
    else if (*pa < *pb) return -1;
    else return 0;
}

#endif

#if 0 // p.372 12-12

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80] = "pear";
    char str2[80] = "peach";
    
    printf("사전에 나중에 나오는 과일 이름: ");
    
    if (strcmp(str1, str2) > 0)
        printf("%s\n", str1);
    else    
        printf("%s\n", str2);
        
    return 0;
}
#endif

#if 0 // p.371 12-11

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80], str2[80];
    char *resp;

    printf("2개의 과일 이름 입력: ");
    scanf("%s%s", str1, str2);
    if (strlen(str1) > strlen(str2))
        resp = str1;
    else
        resp = str2;

    printf("이름이 긴 과일은: %s", resp);

    
    return 0;
}
#endif

#if 0 // p.369 12-10

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[20] = "straw";

    strcat(str, "berry");
    printf("%s\n", str);
    strncat(str, "piece", 3);
    printf("%s\n", str);
    
    return 0;
}
#endif

#if 0 // p.368 12-9

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[20] = "mango tree";
    strncpy(str, "apple-pie", 5);
    printf("%s\n", str);

    return 0;
}
#endif

#if 0 // p.365 12-8

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[100] = "lovepoem";
    char str2[100] = "happy";
    char *ps1 = "banana";
    char *ps2 = str2;
    
    strcpy(str1, str2);
    printf("%s\n", str1); // happy
    
    strcpy(str1, ps1);
    printf("%s\n", str1); // banana

    strcpy(str1, ps2);
    printf("%s\n", str1); // happy

    strcpy(str1, "banana");
    printf("%s\n", str1); // banana

    return 0;
}
#endif

#if 0 // p.360

#include <stdio.h>

int main(void)
{
    int i = 0;
    char str[20];
    char ch;

    do
    {
        ch = getchar();
        str[i] = ch;
        i++;
    } while (ch != '\n');
    
    str[--i] = '\0';
    
    return 0;
}
#endif

#if 0 // p.359 12-7

#include <stdio.h>

int main(void)
{
    char str[80] = "apple juice";
    char *ps = "banana";

    puts(str);
    fputs(ps, stdout);
    puts("milk");
    
    return 0;
}
#endif

#if 0 // p.357 12-6

#include <stdio.h>

int main(void)
{
    int age;
    char name[20];

    printf("나이 입력: ");
    scanf("%d", &age);

    fgetc(stdin);

    printf("이름 입력: ");
    gets(name);
    printf("나이: %d, 이름: %s\n", age, name);

    return 0;
}
#endif

#if 0 // p.354 12-5

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80];

    printf("공백이 포함된 문자열 입력: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';
    printf("입력한 문자열은 %s입니다.", str);

    return 0;
}
#endif

#if 0 // p.353 12-4

#include <stdio.h>

int main(void)
{
    char str[80];

    printf("공백이 포함된 문자열 입력: ");
    gets(str);
    printf("입력한 문자열은 %s입니다.", str);

    return 0;
}
#endif

#if 0 // p.351 12-3

#include <stdio.h>

int main(void)
{
    char str[80];

    printf("문자열 입력: ");
    scanf("%s", str);
    printf("첫 번째 단어: %s\n", str);
    scanf("%s", str);
    printf("버퍼에 남아 있는 두 번째 단어: %s\n", str);

    return 0;
}
#endif

#if 0 // p.348 12-2

#include <stdio.h>

int main(void)
{
    char *dessert = "apple";

    printf("오늘 후식은 %s입니다.\n", dessert);
    dessert = "banana";
    printf("내일 후식은 %s입니다.\n", dessert);

    return 0;
}
#endif

#if 0 // p.347 12-1

#include <stdio.h>

int main(void)
{
    printf("apple이 저장된 시작 주소 값: %p\n", "apple");
    printf("두 번째 문자의 주소 값: %p\n", "apple", + 1);
    printf("첫번째 문자: %c\n", *"apple");
    printf("두번째 문자: %c\n", *("apple"+1));
    printf("배열로 표현한 세번째 문자: %c\n", "apple"[2]);

    return 0;
}
#endif