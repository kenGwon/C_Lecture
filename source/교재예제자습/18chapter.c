
#if 1 // p.576 18-11

#include <stdio.h>

int main(void)
{
    FILE *afp, *bfp;
    int num = 10;
    int res;

    afp = fopen("doc\\test_a.txt", "wt"); // wt 로 열었다.
    fprintf(afp, "%d", num); // num의 값을 아스키코드로 변환해 write

    bfp = fopen("doc\\test_b.txt", "wb"); // wb 로 열었다.
    fwrite(&num, sizeof(num), 1, bfp);

    fclose(afp);
    fclose(bfp);

    bfp = fopen("test_b.txt", "rb");
    fread(&res, sizeof(res), 1, bfp);
    printf("%d", res);

    fclose(bfp);
    
    return 0;
}

#endif

#if 0 // p.574 18-10

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int age;
    char name[20];

    fp = fopen("doc\\test.txt", "r");

    fscanf(fp, "%d", &age);
    fgets(name, sizeof(name), fp);

    printf("나이: %d, 이름: %s", age, name);
    fclose(fp);

    return 0;
}

#endif

#if 0 // p.571 18-9

#include <stdio.h>

int main(void)
{
    FILE *ifp, *ofp;
    char name[20];
    int kor, eng, math;
    int total;
    double avg;
    int result;

    ifp = fopen("doc\\testinput.txt","r");
    if (ifp == NULL)
    {
        printf("입출력 파일을 열지 못했습니다.");
        return 1;
    }

    ofp = fopen("doc\\testoutput.txt", "w");
    if (ofp == NULL)
    {
        printf("출력 파일을 열지 못했습니다.");
        return 1;
    }

    while (1)
    {
        result = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);
        if (result == EOF) break;

        total = kor + eng + math;
        avg = total / 3.0;
        fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
    }
    
    fclose(ifp);
    fclose(ofp);

    return 0;
}

#endif

#if 0 // p.567 18-8

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

#if 0 // p.560 18-7

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    char str[20];

    fp = fopen("doc\\test.txt", "a+"); // 처음에 파일을 열어줄때 어떻게 열어주느냐에 따라 아래에서 할수 있는게 생기고 할수 없는게 생긴다.
    if (fp == NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    while (1)
    {
        printf("과일 이름: ");
        scanf("%s", str);
        
        if(strcmp(str, "end") == 0) break;
        else if (strcmp(str, "list") == 0) 
        {
            fseek(fp, 0, SEEK_SET);
            while (1)
            {
                fgets(str, sizeof(str), fp);
                if (feof(fp)) break;
                printf("%s", str);
            }
        }
        else
        {
            fprintf(fp, "%s\n", str);
        }
    }
    fclose(fp);

    return 0;
}

#endif

#if 0 // p.558 18-6

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int arr[10] = {13, 10, 13, 13, 10, 26, 13, 10, 13, 10};
    int i, res;

    fp = fopen("doc\\test.txt", "wb");
    for (i = 0; i < 10; i++)
    {
        fputc(arr[i], fp);
    }
    fclose(fp);

    fp = fopen("doc\\test.txt", "rt");
    while(1)
    {
        res = fgetc(fp);
        if (res == EOF) break;
        printf("%5d", res);
    }
    fclose(fp);
    
    return 0;
}

#endif

#if 0 // p.556 18-5

#include <stdio.h>

int main(void)
{
    int ch;

    while (1)
    {
        ch = fgetc(stdin);
        if (ch == EOF) // 키보드로 ctrl+z 입력
        {
            break;
        }
        fputc(ch, stdout);
    }

    return 0;
}

#endif

#if 0 // p.554 18-4

#include <stdio.h>

int main(void)
{
    int ch;

    while(1)
    {
        ch = getchar();
        if (ch == EOF) break;
        putchar(ch);
    }

    return 0;
}


#endif

#if 0 // p.552 18-3

#include <stdio.h>

int main(void)
{
    FILE *fp;
    char str[] = "바나나 죠아";
    int i;

    fp = fopen("doc\\test2.txt", "w");
    if (fp == NULL)
    {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    i = 0;
    while(str[i] != '\0')
    {
        fputc(str[i], fp);
        i++;
    }

    fputc('\n', fp);
    fclose(fp);

    return 0;
}

#endif 

#if 0 // p.549 18-2

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int ch;

    fp = fopen("doc\\test.txt", "r");
    if (fp == NULL)
    {
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }

    while(1)
    {
        ch = fgetc(fp);        
        if (ch == EOF) break;

        putchar(ch);
    }
    fclose(fp);

    return 0;
}


#endif

#if 0 // p.543 18-1 

#include <stdio.h>

int main(void)
{
    FILE *fp;

    fp = fopen("a.txt", "r"); // fopen은 파일의 주소를 리턴하는 함수
    if (fp == NULL) // 포인터가 널이라면
    {
        printf("파일이 열리지 않았습니다.\n");
        return 1; 
    }
    printf("파일이 열렸습니다.\n");
    fclose(fp);

    return 0;
}

#endif