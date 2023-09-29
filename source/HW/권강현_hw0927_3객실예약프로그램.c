/*
  - 모든 Requirement 구현 완료(찾지 못한 edge case가 아마 없을건데 있을수도 있음).
  - (주의1) reservation.txt에는 반드시 ASCII로 표현 가능한 문자만 존재하여야 함(한글 X).
  - (주의2) 터미널 입력 포멧에 대한 예외처리를 안했기 때문에, 정확한 포멧으로 터미널 입력이 들어가야 함.
  - (참고1) 테스트를 위해 파일 경로 변경이 필요할 경우, fopen()이 위치한 라인은 82라인, 529라인 두 곳임.
  - (참고2) 테스트 하기 적합하게 미리 구성하여 배포한 reservation.txt를 이용하면, 기능 테스트가 수월함.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char year[6];
    char month[4];
    char day[4];
    char time[6];
} _stDate;

typedef struct _node
{
    char address[40];
    char phone[40];
    char name[20];
    _stDate enter_date;
    _stDate exit_date;
    int roomno;
    int price;
    struct _node *prev;
    struct _node *next;
} t_Node;

typedef struct
{
    t_Node *head_node;
    t_Node *tail_node;
    t_Node *curr_node;
    int num_of_node;
} t_List;

// main.c에 붙어도 될 만한 느낌의 함수들
void reservationManagement(void);
void menuDisplay(void);

// 분할했으면 extern 했을 만한 느낌의 함수들
void CreateReservation(t_List *list);
void DeleteReservation(t_List *list);
void ModifyReservation(t_List *list);
void OnePersonDisplay(t_List *list);
void AllPersonDisplay(t_List *list);
void ExitProgram(t_List *list);

// 분할했으면 static 했을 만한 느낌의 함수들
t_List *initDoubleLinkedList(void);
t_Node *searchReservationByName(t_List *list, char *name);
void readFileWriteMemory(FILE *fp, t_List *list);
void readMemoryWriteFile(FILE *fp, t_List *list);
void refine_stDate(_stDate *date, char *temp);
int checkAvailability(t_List *list, t_Node *new_node);

int main(void)
{
    reservationManagement();

    return 0;
}

/*
  - desc: 객실 예약 프로그램 실행
*/
void reservationManagement(void)
{
    char input_buff[20];
    int select;

    FILE *fp;
    t_List *list;

    list = initDoubleLinkedList();

    fp = fopen("source\\HW\\reservation.txt", "r");
    if (fp == NULL)
    {
        printf("파일열기에 실패했습니다.\n");
        exit(1); // 프로세스 종료 main() return code 1: 파일열기 실패
    }

    readFileWriteMemory(fp, list); // 파일 데이터를 모두 더블링크드리스트에 동적할당하여 메모리로 이관
    fclose(fp);

    void (*pfunction[])(t_List *) = {NULL,
                                     CreateReservation, DeleteReservation, ModifyReservation,
                                     OnePersonDisplay, AllPersonDisplay};

    while (1)
    {
        menuDisplay();
        printf("\n메뉴선택>> ");
        fgets(input_buff, sizeof(input_buff), stdin);
        printf("\n");
        select = atoi(input_buff);

        if (select == 9)
        {
            ExitProgram(list);
        }
        else if (select >= 1 && select <= 5)
        {
            pfunction[select](list);
        }
        else
        {
            printf("잘못된 입력입니다.\n");
        }
    }
}

/*
  - desc: 프로그램 메뉴를 출력한다.
*/
void menuDisplay(void)
{
    int i;
    char menu[10][60] = {
        "==================< 객실 관리 >==================",
        "   1. 입력(예약)",
        "   2. 삭제(퇴실)",
        "   3. 수정(예약내역수정)",
        "   4. 조회(개별조회)",
        "   5. 전체조회(예약자 전체조회)",
        " ",
        "   9. 종료"};

    printf("\n\n");
    for (i = 0; i < 8; i++)
        printf("%s\n", menu[i]);
}

/*
  - desc: 터미널에서 사용자 입력한 정보를 바탕으로 새로운 예약 노드를 생성한다.
  - param1: 더블 링크드 리스트 포인터
*/
void CreateReservation(t_List *list)
{
    char input_buff[100];
    t_Node *new_node;

    new_node = (t_Node *)malloc(sizeof(t_Node));
    if (new_node == NULL)
    {
        printf("동적할당에 실패했습니다.\n");
        exit(2); // 프로세스 종료 main() return code 2: 동적할당 실패
    }

    printf("---------< 입실 예약 >---------\n");
    printf("객실 번호: ");
    fgets(input_buff, sizeof(input_buff), stdin);
    input_buff[strlen(input_buff) - 1] = '\0';
    new_node->roomno = atoi(input_buff);

    printf("성함: ");
    fgets(input_buff, sizeof(input_buff), stdin);
    input_buff[strlen(input_buff) - 1] = '\0';
    strcpy(new_node->name, input_buff);

    printf("전화번호: ");
    fgets(input_buff, sizeof(input_buff), stdin);
    input_buff[strlen(input_buff) - 1] = '\0';
    strcpy(new_node->phone, input_buff);

    printf("요금: ");
    fgets(input_buff, sizeof(input_buff), stdin);
    input_buff[strlen(input_buff) - 1] = '\0';
    new_node->price = atoi(input_buff);

    printf("주소: ");
    fgets(input_buff, sizeof(input_buff), stdin);
    input_buff[strlen(input_buff) - 1] = '\0';
    strcpy(new_node->address, input_buff);

    printf("입실예정시각(yyyy-mm-dd-hhmm): ");
    fgets(input_buff, sizeof(input_buff), stdin);
    input_buff[strlen(input_buff) - 1] = '\0';
    strcpy(new_node->enter_date.year, strtok(input_buff, "-"));
    strcpy(new_node->enter_date.month, strtok(NULL, "-"));
    strcpy(new_node->enter_date.day, strtok(NULL, "-"));
    strcpy(new_node->enter_date.time, strtok(NULL, "-"));

    printf("퇴실예정시각(yyyy-mm-dd-hhmm): ");
    fgets(input_buff, sizeof(input_buff), stdin);
    input_buff[strlen(input_buff) - 1] = '\0';
    strcpy(new_node->exit_date.year, strtok(input_buff, "-"));
    strcpy(new_node->exit_date.month, strtok(NULL, "-"));
    strcpy(new_node->exit_date.day, strtok(NULL, "-"));
    strcpy(new_node->exit_date.time, strtok(NULL, "-"));

    printf("\n");
    printf("확인(y/n): ");
    fgets(input_buff, sizeof(input_buff), stdin);
    input_buff[strlen(input_buff) - 1] = '\0';

    if (strncmp(input_buff, "y", 1) == 0)
    {
        // 해당 객실이 해당 시간에 예약 가능하면 insert, 불가능하면 free().
        if (checkAvailability(list, new_node))
        {
            new_node->next = list->tail_node->next;
            new_node->prev = list->tail_node;

            list->tail_node->next = new_node;
            list->tail_node = new_node;
            list->num_of_node++;
            printf("예약이 완료되었습니다.\n");
        }
        else
        {
            printf("해당 시간에 이미 예약된 객실입니다. 예약이 취소됩니다.\n");
            free(new_node);
        }
    }
    else // 사용자 선택에 의한 예약 취소
    {
        printf("입실 예약이 취소되었습니다.\n");
        free(new_node);
    }
}

/*
  - desc: 터미널에서 사용자가 지정한 예약 노드의 정보를 삭제한다.
  - param1: 더블 링크드 리스트 포인터
*/
void DeleteReservation(t_List *list)
{
    char input_buff[100];
    int roomno;
    char name[20];
    int i;
    t_Node *target_reservation;

    printf("---------< 삭제(퇴실) >---------\n");
    printf("예약자 성함: ");
    fgets(input_buff, sizeof(input_buff), stdin);
    input_buff[strlen(input_buff) - 1] = '\0';
    strcpy(name, input_buff);

    target_reservation = searchReservationByName(list, name);

    if (target_reservation)
    {
        printf("확인 (y/n): ");
        fgets(input_buff, sizeof(input_buff), stdin);
        input_buff[strlen(input_buff) - 1] = '\0';

        if (strncmp(input_buff, "y", 1) == 0)
        {
            if (target_reservation->next == NULL)
            {
                target_reservation->prev->next = NULL;
                list->tail_node = target_reservation->prev;
                list->num_of_node--;
            }
            else
            {
                target_reservation->prev->next = target_reservation->next;
                target_reservation->next->prev = target_reservation->prev;
                list->num_of_node--;
            }

            printf("퇴실처리 되었습니다.\n");
            free(target_reservation);
        }
        else // 사용자 선택에 의한 삭제 취소
        {
            printf("삭제를 취소합니다.\n");
            return;
        }
    }
    else
    {
        printf("해당 이름으로 예약이 존재하지 않습니다.\n");
    }
}

/*
  - desc: 터미널에서 사용자가 지정한 예약 노드의 정보를 수정한다. 수정 가능 여부는 checkAvailability()함수를 통해 판단한다.
  - param1: 더블 링크드 리스트 포인터
*/
void ModifyReservation(t_List *list)
{
    char input_buff[100];
    char name[20];
    int temp_roomno;
    int select;
    t_Node *target_reservation;
    char temp_enter_date[4][10], temp_exit_date[4][10];

    printf("---------< 예약 수정 >---------\n");
    printf("예약자 성함: ");
    fgets(input_buff, sizeof(input_buff), stdin);
    input_buff[strlen(input_buff) - 1] = '\0';
    strcpy(name, input_buff);

    target_reservation = searchReservationByName(list, name);

    if (target_reservation)
    {
        printf("무엇을 수정하시겠습니까?\n");
        printf("(1)객실번호 (2)예약자이름 (3)전화번호 (4)요금\n");
        printf("(5)주소 (6)입실시간 (7)퇴실시간\n");
        printf(">> ");
        fgets(input_buff, sizeof(input_buff), stdin);
        input_buff[strlen(input_buff) - 1] = '\0';
        select = atoi(input_buff);

        switch (select)
        {
        case 1:
            printf("바꾸실 객실번호를 입력하세요: ");
            fgets(input_buff, sizeof(input_buff), stdin);
            input_buff[strlen(input_buff) - 1] = '\0';

            temp_roomno = target_reservation->roomno;
            target_reservation->roomno = atoi(input_buff);

            if (checkAvailability(list, target_reservation))
            {
                printf("정상 수정되었습니다.\n");
            }
            else
            {
                printf("해당 시간에 해당 객실은 사용중이기 때문에 불가능합니다.\n");
                target_reservation->roomno = temp_roomno;
            }

            break;

        case 2:
            printf("바꾸실 예약자분 성함을 입력하세요: ");
            fgets(input_buff, sizeof(input_buff), stdin);
            input_buff[strlen(input_buff) - 1] = '\0';
            strcpy(target_reservation->name, input_buff);
            printf("정상 수정되었습니다.\n");
            break;

        case 3:
            printf("바꾸실 전화번호를 입력하세요: ");
            fgets(input_buff, sizeof(input_buff), stdin);
            input_buff[strlen(input_buff) - 1] = '\0';
            strcpy(target_reservation->phone, input_buff);
            printf("정상 수정되었습니다.\n");
            break;

        case 4:
            printf("바꾸실 요금을 입력하세요: ");
            fgets(input_buff, sizeof(input_buff), stdin);
            input_buff[strlen(input_buff) - 1] = '\0';
            target_reservation->price = atoi(input_buff);
            printf("정상 수정되었습니다.\n");
            break;

        case 5:
            printf("바꾸실 주소를 입력하세요: ");
            fgets(input_buff, sizeof(input_buff), stdin);
            input_buff[strlen(input_buff) - 1] = '\0';
            strcpy(target_reservation->address, input_buff);
            printf("정상 수정되었습니다.\n");
            break;

        case 6:
            printf("바꾸실 입실시간을 입력하세요(yyyy-mm-dd-hhmm): ");
            fgets(input_buff, sizeof(input_buff), stdin);
            input_buff[strlen(input_buff) - 1] = '\0';

            strcpy(temp_enter_date[0], target_reservation->enter_date.year);
            strcpy(temp_enter_date[1], target_reservation->enter_date.month);
            strcpy(temp_enter_date[2], target_reservation->enter_date.day);
            strcpy(temp_enter_date[3], target_reservation->enter_date.time);

            strcpy(target_reservation->enter_date.year, strtok(input_buff, "-"));
            strcpy(target_reservation->enter_date.month, strtok(NULL, "-"));
            strcpy(target_reservation->enter_date.day, strtok(NULL, "-"));
            strcpy(target_reservation->enter_date.time, strtok(NULL, "-"));

            if (checkAvailability(list, target_reservation))
            {
                printf("정상 수정되었습니다.\n");
            }
            else
            {
                printf("해당 시간에 해당 객실은 사용중이기 때문에 불가능합니다.\n");
                strcpy(target_reservation->enter_date.year, temp_enter_date[0]);
                strcpy(target_reservation->enter_date.month, temp_enter_date[1]);
                strcpy(target_reservation->enter_date.day, temp_enter_date[2]);
                strcpy(target_reservation->enter_date.time, temp_enter_date[3]);
            }
            break;

        case 7:
            printf("바꾸실 퇴실시간을 입력하세요(yyyy-mm-dd-hhmm): ");
            fgets(input_buff, sizeof(input_buff), stdin);
            input_buff[strlen(input_buff) - 1] = '\0';

            strcpy(temp_exit_date[0], target_reservation->exit_date.year);
            strcpy(temp_exit_date[1], target_reservation->exit_date.month);
            strcpy(temp_exit_date[2], target_reservation->exit_date.day);
            strcpy(temp_exit_date[3], target_reservation->exit_date.time);

            strcpy(target_reservation->exit_date.year, strtok(input_buff, "-"));
            strcpy(target_reservation->exit_date.month, strtok(NULL, "-"));
            strcpy(target_reservation->exit_date.day, strtok(NULL, "-"));
            strcpy(target_reservation->exit_date.time, strtok(NULL, "-"));

            if (checkAvailability(list, target_reservation))
            {
                printf("정상 수정되었습니다.\n");
            }
            else
            {
                printf("해당 시간에 해당 객실은 사용중이기 때문에 불가능합니다.\n");
                strcpy(target_reservation->exit_date.year, temp_exit_date[0]);
                strcpy(target_reservation->exit_date.month, temp_exit_date[1]);
                strcpy(target_reservation->exit_date.day, temp_exit_date[2]);
                strcpy(target_reservation->exit_date.time, temp_exit_date[3]);
            }
            break;

        default:
            printf("잘못된 입력입니다.\n");
            break;
        }
    }
    else
    {
        printf("해당 이름으로 예약이 존재하지 않습니다.\n");
    }
}

/*
  - desc: 터미널에서 사용자가 지정한 예약 노드의 정보를 터미널에 출력한다.
  - param1: 더블 링크드 리스트 포인터
*/
void OnePersonDisplay(t_List *list)
{
    char input_buff[100];
    char name[20];
    char temp_enter_date[20] = {'\0'}, temp_exit_date[20] = {'\0'};
    t_Node *target_reservation;

    printf("---------< 조회(개별조회) >---------\n");
    printf("예약자 성함: ");
    fgets(input_buff, sizeof(input_buff), stdin);
    input_buff[strlen(input_buff) - 1] = '\0';
    strcpy(name, input_buff);

    target_reservation = searchReservationByName(list, name);

    if (target_reservation)
    {
        printf("\n<< %s님의 예약정보 >>\n\n", name);
        printf("객실번호: %d\n", target_reservation->roomno);
        printf("예약자: %s\n", target_reservation->name);
        printf("전화번호: %s\n", target_reservation->phone);
        printf("요금: %d\n", target_reservation->price);
        printf("주소: %s\n", target_reservation->address);
        refine_stDate(&target_reservation->enter_date, temp_enter_date);
        printf("입실시간: %s\n", temp_enter_date);
        refine_stDate(&target_reservation->exit_date, temp_exit_date);
        printf("퇴실시간: %s\n", temp_exit_date);
    }
    else
    {
        printf("해당 이름으로 예약이 존재하지 않습니다.\n");
    }
}

/*
  - desc: 현재 리스트에 들어있는 모든 예약 노드의 정보를 터미널에 출력한다.
  - param1: 더블 링크드 리스트 포인터
*/
void AllPersonDisplay(t_List *list)
{
    int i;
    char temp_enter_date[20] = {'\0'}, temp_exit_date[20] = {'\0'};

    printf("---------------------------------------------< 전체조회(예약자 전체조회) >----------------------------------------------\n");
    printf("객실  이름            전화번호             요금       주소                 입실시간             퇴실시간                  \n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");

    list->curr_node = list->tail_node;
    for (i = 0; i < list->num_of_node; i++)
    {
        temp_enter_date[0] = '\0';
        temp_exit_date[0] = '\0';
        printf("%-5d ", list->curr_node->roomno);
        printf("%-15s ", list->curr_node->name);
        printf("%-20s ", list->curr_node->phone);
        printf("%-10d ", list->curr_node->price);
        printf("%-20s ", list->curr_node->address);
        refine_stDate(&list->curr_node->enter_date, temp_enter_date);
        printf("%-20s ", temp_enter_date);
        refine_stDate(&list->curr_node->exit_date, temp_exit_date);
        printf("%-20s ", temp_exit_date);

        printf("\n");

        list->curr_node = list->curr_node->prev;
    }
}

/*
  - desc: 프로그램을 종료한다.
  - param1: 더블 링크드 리스트 포인터
*/
void ExitProgram(t_List *list)
{
    int i;
    char input_buff[100];
    FILE *fp;

    printf("---------< 종료 >---------\n");
    printf("확인 (y/n): ");
    fgets(input_buff, sizeof(input_buff), stdin);
    input_buff[strlen(input_buff) - 1] = '\0';

    if (strncmp(input_buff, "y", 1) == 0)
    {
        fp = fopen("source\\HW\\reservation.txt", "w");
        if (fp == NULL)
        {
            printf("파일열기에 실패했습니다.\n");
            exit(1); // 프로세스 종료 main() return code 1: 파일열기 실패
        }

        rewind(fp);
        readMemoryWriteFile(fp, list);
        fclose(fp);
        free(list);
        exit(0); // 프로세스 종료 main() return code 0: 정상종료
    }
    else // 사용자가 종료를 취소함
    {
        return;
    }
}

/*
  - desc: 더블 링크드 리스트를 initialize한다.
  - return: init_node를 가진 더블 링크드 리스트를 리턴한다.
*/
t_List *initDoubleLinkedList(void)
{
    t_List *list;
    t_Node *init_node;

    list = (t_List *)malloc(sizeof(t_List));
    if (list == NULL)
    {
        printf("동적할당에 실패했습니다.\n");
        exit(2); // 프로세스 종료 main() return code 2: 동적할당 실패
    }

    init_node = (t_Node *)malloc(sizeof(t_Node));
    if (init_node == NULL)
    {
        printf("동적할당에 실패했습니다.\n");
        exit(2); // 프로세스 종료 main() return code 2: 동적할당 실패
    }

    init_node->prev = NULL;
    init_node->next = NULL;

    list->head_node = init_node;
    list->tail_node = init_node;
    list->curr_node = init_node;
    list->num_of_node = 0;

    return list;
}

/*
  - desc: 이름 문자열을 매개변수로 받아, 더블 링크드 리스트를 순회하며 해당 이름과 같은 이름을 저장하고 있는 노드를 검색한다.
  - param1: 더블 링크드 리스트 포인터
  - param2: 검색할 이름 문자열
  - return: 검색에 성공하면 찾은 노드를 반환하고, 검색에 실패하면 NULL을 리턴한다.
*/
t_Node *searchReservationByName(t_List *list, char *name)
{
    int i;

    list->curr_node = list->tail_node;

    for (i = 0; i < list->num_of_node; i++)
    {
        if (strncmp(name, list->curr_node->name, strlen(name)) == 0)
        {
            return list->curr_node;
        }
        else
        {
            list->curr_node = list->curr_node->prev;
        }
    }

    return NULL;
}

/*
  - desc: 파일에 있는 텍스트를 읽어, 메모리에 있는 더블 링크드 리스트 자료구조에 옮겨 쓴다.
  - param1: 파일 포인터
  - param2: 더블 링크드 리스트 포인터
*/
void readFileWriteMemory(FILE *fp, t_List *list)
{
    char input_buff[200];
    char enter_date[20], exit_date[20];
    t_Node *new_node, *prev;

    while (1)
    {
        fgets(input_buff, sizeof(input_buff), fp);
        if (feof(fp))
            break;
        input_buff[strlen(input_buff) - 1] = '\0';

        new_node = (t_Node *)malloc(sizeof(t_Node));
        if (new_node == NULL)
        {
            printf("동적할당에 실패했습니다.\n");
            exit(2); // 프로세스 종료 main() return code 2: 동적할당 실패
        }

        new_node->roomno = atoi(strtok(input_buff, ":"));
        strcpy(new_node->name, strtok(NULL, ":"));
        strcpy(new_node->phone, strtok(NULL, ":"));
        new_node->price = atoi(strtok(NULL, ":"));
        strcpy(new_node->address, strtok(NULL, ":"));

        strcpy(enter_date, strtok(NULL, ":"));
        strcpy(exit_date, strtok(NULL, ":"));

        strcpy(new_node->enter_date.year, strtok(enter_date, "-"));
        strcpy(new_node->enter_date.month, strtok(NULL, "-"));
        strcpy(new_node->enter_date.day, strtok(NULL, "-"));
        strcpy(new_node->enter_date.time, strtok(NULL, "-"));

        strcpy(new_node->exit_date.year, strtok(exit_date, "-"));
        strcpy(new_node->exit_date.month, strtok(NULL, "-"));
        strcpy(new_node->exit_date.day, strtok(NULL, "-"));
        strcpy(new_node->exit_date.time, strtok(NULL, "-"));

        new_node->next = list->tail_node->next;
        new_node->prev = list->tail_node;

        list->tail_node->next = new_node;
        list->tail_node = new_node;
        list->num_of_node++;
    }
}

/*
  - desc: 메모리에 있는 더블 링크드 리스트 자료구조를 읽어, 파일에 텍스트로 옮겨 쓴다.
  - param1: 파일 포인터
  - param2: 더블 링크드 리스트 포인터
*/
void readMemoryWriteFile(FILE *fp, t_List *list)
{
    int i;

    list->curr_node = list->tail_node;
    for (i = 0; i < list->num_of_node; i++)
    {
        fprintf(fp, "%d:%s:%s:%d:%s:%s-%s-%s-%s:%s-%s-%s-%s\n", list->curr_node->roomno,
                list->curr_node->name, list->curr_node->phone, list->curr_node->price, list->curr_node->address,
                list->curr_node->enter_date.year, list->curr_node->enter_date.month,
                list->curr_node->enter_date.day, list->curr_node->enter_date.time,
                list->curr_node->exit_date.year, list->curr_node->exit_date.month,
                list->curr_node->exit_date.day, list->curr_node->exit_date.time);

        list->curr_node = list->curr_node->prev;
    }
}

/*
  - desc: 구조체 _stDate의 멤버변수들을 이용해 yyyy-mm-dd-tttt 형태의 문자열을 편집한다.
  - param1: 원본 구조체 포인터
  - param2: 편집된 문자열 포인터
*/
void refine_stDate(_stDate *date, char *temp)
{
    strcat(temp, date->year);
    strcat(temp, "-");
    strcat(temp, date->month);
    strcat(temp, "-");
    strcat(temp, date->day);
    strcat(temp, " ");
    strcat(temp, date->time);
}

/*
  - desc: 수정 요청된 예약과 "객실번호 및 입실/퇴실 시간"이 겹치는 기존 예약이 있는지 검사한다.
  - param1: 더블 링크드 리스트 포인터
  - param2: 수정요청 된 예약(임시 변경상태) 포인터
  - return: 예약 가능여부 Boolean(0, 1)
*/
int checkAvailability(t_List *list, t_Node *target_reservation)
{
    int i, flag;
    char curr_node_enter_time[30] = {'\0'}, curr_node_exit_time[30] = {'\0'},
         target_reservation_enter_time[30] = {'\0'}, target_reservation_exit_time[30] = {'\0'};

    // printf("최초 테일 값 list->tail_node->roomno: %d\n", list->tail_node->roomno);
    list->curr_node = list->tail_node;

    flag = 0;
    for (i = 0; i < list->num_of_node; i++)
    {
        if (list->curr_node == target_reservation)
        {
            // printf("자기자신 건너뛰기\n");
            list->curr_node = list->curr_node->prev;
            continue;
        }

        if (list->curr_node->roomno == target_reservation->roomno)
        {
            // printf("반복문if진입 list->curr_node->roomno: %d // target_reservation->roomno: %d\n", list->curr_node->roomno, target_reservation->roomno);
            curr_node_enter_time[0] = '\0';
            curr_node_exit_time[0] = '\0';
            target_reservation_enter_time[0] = '\0';
            target_reservation_exit_time[0] = '\0';
            strcat(curr_node_enter_time, list->curr_node->enter_date.year);
            strcat(curr_node_enter_time, list->curr_node->enter_date.month);
            strcat(curr_node_enter_time, list->curr_node->enter_date.day);
            strcat(curr_node_enter_time, list->curr_node->enter_date.time);

            strcat(curr_node_exit_time, list->curr_node->exit_date.year);
            strcat(curr_node_exit_time, list->curr_node->exit_date.month);
            strcat(curr_node_exit_time, list->curr_node->exit_date.day);
            strcat(curr_node_exit_time, list->curr_node->exit_date.time);

            strcat(target_reservation_enter_time, target_reservation->enter_date.year);
            strcat(target_reservation_enter_time, target_reservation->enter_date.month);
            strcat(target_reservation_enter_time, target_reservation->enter_date.day);
            strcat(target_reservation_enter_time, target_reservation->enter_date.time);

            strcat(target_reservation_exit_time, target_reservation->exit_date.year);
            strcat(target_reservation_exit_time, target_reservation->exit_date.month);
            strcat(target_reservation_exit_time, target_reservation->exit_date.day);
            strcat(target_reservation_exit_time, target_reservation->exit_date.time);

            if (atoll(target_reservation_enter_time) >= atoll(curr_node_enter_time) && atoll(target_reservation_enter_time) <= atoll(curr_node_exit_time))
            {
                flag = 1;
                // printf("케이스(1) 플래그 온\n");
                list->curr_node = list->curr_node->prev;
                continue;
            }
            if (atoll(target_reservation_exit_time) >= atoll(curr_node_enter_time) && atoll(target_reservation_exit_time) <= atoll(curr_node_exit_time))
            {
                flag = 1;
                // printf("케이스(2) 플래그 온\n");
                list->curr_node = list->curr_node->prev;
                continue;
            }
            if (atoll(target_reservation_enter_time) <= atoll(curr_node_enter_time) && atoll(target_reservation_exit_time) >= atoll(curr_node_exit_time))
            {
                flag = 1;
                // printf("케이스(3) 플래그 온\n");
                list->curr_node = list->curr_node->prev;
                continue;
            }
        }

        // printf("반복for문한번끝 list->curr_node->roomno: %d\n", list->curr_node->roomno);
        list->curr_node = list->curr_node->prev;
    }

    if (flag == 1)
        return 0; // 예약 불가능
    else
        return 1; // 예약 가능
}