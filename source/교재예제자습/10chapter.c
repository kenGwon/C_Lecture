
#if 1 // p.320 10-challenge 

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

#endif

#if 0 // p.317

int ary[5] = {1,2,3,4,5};
print_ary(ary);

void print_ary(int pa[5]) 
// 함수 선언에서 배열을 선언하면 배열의 저장공간이 할당되지 않으며, 
// 매열명은 컴파일 과정에서 첫번째 배열 요소를 가리키는 포인터로 바뀜.
{
    int i;
    for (i=0; i<5; i++)
    {
        printf("%d ", pa[i]);
    }
}
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
