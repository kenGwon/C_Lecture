#if 1 // 3차원 배열로 달력만들기
/*
2023년 달력 출력... 1/1은 일요일로 가정


        1월
일  월  화 수  목 금 토
  1  2  3  4  5  6  7  
  8  9  10 11 12 13 14
  15 16 17 18 19 20 21
  22 23 24 25 26 27 28
  29 30 31

        2월
일  월  화  수  목  금  토
            1   2   3   4
5   6   7   8   9  10  11
*/
#include <stdio.h>

int main(void)
{
    int day_of_month[14] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int callender[14][6][8] = { 0 }; 

    int offset = 0; // 해당 달의 1일까지의 offset
    int cnt = 1; // 날짜값 입력용 변수
    int i, j, k; 

    // 3차원 배열로 2023년 달력 만들기
    for (i = 1; i < 13; i++)
    {
        offset = (offset + (day_of_month[i-1] % 7)) % 7; 
        
        for (j = 1; j < 7; j++)
        {
            if (j == 1)
            {
                for (k = 1; k < 8; k++)
                {
                    callender[i][j][offset+k] = cnt;
                    cnt++;
                }
                cnt -= offset;
            }
            else
            {
                for (k = 1; k < 8; k++)
                {
                    callender[i][j][k] = cnt;
                    cnt++;                    

                    if (cnt == day_of_month[i] + 1) break;
                }
            }
            
            if (cnt == day_of_month[i] + 1)
            {
                cnt = 1;
                break;
            }
        }
    }

    // 3차원 배열로 완성된 달력 출력
    for (i = 1; i < 13; i++)
    {
        printf("%d월\n", i);
        printf("%-5s%-5s%-5s%-5s%-5s%-5s%-5s\n", "sun", "mon", "tue", "wen", "thr", "fri", "sat");
        for (j = 1; j < 7; j++)
        {
            for (k = 1; k < 8; k++)
            {
                if (callender[i][j][k] == 0) printf("%-5c", ' ');
                else printf("%-5d", callender[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

#endif