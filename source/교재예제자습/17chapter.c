
#if 1 // p.540 17-challenge

typedef struct student
{
    char name[20];
    int id;
    int kor;
    int eng;
    int math;
    double avg;
    char grade;
}Student;

// struct double_linked_list
// {
//     Student *front;
//     Student *current;
//     Student *rear;
// };

#include <stdio.h>

int main(void)
{
    int i;

    Student s_list[5];

    for (i = 0; i < 5; i++)
    {
        printf("학번: ");
        scanf("%d", s_list[i].id);
        printf("이름: ");
        scanf("%s", s_list[i].name);
        printf("국어, 영어, 수학 점수: ");
        scanf("%d%d%d", s_list[i].kor, s_list[i].eng, s_list[i].math);

        s_list[i].avg = (s_list[i].kor + s_list[i].eng + s_list[i].math) / 3.0;
        if (s_list[i].avg >= 90) s_list[i].grade = 'A';
        else if (s_list[i].avg >= 80) s_list[i].grade = 'B';
        else if (s_list[i].avg >= 70) s_list[i].grade = 'C';
        else s_list[i].grade = 'F';
    }

/*****************************************************************
                      아직 정렬방식 미구현                        
*****************************************************************/

    return 0;
}

#endif 

#if 0 // p.533 17-12

#include <stdio.h>

typedef struct student 
{
    int num;
    double grade;

} Student_t;
// typedef struct student Student_t;
void print_data(Student_t *ps);

int main(void)
{   
    Student_t s1 = {60150649, 4.5};
    print_data(&s1);

    return 0;
}

void print_data(Student_t *pt)
{
    printf("학생의 학번은: %d\n", pt->num);
    printf("학생의 학점은: %.1lf\n", pt->grade);
}

#endif

#if 0 //p.532 17-11

#include <stdio.h>

enum season{
    SPRING, SUMMER, FALL, WINTER
};

int main(void)
{
    enum season happy_season;
    char *temp;

    happy_season = SPRING;

    switch (happy_season)
    {
    case SPRING:
        printf("봄에는 꽃놀이");
        break;
    
    case SUMMER:
        printf("여름에는 물놀이");
        break;

    case FALL:
        printf("가을에는 낙엽놀이");
        break;

    case WINTER:
        printf("겨울에는 썰매놀이");
        break;

    default:
        break;
    }


    return 0;
}

#endif

#if 0 // p.530 17-10

#include <stdio.h>

union student
{
    int num;
    double grade;
};

int main(void)
{
    union student s1 = {315};

    printf("학번: %d\n", s1.num);
    s1.grade = 4.4;
    printf("학점: %.1lf\n", s1.grade);
    printf("re학번: %d\n", s1.num);

    return 0;
}

#endif

# if 0 // p.527 17-9

#include <stdio.h>

struct list
{
    int num;
    struct list *next;
};

int main(void)
{
    struct list a = {10, 0}, b = {20, 0}, c = {30, 0}; // 구조체 변수 초기화
    struct list *head = &a, *current; // 헤드 포인터 초기화

    a.next = &b;
    b.next = &c;

    printf("head->num: %d\n", head->num); // 10
    printf("a.next->num: %d\n", a.next->num); // 20
    printf("b.next->num: %d\n", b.next->num); // 30

    printf("list all: ");
    current = head;
    while(current->next != NULL)
    {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");

    return 0;
}

#endif

#if 0 // p.525 17-8

#include <stdio.h>

struct adress
{
    char name[20];
    int age;
    char tel[20];
    char addr[80];
};

void print_list(struct adress *st);

int main(void)
{
    struct adress list[5] = {
        {"홍길동", 22, "111-1111", "울릉도 독도"},
        {"장보고", 75, "121-1331", "강원도 동해"},
        {"유관순", 90, "331-4411", "경상도 부산"},
        {"안중근", 52, "661-1522", "전라도 광주"},
        {"이순신", 32, "861-0021", "충청도 충주"}
    };

    print_list(list);

    return 0;
}

void print_list(struct adress *st)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%5s%5d%15s%20s\n", (st+i)->name, (st+i)->age, (st+i)->tel, (st+i)->addr);
    }
}


#endif

#if 0 // p.523 17-7

#include <stdio.h>

struct adress
{
    char name[20];
    int age;
    char tel[20];
    char addr[80];
};

int main(void)
{
    struct adress list[5] = {
        {"홍길동", 22, "111-1111", "울릉도 독도"},
        {"장보고", 75, "121-1331", "강원도 동해"},
        {"유관순", 90, "331-4411", "경상도 부산"},
        {"안중근", 52, "661-1522", "전라도 광주"},
        {"이순신", 32, "861-0021", "충청도 충주"}
    };

    int i;

    for (i = 0; i < sizeof(list)/sizeof(list[0]); i++)
    {
        printf("%5s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
    }

    return 0;
}

#endif

#if 0 // p.521 17-6

#include <stdio.h>

struct score
{
    int kor;
    int math;
    int english;
};

int main(void)
{
    struct score ken = {90, 80, 70};
    struct score *ps = &ken;
    
    printf("국어: %d\n", ps->kor);
    printf("수학: %d\n", ps->math);
    printf("영어: %d\n", (*ps).english);

    return 0;
}

#endif

#if 0 // p.519

#include <stdio.h>

struct cracker
{
    int price;
    int calories;
};

int main(void)
{
    struct cracker ivy;

    printf("바사삭의 가격과 열량을 입력하세요: ");
    scanf("%d%d", &ivy.price, &ivy.calories);

    printf("바사삭의 가격: %d원\n", ivy.price);
    printf("바사삭의 열량: %d원\n", ivy.calories);

    return 0;
}

#endif

#if 0 // p.516 17-5

#include <stdio.h>

struct vision
{
    double left;
    double right;
};

struct vision exchange(struct vision robot);

int main(void)
{
    struct vision robot;

    printf("시력 입력: ");
    scanf("%lf%lf", &robot.left, &robot.right);

    robot = exchange(robot);
    printf("바뀐 시력: %.1lf, %.1lf", robot.left, robot.right);

    return 0;
}

struct vision exchange(struct vision robot)
{
    double temp;
    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;
    
    return robot;
}

#endif

#if 0 // p.513 17-4

#include <stdio.h>

struct student
{
    int id;
    char name[20];
    double grade;
};


int main(void)
{
    struct student s1 = {314, "ken", 2.5},
                   s2 = {22, "gwon", 3.4},
                   s3 = {5124, "ghang", 4.3};

    struct student max;
    max = s1;
    if (s2.grade > max.grade) max = s2;
    if (s3.grade > max.grade) max = s3;

    printf("max의 학번: %d\n", max.id);
    printf("max의 이름: %s\n", max.name);
    printf("max의 평점: %.1lf\n", max.grade);

    return 0;
}

#endif

#if 0 // p.511 17-3

#include <stdio.h>

struct profile
{
    int age;
    double height;
};

struct student
{
    struct profile pf;
    int id;
    double grade;
};

int main(void)
{
    struct student yuni;

    yuni.pf.age = 17;
    yuni.pf.height = 164.5;
    yuni.id = 315;
    yuni.grade = 4.3;

    printf("나이: %d\n", yuni.pf.age);
    printf("키: %.1lf\n", yuni.pf.height);
    printf("학번: %d\n", yuni.id);
    printf("학점: %.1lf\n", yuni.grade);

    return 0;
}

#endif

#if 0 // p.509 17-2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile 
{
    char name[20];
    int age;
    double height;
    char *intro;
};

int main(void)
{
    struct profile ken;
    
    strcpy(ken.name, "kenGwon");
    ken.age = 17;
    ken.height = 175;

    /////////////구조체와 동적할당의 조합/////////////
    ken.intro = (char *)malloc(100);
    printf("자기소개를 입력해주세요: ");
    fgets(ken.intro, 100, stdin);
    ////////////////////////////////////////////////

    printf("이름: %s\n", ken.name);
    printf("나이: %d\n", ken.age);
    printf("키: %.1lf\n", ken.height);
    printf("자기소개: %s\n", ken.intro);

    free(ken.intro);

    return 0;
}

#endif

#if 0 // p.505 17-1

#include <stdio.h>

typedef struct student
{
    int num;
    double grade;
} yes;

int main(void)
{
    struct student s1;
    yes s2;

    s1.num = 1234;
    s2.num = 968;
    s1.grade = 1.1;
    s2.grade = 4.3;

    printf("%d %d\n", s1.num, s2.num);
    printf("%.1lf %.1lf\n", s1. grade, s2.grade);

    return 0;
}

#endif