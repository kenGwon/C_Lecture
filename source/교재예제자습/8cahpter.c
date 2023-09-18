#if 0 // 8-6
#include <stdio.h>

int main(void){
    int a = 10, b =20;
    const int *pa = &a;

    printf("변수 a값: %d\n", *pa); // 10
    pa = &b;
    printf("변수 b값: %d\n", *pa); // 20
    pa = &a;
    a = 20;
    printf("변수 a값: %d\n", *pa); // 20

    // *pa = 20; 
    // 포인터에 const를 달아줬기 때문에, 포인터 간접 접근으로 a의 값을 바꿀 수 없게 됨.
    // 즉 포인터의 간접참조로 인해 원 변수의 값이 바뀌는 것을 원치 않을 때, "포인터 측에" const를 달아주면 된다.
    printf("변수 a값: %d\n", *pa); // err


    return 0;
}
#endif

#if 0 // 8-5
#include <stdio.h>

int main(void)
{
	int a = 10, b = 15, total;
	double avg;
	int *pa, *pb;
	int *pt = &total;
	double *pg = &avg;
	
	pa = &a; // 주소에 주소를 대입
	pb = &b;

	// printf("%d\n", pa); // 주소값이 나올 것
	// printf("%d\n", *pa); // 주소에 들어있는 "값"이 나올 것

	*pt = *pa + *pb;
	*pg = *pt / 2.0;

	printf("두 정수의 값: %d, %d\n", *pa, *pb);
	printf("두 정수의 합: %d\n", *pt);
	printf("두 정수의 평균: %.1lf\n", *pg);
	printf("%d\n", total);
	return 0;
}
#endif

#if 0 // 8-4
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[80], str2[80];
	char temp[80];

	printf("두 문자열 입력 : ");
	scanf("%s %s", str1, str2);
	printf("바꾸기 전: %s,%s\n", str1, str2);

	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);

	printf("바꾼 후: %s,%s\n", str1, str2);

	return 0;
}
#endif

#if 0 // 8-3
#include <stdio.h>

int main(void)
{
    char str[80] = "applejam";

    printf("chlch answkduf: %s\n", str);
    printf("문자열 입력: ");
    scanf("%s", str);
    printf("입력 후 문자열: %s\n", str);

    return 0;
}

#endif

#if 0 // 8-2
#include <stdio.h>

int main(void)
{
    int A[3] = {1, 2, 3};
    int B[10];
    int i;

    for (i=0; i<10; i++)
    {
        B[i] = A[i % 3];
    }

    for (i=0; i<10; i++)
    {
        printf("%5d", B[i]);
    }


    return 0;
}
#endif

#if 0 // 8-1
#include <stdio.h>

int main(void)
{
    int score[5];
    int i;
    int total = 0;
    double avg;
    int count; // 배열 요소의 갯수를 저장할 변수 

    count = sizeof(score) / sizeof(score[0]);

    for (i=0; i<count; i++)
    {
        scanf("%d", &score[i]);
    }

    for (i=0; i<count; i++)
    {
        total += score[i];
    }
    avg = total/(double)count; //평균계산

    for (i=0; i<count; i++)
    {
        printf("%05d", score[i]);
    }
    printf("\n");

    printf("평균: %.1lf\n", avg);


    return 0;    
}
#endif



