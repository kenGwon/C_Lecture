
#if 1
/*
  구조체를 정적 메모리에 할당 후, 사용자로부터 자료를 입력 받아
  프린트 하는 program을 작성한다. (구조체 pointer 활용)
*/

#include <stdio.h>
#include <string.h>
#define NUMBER 10 // 이런류의 디파인은 코드의 유지보수를 쉽게 해준다.

typedef struct _Person
{
    char name[20];
    int age;
    char address[40];
} Person_t; 

void print_person(Person_t *persons, int person_num);
void copy_person(Person_t *persons, int *index, char *name, int *age, char *address);

int main(void)
{
    Person_t persons[NUMBER]; // 사람 10명을 정적메모리 할당
    char name[20];
    int age;
    char address[40];

    int i = 0;
    while (1)
    {
        printf("name age addree 입력(exit: end 0 end): ");
        scanf("%s%d%s", name, &age, address);
        if (strncmp(name, "end", 3) == 0 || age == 0 || strncmp(address, "end", 3) == 0) 
        {
            print_person(persons, i);
            break;
        }
        else
        {
            copy_person(persons, &i, name, &age, address);
        }
        if (i > NUMBER) break;
    }   

    return 0;
}

void copy_person(Person_t *persons, int *index, char *name, int *age, char *address)
{
    strcpy(persons[*index].name, name);
    persons[*index].age = *age;
    strcpy(persons[*index].address, address);
    (*index)++;
}

void print_person(Person_t *persons, int person_num)
{
    Person_t *temp = persons; // *temp에는 persons[0]의 주소가 들어감 // 원본 포인터를 대피시켜놓고 찍어야 함.

    printf("%s   %s   %s\n", "이름", "나이", "주소");
    printf("=============================\n");
    for (int i = 0; i < person_num; i++)
    {
        printf("%-10s%-10d%-10s\n", (temp+i)->name, (temp+i)->age, (temp+i)->address);
    }
    
}



#endif