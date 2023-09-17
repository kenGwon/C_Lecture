
#if 1 // p.441 14-challenge

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

#if 0 // p.423 14-4

#include <stdio.h>

int main(void)
{
    char animal1[5][10] = {
        {'d','o','g','\0'},
        {'t','i','g','e','r','\0'},
        {'r','a','b','b','i','t','\0'},
        {'h','o','r','s','e','\0'},
        {'c','a','t','\0'}
    };
    
    char animal2[][10] = {"dog", "tiger", "rabbit", "horse", "cat"};

    int i;
    for (i=0; i<5; i++)
    {
        printf("%s ", animal1[i]);
    }
    printf("\n");
    for (i=0; i<5; i++)
    {
        printf("%s ", animal2[i]);
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

#if 0 // p.412 14-1

#include <stdio.h>

int main(void)
{
    int score[3][4];
    int total;
    double avg;
    int i, j;

    for (i=0; i<3;i++)
    {
        printf("4과목의 점수 입력: ");
        for (j=0; j<4; j++)
        {
            scanf("%d", &score[i][j]);
        }
        printf("\n");
    }

    for (i=0; i<3;i++)
    {
        total = 0;
        for (j=0; j<4; j++)
        {
            total += score[i][j];
        }
        avg = total/4.0;
        printf("총점: %d, 평균: %d\n", total, avg);
    }
}

#endif