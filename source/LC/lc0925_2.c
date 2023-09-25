#if 1
/////////////////////////////////////////
// 아래의 프로그램을 
//  구조체를 화일 pointer및 fseek, rewind로 구현 
/////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define NAME_LEN   20

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT=9};

typedef struct 
{
	int acc_id;     // 계좌번호
	int balance;    // 잔    액
	char cus_name[NAME_LEN];   // 고객이름
} t_account;

void show_menu(void);       	// 메뉴출력
void make_account(t_account *t, int *n);       	// 계좌개설을 위한 함수
void deposit_money(t_account *t, int *n);       // 입    금
void with_draw_money(t_account *t, int *n);		// 출    금
void show_all_acc_info(t_account *t, int *n);	// 잔액조회

FILE *filep; // 전역변수로 선언
	
int main(void)
{
	int choice;
	int acc_num=0;        		// 저장된 Account 수	
	
	t_account acc_arr[10];   	// Account 저장을 위한 배열


	void (*fp[]) (t_account *t, int *n) =
	{
		NULL,
	   	make_account,
	   	deposit_money,
	   	with_draw_money,
	   	show_all_acc_info
	};
	
	if ( (filep = fopen("source\\lc\\lc0925_2_money_file", "wb+")) == NULL)  // 
	{
		fprintf(stderr, "can't Open file wb+ : money_file....\n");
		exit(1);  
	}

	while(1)
	{
		show_menu();
		printf("선택: ");  
		scanf("%d", &choice);
		printf("\n");
		
		if (choice == EXIT) 
		{
			fclose(filep);
			return 0;
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

	}
	return 0;
}

void show_menu(void)
{
	int i;
	
	char *m[] = 
	{
	 "-----Menu------\n",
	 "1. 계좌개설\n",
	 "2. 입    금\n",
	 "3. 출    금\n",
	 "4. 계좌정보 전체 출력\n",
	 "9. 종    료\n"		
	};

	for (i=0; i < 6; i++)
		printf("%s", m[i]);
}

void make_account(t_account *t, int *n) 
{
	int id,i;
	int balance;
	char name[NAME_LEN];
	t_account *tp;
	
	printf("[계좌개설]\n");
	printf("계좌ID: ");	
	scanf("%d", &id);
	printf("이  름: ");	
	scanf("%s", name);
	printf("입금액: ");	
	scanf("%d", &balance);
	printf("\n");
	
	tp = t + *n;
	
	rewind(filep);
	
	for (i=0; ; i++)
	{
		if (fread( (char *) &tp->acc_id, 1, sizeof(t_account), filep) == 0 )
		{
			break;
		}
		else if (tp->acc_id == id)
		{
			printf("Already exist ID %d\n", id); 
			return;  
		}
	
	}
	
	fseek(filep, 0, SEEK_END);

	tp->acc_id=id;
	tp->balance=balance;
	strcpy(tp->cus_name,name);
	fwrite( (char *) &tp->acc_id, 1,sizeof(t_account), filep);

	*n = *n+1;
	 
}

void deposit_money(t_account *t, int *n)
{
	int money;
	int id, i, size;
	t_account *tp=t;
		
	printf("[입    금]\n");
	printf("계좌ID: ");
	scanf("%d", &id);
	printf("입금액: ");
	scanf("%d", &money);

	rewind(filep);
	
	for (i=0; i < *n; i++, tp++)
	{
		if (fread( (char *) &tp->acc_id, 1, sizeof(t_account), filep) == 0 )
		{
			break;
		}
		else if(tp->acc_id==id)
		{
			tp->balance += money;
			size = sizeof(t_account); 
			fseek(filep, -size, SEEK_CUR); // 여기가 key point
			fwrite( (char *) &tp->acc_id, 1, sizeof(t_account), filep);
			printf("입금완료\n\n");
			return;
		}
	}
	printf("유효하지 않은 ID 입니다.\n\n");
}

void with_draw_money(t_account *t, int *n)
{
	int money;
	int id, i, size;
	t_account *tp = t;

	printf("[출    금]\n");
	printf("계좌ID: ");
	scanf("%d", &id);
	printf("출금액: ");
	scanf("%d", &money);
	
	rewind(filep);
	
	for(i=0; i < *n; i++)
	{
		if (fread( (char *) &tp->acc_id, 1, sizeof(t_account), filep) == 0 )
		{
			break;
		}
		else if(tp->acc_id==id)
		{
			if (tp->balance < money)
			{
				printf("잔액부족\n\n");
				return;
			}

			tp->balance -= money;
			size = sizeof(t_account); 
			fseek(filep, -size, SEEK_CUR);
			fwrite( (char *) &tp->acc_id, 1, sizeof(t_account), filep);
			printf("출금완료\n\n");
			return;
		}
	}
	printf("유효하지 않은 ID 입니다.\n\n");
}

void show_all_acc_info(t_account *t, int *n)	
{
	int i;
	t_account *tp = t;
	
	rewind(filep);
	
	for(i=0; i < *n; i++,tp++)
	{
		if (fread( (char *) &tp->acc_id, 1, sizeof(t_account), filep) == 0 )
		{
			break;
		}
		printf("계좌ID: %d\n", tp->acc_id);
		printf("이  름: %s\n", tp->cus_name);
		printf("잔  액: %d\n\n", tp->balance);
	}
	printf("\n");
}
#endif
