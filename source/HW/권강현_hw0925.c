#if 1
/* 
  < lc0922_1.c의 뱅킹 코드를 다음 요구조건에 맞게 수정 >
  요구조건1. 구조배열을 구조체포인터로 변경
  요구조건2. switch ~ case문의 menu-driven코딩을, 함수 포인터의 command-driven코딩으로 변경
  요구조건3. 구조체를 정적 메모리 할당에서 동적메모리 할당으로 변경
  요구조건4. 데이터를 메모리가 아닌 하드디스크에 넣어서 접근하도록 변경
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN   20
#define ACCOUNTS_MAX 10

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT=9};

typedef struct 
{
	int acc_id;      // 계좌번호
	int balance;    // 잔    액
	char cus_name[NAME_LEN];   // 고객이름
} t_account; // sizeof(t_account) = 28bytes

void show_menu(void);       // 메뉴출력
void make_account(t_account *t, int *n);       // 계좌개설을 위한 함수
void deposit_money(t_account *t, int *n);       // 입    금
void with_draw_money(t_account *t, int *n);      // 출    금
void show_all_acc_info(t_account *t, int *n);     // 잔액조회

FILE *file_pointer; // 전역변수

int main(void)
{
    int choice;
	int acc_num = 0; // 저장된 Account 수

	void (*fp[])(t_account*, int*) = 
    {
        NULL, // enum에서 1부터 시작하도록 선언해 놓았기 때문
        make_account,
        deposit_money,
        with_draw_money,
        show_all_acc_info
    };

	t_account *acc_arr = (t_account*)malloc(ACCOUNTS_MAX * sizeof(t_account)); // Account 저장을 위한 메모리 할당
	if (acc_arr == NULL)
	{
		printf("메모리 할당에 실패했습니다.");
		exit(1);
	}

    file_pointer = fopen("source\\HW\\money_file", "wb+");
    if (file_pointer == NULL)
    {
        printf("파일 생성에 실패했습니다.");
        exit(1);
    }

	while(1)
	{
		show_menu();
		printf("선택: ");  
		scanf("%d", &choice);
		printf("\n");

		// <command-driven>
		if (choice == 9) 
		{
			printf("프로그램을 종료합니다.\n");
            break;
		}
		else if (choice >= 1 && choice <= 4)
		{
			fp[choice](acc_arr, &acc_num);
		}
		else	
		{
			printf("잘못된 입력입니다.\n");
			continue;
		}
		
		/* <menu-driven>
		switch(choice)
		{
		case MAKE:
			make_account(acc_arr, &acc_num); 
			break;
		case DEPOSIT:
			deposit_money(acc_arr, &acc_num); 
			break;
		case WITHDRAW: 
			with_draw_money(acc_arr, &acc_num); 
			break;
		case INQUIRE:
			show_all_acc_info(acc_arr, &acc_num); 
			break;
		case EXIT:
			return 0;
		default:
			printf("Illegal selection..\n");
		}
		*/
	}

    free(acc_arr); // 위에서 동적할당을 했기 때문에 잊지말고 free해줘야 함.
    fclose(file_pointer); // 위에서 파일 열었으면 잊지말고 닫아줘야지.

	return 0;
}

void show_menu(void)
{
    char *menu[] = {
        "-----Menu------",
        "1. 계좌개설",
        "2. 입    금",
        "3. 출    금",
        "4. 계좌정보 전체 출력",
        "9. 종    료"
    };

    for (int i = 0; i < 6; i++) { printf("%s\n", *(menu+i)); }
}

void make_account(t_account *t, int *n) 
{
	int id;
	char name[NAME_LEN];
	int balance;
	t_account *tp;
	
	if (*n + 1 > ACCOUNTS_MAX) 
	{
		printf("현재 입력 가능한 계좌 수가 가득 찼습니다."); 
		return;
	}
    else
    {
        tp = t + *n;
    }

	printf("[계좌개설]\n");
	printf("계좌ID: ");	
	scanf("%d", &id);
	printf("이  름: ");	
	scanf("%s", name);
	printf("입금액: ");	
	scanf("%d", &balance);
	printf("\n");
	
    rewind(file_pointer);

    for (int i = 0; ; i++)
    {
        // 아래 if문을 체크하는 것 자체 만으로 for문이 한번 돌때마다 
        // 위치 지시자가 이동하면서 파일에서 하나씩 읽어내고 있음.
        if (fread((char*)&tp->acc_id, 1, sizeof(t_account), file_pointer) == 0)
        // 이 조건문이 true로 걸린다는 것은 for문을 돌면서 위치지시자가 이동하면서
        // fread()로 읽었는데 파일에서 읽은게 하나도 없어서 ret에 0이 되었다는 뜻이다.
        // 고로 구조체 하나씩 읽어서 파일의 끝까지 읽었다는 것이다.
        {
            break; // 그러면 비로소 현재 파일에 중복된 id가 없다는 것을 알게되는 것이다.
        }
        else if (tp->acc_id == id)
        {
            printf("ID: %d는 이미 존재하는 ID입니다.\n", id);
            return;
        }
    }

	tp->acc_id = id;
	tp->balance = balance;
	strcpy(tp->cus_name, name);
    fwrite((char*)&tp->acc_id, 1, sizeof(t_account), file_pointer);

	(*n)++;
}

void deposit_money(t_account *t, int *n)
{
	int money;
	int id, i;
	t_account *tp = t; // 원본 포인터 대피

	printf("[입    금]\n");
	printf("계좌ID: ");
	scanf("%d", &id);
	printf("입금액: ");
	scanf("%d", &money);

    rewind(file_pointer);
	
	for (i = 0; i < *n; i++)
	{
		if (fread((char*)&tp->acc_id, 1, sizeof(t_account), file_pointer) == 0)
        {
            break;
        }
        else if (tp->acc_id == id)
		{
			tp->balance += money;
            fseek(file_pointer, -sizeof(t_account), SEEK_CUR);
            fwrite((char *)&tp->acc_id, 1, sizeof(t_account), file_pointer);

			printf("입금완료\n\n");
			return;
		}
		tp++; // 포인터 대피를 했기에 가능한 부분(?)
	}
	printf("유효하지 않은 ID 입니다.\n\n");
}

void with_draw_money(t_account *t, int *n)
{
	int money;
	int id, i;
	t_account *tp = t; // 원본 포인터 대피
	
	printf("[출    금]\n");
	printf("계좌ID: ");
	scanf("%d", &id);
	printf("출금액: ");
	scanf("%d", &money);

    rewind(file_pointer);
	
	for(i = 0; i < *n; i++)
	{
        if(fread((char *)&tp->acc_id, 1, sizeof(t_account), file_pointer) == 0)
        {
            break;
        }
		else if(tp->acc_id == id)
		{
			if(tp->balance < money)
			{
				printf("잔액부족\n\n");
				return;
			}

			tp->balance -= money;
            fseek(file_pointer, -sizeof(t_account), SEEK_CUR);
            fwrite((char *)&tp->acc_id, 1, sizeof(t_account), file_pointer);

			printf("출금완료\n\n");
			return;
		}
		tp++; // 포인터 대피를 했기에 가능한 부분(?)
	}
	printf("유효하지 않은 ID 입니다.\n\n");
}

void show_all_acc_info(t_account *t, int *n)	
{
	int i;
	t_account *tp = t;

    rewind(file_pointer);

	for(i = 0; i < *n; i++)
	{   
        if (fread((char *)&tp->acc_id, 1, sizeof(t_account), file_pointer) == 0)
        {
            break;
        }
		printf("계좌ID: %d\n", tp->acc_id);
		printf("이  름: %s\n", tp->cus_name);
		printf("잔  액: %d\n\n", tp->balance);
		tp++;
	}
    printf("\n");
}

#endif
