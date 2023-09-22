
#if 1 // p.567 18-8

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *ifp, *ofp;
    char str[80];
    char *res;

    ifp = fopen("a.txt", "r");
    if(ifp == NULL)
    {
        printf("입력 파일을 열지 못했씁니다.\n");
        return 1;
    }

    ofp = fopen("b.txt", "w");
    if (ofp == NULL)
    {
        printf("출력 파일을 열지 못했습니다.\n");
        return 1;
    }

    while(1)
    {
        res = fgets(str, sizeof(str), ifp);
        if(res == NULL) break;
        str[strlen(str)-1] = '\0';
        fputs(str, ofp);
        fputs(" ", ofp);
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}

#endif

#if 0 // p.482 16-2

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi; // 동적할당 연결용 포인터
    int i, sum = 0;

    pi = (int *)malloc(sizeof(int) * 5);
    if (pi == NULL)
    {
        printf("메모리가 부족합니다.\n");
        exit(1);
    }

    printf("다섯명의 나이를 입력하세요: ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &pi[i]);
        sum += pi[i];
    }
    printf("다섯명의 평균 나이: %.1lf\n", (sum / 5.0));
    
    free(pi);

    return 0;
}

#endif

#if 0 // p.476 15-challenge

#include <stdio.h>
#include <string.h>

void swap(const char *type, void *pa, void *pb);

int main(void)
{
    int a1, a2;
    double h1, h2;

    printf("첫 번째 사람의 나이와 키 입력: ");
    scanf("%d%lf", &a1, &h1);
    getchar(); // 입력 버퍼를 비워야 엔터입력까지 버퍼에 넣어버리는 scanf의 문제점을 해결 가ㄴ능
    printf("두 번째 사람의 나이와 키 입력: ");
    scanf("%d%lf", &a2, &h2);

    swap("int", &a1, &a2);
    swap("double", &h1, &h2);

    printf("첫 번째 사람의 나이와 키: %d %.1lf\n", a1, h1);
    printf("두 번째 사람의 나이와 키: %d %.1lf\n", a2, h2);
    
    return 0;
}

void swap(const char *type, void *pa, void *pb)
{

    if (strcmp((char*)type, "int") == 0) // const char로 받은거 char로 형변환 해줘야 함
    {
        int temp_i;
        temp_i = *(int*)pa;
        *(int*)pa = *(int*)pb;
        *(int*)pb = temp_i;
    }
    else if (strcmp((char*)type, "double") == 0)
    {
        double temp_d;
        temp_d = *(double*)pa;
        *(double*)pa = *(double*)pb;
        *(double*)pb = temp_d;
    }
    else
    {}
}

// void swap(char *type, void **ppx, void *ppy)
// {
//     if (strcmp(type, "int") == 0)
//     {
//         int *temp;
//         temp = *ppx;
//         *ppx = *ppy;
//         *ppy = temp;
//     }
//     else if (strcmp(*type, "double") == 0)
//     {
//         double *temp;
//         temp = *(double*)ppx;
//         *(double*)ppx = *(double*)ppy;
//         *(double*)ppy = temp;
//     }
//     else {}

// }

/*********************************************************************************
// "이중 포인터"만 활용하고... "void포인터"와 "함수포인터"를 적용하지 못한 코드 

#include <stdio.h>


void int_swap_pointer(int **ppx, int **ppy);
void double_swap_pointer(double **ppx, double **ppy);

int main(void)
{
    int *pa1, *pa2;
    int a1, a2;

    double *ph1, *ph2;
    double h1, h2;

    printf("첫 번째 사람의 나이와 키 입력: ");
    scanf("%d %lf", &a1, &h1);
    printf("두 번째 사람의 나이와 키 입력: ");
    scanf("%d %lf", &a2, &h2);

    pa1 = &a1;
    pa2 = &a2;
    ph1 = &h1;
    ph2 = &h2;
    
    int_swap_pointer(&pa1, &pa2);
    double_swap_pointer(&ph1, &ph2);

    printf("첫 번째 사람의 나이와 키: %d %.1lf\n", *pa1, *ph1);
    printf("두 번째 사람의 나이와 키: %d %.1lf\n", *pa2, *ph2);
    
    return 0;
}

void int_swap_pointer(int **ppx, int **ppy)
{
    int *temp;
    temp = *ppx;
    *ppx = *ppy;
    *ppy = temp;
}

void double_swap_pointer(double **ppx, double **ppy)
{
    double *temp;
    temp = *ppx;
    *ppx = *ppy;
    *ppy = temp;
}
*********************************************************************************/

#endif

#if 0 // p.472 15-9

#include <stdio.h>

int main(void)
{
    int a = 10;
    double b = 3.5;
    void *vp;

    vp =  &a;
    printf("a: %d\n", *vp);

    vp = &b;
    printf("a: %.1lf\n", *(double*)vp);

    return 0;
}

#endif

#if 0 // p.472 15-9

#include <stdio.h>

int main(void)
{
    int a = 10;
    double b = 3.5;
    void *vp;

    vp =  &a;
    printf("a: %d\n", *vp);

    vp = &b;
    printf("a: %.1lf\n", *(double*)vp);

    return 0;
}

#endif

#if 0 // p.469 15-8

#include <stdio.h>

void func(int (*fp)(int, int));
int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);

int main(void)
{
    int select;

    printf("01 두 정수의 합\n");
    printf("02 두 정수의 곱\n");
    printf("03 두 정수 중에서 큰 값 계산\n");
    printf("원하는 연산을 선택하세요: ");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
        func(sum); 
        break;

    case 2:
        func(mul); 
        break;

    case 3:
        func(max); 
        break;

    default:
        break;
    }

    return 0;
}

void func(int (*fp)(int, int))
{
    int a, b;
    int res;

    printf("두 정수의 값을 입력하세요: ");
    scanf("%d%d", &a, &b);
    res = fp(a, b);
    printf("결과값은: %d\n", res);
}

int sum(int a, int b)
{
    return a + b;
}

int mul(int a, int b)
{
    return a * b;
}

int max(int a, int b)
{
    if (a > b) return a;
    else return b;
}

#endif

#if 0 // p.467 15-7

#include <stdio.h>

int sum(int, int);

int main(void)
{    
    int (*pf)(int, int);
    int result;
    int result2;
    int result3;

    pf = sum;

    result = pf(10, 20);
    printf("result: %d\n", result);

    result2 = sum(10, 20);
    printf("result: %d\n", result2);

    result3 = (*sum)(10, 20);
    printf("result: %d\n", result3);

    return 0;
}

int sum(int a, int b)
{
    return a+b;
}

#endif

#if 0 // p.441 14-challenge

#include <stdio.h>

int main(void)
{
    int arr[5][6] = {
        {1, 2, 3, 4 ,5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14 ,15},
        {16, 17, 18, 19, 20}
    };
    
    int i, j;

    for (i=0; i<4; i++)
    {
        for (j=0; j<5; j++)
        {
            arr[i][5] += arr[i][j];
            arr[4][j] += arr[i][j];
            arr[4][5] += arr[i][j];
        }
    }
    
    for (i=0;i<5;i++)
    {
        for (j=0;j<6;j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");

    }

    return 0;
}
/************************************************************************
<실행결과>
    1    2    3    4    5   15
    6    7    8    9   10   40
   11   12   13   14   15   65
   16   17   18   19   20   90
   34   38   42   46   50  210
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
************************************************************************/
#endif

#if 0 // p.435 14-7

#include <stdio.h>

int main(void)
{
    int ary1[4] = {1,2,3,4};
    int ary2[4] = {11,12,13,14};
    int ary3[4] = {21,22,23,24};
    int *pary[3] = {ary1, ary2, ary3};
    int i, j;

    for (i=0;i<3;i++)
    {
        for (j=0;j<5;j++)
        {
            printf("%5d", pary[i][j]);
        }
        printf("\n");

    }


    return 0;
}

#endif

#if 0 // p.432 14-6

#include <stdio.h>

int main(void)
{
    char *pary[5];
    int i;

    pary[0] = "dog";
    pary[1] = "elephant";
    pary[2] = "horse";
    pary[3] = "tiger";
    pary[4] = "lion";

    for (i=0; i<5; i++)
    {
        printf("%s\n", pary[i]);
    }

    return 0;
}

#endif

#if 0 // p.425 14-5

#include <stdio.h>

int main(void)
{
    int score[2][3][4] = {
        {{72,80,95,60}, {68,98,83,90}, {75,72,84,90}},
        {{66,85,90,88}, {95,92,88,95}, {43,72,56,75}}
    };
    
    int i,j,k;
    for (i=0; i<2; i++)
    {
        printf("%d반 점수...\n", i+1);
        for (j=0; j<3; j++)
        {
            for (k=0; k<4; k++)
            {
                printf("%5d", score[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

#endif

#if 0 // p.421 14-3

#include <stdio.h>

int main(void)
{
    char animal[5][20];
    int i;
    int count;

    count = sizeof(animal)/sizeof(animal[0]);
    for (i=0; i<count; i++)
    {
        scanf("%s", animal[i]);
    }

    for (i=0; i<count; i++)
    {
        printf("%s ", animal[i]);
    }

    return 0;
}

#endif

#if 0 // p.416 14-2

#include <stdio.h>

int main(void)
{
    int num[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int i, j;

    for (i=0; i<3; i++)
    {
        for (j=0; j<4; j++)
        {
            printf("%5d", num[i][j]);
        }
        printf("\n");
    }


    return 0;
}

#endif

#if 0 // p.408 13-challenge

#include <stdio.h>

void input_data(int *pa, int *pb);
void swap_data(void);
void print_data(int a, int b);

int a, b; // 전역변수 a, b

int main(void)
{
    input_data(&a, &b); // 전역변수에 정수값 입력
    swap_data(); // 두 변수 교환
    print_data(a, b); // 교환된 변숫값 출력

    return 0;
}

void input_data(int *pa, int *pb)
{
    printf("두 정수 입력: ");
    scanf("%d%d", pa, pb);
    printf("\n");
}

void swap_data(void)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void print_data(int a, int b)
{
    printf("두 정수 입력: %d, %d", a, b);
}
#endif

#if 0 // p.404 13-8

#include <stdio.h>

int* sum(int a, int b); // int형 변수의 "주소"를 반환하는 sum함수 선언

int main(void)
{
    int *resp;

    resp = sum(10, 20); // 반환된 주소를 주소에 저장
    printf("두 정수의 합: %d\n", *resp);

    return 0;
}

int* sum(int a, int b)
{    
    static int res;
    res = a + b;
    return &res;
}

#endif

#if 0 // p.402 13-7

#include <stdio.h>

void add_ten(int *pa);

int main(void)
{
    int a = 10;

    add_ten(&a);
    printf("a: %d\n", a);

    return 0;
}

void add_ten(int *pa)
{
    *pa = *pa + 10;
}

#endif

#if 0 // p.400 13-6

#include <stdio.h>

int add_ten(int a);

int main(void)
{
    int a = 10;

    a = add_ten(a);
    printf("a: %d\n", a);

    return 0;
}

int add_ten(int a)
{
    return a + 10;
}

#endif

#if 0 // p.392 13-4

#include <stdio.h>

void auto_func(void);
void static_func(void);

int main(void)
{
    int i;

    printf("일반 지역 변수(auto)를 사용한 함수...\n");
    for (i=0; i<3; i++)
    {
        auto_func();
    }

    printf("정적 지역 변수(static)를 사용한 함수...\n");
    for (i=0; i<3; i++)
    {
        static_func();
    }

    return 0;
}

void auto_func(void)
{
    auto int a = 0;

    a++;
    printf("%d\n", a);
}

void static_func(void)
{
    static int a = 0;

    a++;
    printf("%d\n", a);
}

#endif

#if 0 // p.389 13-3

#include <stdio.h>

void assign10(void);
void assign20(void);
int a;

int main(void)
{
    printf("함수 호출 전 a값: %d\n", a);

    assign10();
    assign20();

    printf("함수 호출 후 a값: %d\n", a);

    return 0;
}

void assign10(void)
{
    a = 10;
}

void assign20(void)
{
    int a= 20;
}

#endif

#if 0 // p.381 12-challenge

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_str(char *str_a, char *str_b);

int main(void)
{
    char str1[50], str2[50], str3[50];
    char temp[50];


    printf("세 단어 입력: ");
    scanf("%s%s%s", str1, str2, str3);

    if (strcmp(str1, str2) == 1) 
    {
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2, temp);
    }
    if (strcmp(str1, str3) == 1) 
    {
        strcpy(temp, str1);
        strcpy(str1, str3);
        strcpy(str3, temp);
    }
    if (strcmp(str2, str3) == 1) 
    {
        strcpy(temp, str2);
        strcpy(str2, str3);
        strcpy(str3, temp);
    }

    printf("%s, %s, %s", str1, str2, str3);

    return 0;
}

/************************************************************************
<실행결과
세 단어 입력: kiwi banana grape
banana, grape, kiwi
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
************************************************************************/
#endif

#if 0 // p.381

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char input_buffer[100];
    char str[100];
    int cnt = 0;

    printf("단어 입력: ");
    fgets(input_buffer, 100, stdin);
    strcpy(str, input_buffer);
    
    printf("입력한 단어: %s, ", str);
    
    for (int i = 0; i < strlen(str)-1; i++)
    {
        if (cnt > 4) {
            str[i] = '*';
            cnt++;
        }
        else{
            cnt++;
        }

    }
    
    printf("생략한 단어: %s\n", str);

    return 0;
}

#endif

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

#if 0 // p.343 11-challenge

#include <stdio.h>

int main(void)
{
    char ch;
    
    int max = 0;
    int len = 0;

    while (1)
    {
        ch = getchar();
        if (ch == EOF) break;
        len = 0;

        while (ch != '\n')
        {
            len++;
            ch = getchar();
        }
        if (len > max) max = len;
    }
    printf("가장 긴 단어의 길이: %d\n", len);

    return 0;
}
/****************************************************************************
<실행결과>
watermelon
banana
melon
strawberry
^Z
가장 긴 단어의 길이: 10
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
****************************************************************************/
#endif

#if 0 // p.335 11-5

#include <stdio.h>

int main(void)
{
    int res;
    char ch;

    while (1)
    {
        res = scanf("%c", &ch);
        if (res == -1) break;
        printf("%d ", ch);
    }
    
    return 0;
}

#endif

#if 0 // p323 11-1

#include <stdio.h>

int main(void)
{
    char small, cap = 'G';

    if ((cap >= 'A') && (cap < 'Z'))
    {
        small = cap - (0x41 - 0x61);
    }
    printf("대문자: %c %c", cap, '\n');
    printf("소문자: %c ", small);

    return 0;
}

#endif

#if 0 // p.320 10-challenge 

#include <stdio.h>

void input_nums(int *lotto_nums);
void print_nums(int *lotto_nums);

int main(void)
{
    int lotto_nums[6];

    input_nums(lotto_nums);
    print_nums(lotto_nums);
    return 0;
}

void input_nums(int *lotto_nums)
{
    int input;
    int dup;

    for (int i=0; i<6; i++)
    {
        printf("번호 입력 : ");
        scanf("%d", &input);
        dup = 0;

        for (int j=0; j<i; j++)
        {
            if (input == lotto_nums[j]) 
            {
                dup = 1;
                break;
            }
        }

        if (dup == 1)
        {
            printf("같은 번호가 있습니다!\n");
            i--;
        }
        else
        {
            lotto_nums[i] = input;
        }
    }
}

void print_nums(int *lotto_nums)
{
    printf("로또 번호 : ");
    for (int i=0; i<6; i++) printf("%d ", lotto_nums[i]);
    printf("\n");
}

/**************************************************************
<실행 결과>
번호 입력 : 3                                                                                                                                                          번호 입
번호 입력 : 7
번호 입력 : 15
번호 입력 : 3
같은 번호가 있습니다!
번호 입력 : 22
번호 입력 : 40
번호 입력 : 22
같은 번호가 있습니다!
번호 입력 : 13
로또 번호 : 3 7 15 22 40 13                                                                                                                                       
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
***************************************************************/
#endif

#if 0 // p.314 10-7

#include <stdio.h>

void intput_ary(double *pa, int size);
double find_max(double *pa, int size);

int main(void)
{
    double ary[5];
    double max;
    int size = sizeof(ary) / sizeof(ary[0]);

    intput_ary(ary, size);
    max = find_max(ary, size);
    printf("배열의 최댓값: %.4lf", max);

    return 0;
}

void intput_ary(double *pa, int size)
{
    int i;
    printf("%d개의 실수값 입력: ", size);
    for (i=0; i<size; i++)
    {
        // scanf("%lf", pa + i);
        scanf("%lf", &pa[i]);
    }
}

double find_max(double *pa, int size)
{
    double max;
    int i;

    max = pa[0];
    for (i=0; i<size; i++)
    {
        if (pa[i] > max) max = pa[i];
    }
    
    return max;
}

#endif

#if 0 // p.312 10-6

#include <stdio.h>

void print_ary(int *pa, int size);

int main(void)
{
    int ary1[5] = {10,20,30,40,50};
    int ary2[8] = {10,20,30,40,50,60,70};

    print_ary(ary1, sizeof(ary1)/sizeof(ary1[0]));
    printf("\n");
    print_ary(ary2, sizeof(ary2)/sizeof(ary2[0]));

    return 0;
}

void print_ary(int *pa, int size)
{
    int i;
    
    for (i=0; i<size; i++)
    {
        printf("%d ", pa[i]);
    }
}

#endif

#if 0 // p.310 10-5
#include <stdio.h>

void print_ary(int *pa);

int main(void)
{
    int ary[5] ={10,20,30,40,50};
    print_ary(ary);
    return 0;
}

void print_ary(int *pa)
{
    int i;
    for (i=0; i<5; i++)
    {
        printf("%d ", pa[i]);
    }
}

#endif

#if 0 // p.303 10-4

#include <stdio.h>

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *pa = arr;
    int *pb = pa + 3;

    printf("pa : %u\n", pa);
    printf("pb : %u\n", pb);
    pa++;
    printf("pb - pa : %u\n", pb - pa);
    
    printf("앞에 있는 배열 요소의 값 출력: ");
    if (pa < pb) printf("%d\n", *pa);
    else printf("%d\n", *pb);

    return 0;
}

#endif

#if 0 // p.299 10-3

#include <stdio.h>

int main(void)
{
    int arr[3] = {10, 20, 30};
    int *pa = arr;
    int i;

    printf("배열의 값: ");
    for (i = 0; i < 3; i++)
    {
        printf("%d ", *pa);
        pa++;
    }

    return 0; 
}

#endif

#if 0 // p.296 10-2

#include <stdio.h>

int main(void)
{
    int arr[3];
    int *pa = arr;
    int i;

    *pa = 10;
    *(pa + 1) = 20;
    pa[2] = pa[0] + pa[1];

    for (i = 0; i < 3; i++)
    {
        printf("%5d", pa[i]);
    }
    
    return 0;
}


#endif

#if 0 // p.293 10-1

#include <stdio.h>

int main(void)
{
    int arr[3];
    int i;

    *(arr + 0) = 10;
    *(arr + 1) = *(arr + 0) + 10;

    printf("세 번째 배열 요소에 키보드 입력: ");
    scanf("%d", arr + 2);

    for (i = 0; i < 3; i++)
    {
        printf("%5d", *(arr + i));
    }
}

#endif