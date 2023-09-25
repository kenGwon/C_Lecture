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

int main(void)
{
	int choice;
	int acc_num = 0; // 저장된 Account 수

	char *temp; 
	t_account *acc_arr;

	// quiz1. malloc을 활용하여 280을 할당하여 시작번지를  temp에 저장하시오.
	temp = (char*)malloc(280 * sizeof(char));
	// quiz2. temp에 저장된 메모리를 acc_arr 구조체 배열이 10개가 생성 되도록 프로그램을 작성하시오.
	acc_arr = (t_account*)temp;
	
	// 바로 위에 4라인은 교수님이 꼬아서 퀴즈를 낸 것이고, 원래 그냥 아래 라인처럼 하는게 당연한거임.
	// t_account *acc_arr = (t_account*)malloc(ACCOUNTS_MAX * sizeof(t_account)); // Account 저장을 위한 메모리 할당
	
	if (acc_arr == NULL) // 동적할당을 했으면, 반드시 해당 공간이 메모리에 제대로 할당되었는지 확인하는 과정이 필요함.
	{
		printf("메모리 할당에 실패했습니다.");
		return -1; // exit(1);
	}

	void (*fp[])(t_account*, int*) = {NULL, // enum에서 1부터 시작하도록 선언해 놓았기 때문
									make_account,
									deposit_money,
									with_draw_money,
									show_all_acc_info};

	while(1)
	{
		show_menu();
		printf("선택: ");  
		scanf("%d", &choice);
		printf("\n");

		// <command-driven>
		if (choice == 9) 
		{
			free(acc_arr); // 위에서 동적할당을 했기 때문에 잊지말고 free해줘야 함.
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
	t_account *tp = t;
	
	if (*n + 1 > ACCOUNTS_MAX) 
	{
		printf("계좌 구조체 배열이 꽉찼습니다."); 
		return;
	}

	printf("[계좌개설]\n");
	printf("계좌ID: ");	
	scanf("%d", &id);
	printf("이  름: ");	
	scanf("%s", name);
	printf("입금액: ");	
	scanf("%d", &balance);
	printf("\n");
	
	(tp + *n)->acc_id = id;
	(tp + *n)->balance = balance;
	strcpy((tp + *n)->cus_name, name);
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
	
	for (i = 0; i < *n; i++)
	{
		if(tp->acc_id == id)
		{
			tp->balance += money;
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
	
	for(i = 0; i < *n; i++)
	{
		if(tp->acc_id == id)
		{
			if(tp->balance < money)
			{
				printf("잔액부족\n\n");
				return;
			}

			tp->balance -= money;
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

	for(i = 0; i < *n; i++)
	{
		printf("계좌ID: %d\n", tp->acc_id);
		printf("이  름: %s\n", tp->cus_name);
		printf("잔  액: %d\n\n", tp->balance);
		tp++;
	}
}

#endif
