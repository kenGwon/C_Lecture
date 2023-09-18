#if 1
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
    char eng[3];
    char math[3];
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

/*
[ 실행결과 ]

 *  작업 실행 중: cmd /C D:\project\c\source\LC\lc0918 

학점 평점 영어 수학 이름(A 3.5 99 99 ken): a 4.5 99 99 ken
EXCELLENT a 4.5 99 99 ken

학점 평점 영어 수학 이름(A 3.5 99 99 ken): b 4.3 90 90 ken
GOOD b 4.3 90 90 ken

학점 평점 영어 수학 이름(A 3.5 99 99 ken): c 3.7 85 99 ken
NORMAL c 3.7 85 99 ken

학점 평점 영어 수학 이름(A 3.5 99 99 ken): d 4.4 44 44 ken
d 4.4 44 44 ken

학점 평점 영어 수학 이름(A 3.5 99 99 ken): F 2.1 30 30 ken
 *  터미널이 작업에서 다시 사용됩니다. 닫으려면 아무 키나 누르세요. 
*/