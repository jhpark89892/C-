//Banking system ver 1.0

#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN=20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE =1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
	int accID;		//계좌번호
	int balance;	//잔액
	char cusName[NAME_LEN];	//고객이름

}Account;

Account accArr[100];
int accNum=0;

int main(void)
{
	int choice;

	while(1)
	{
		ShowMenu();
		cout<<"선택: ";
		cin>>choice;
		cout<<endl;

		switch(choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout<<"Illegal selection.."<<endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout<<"----- Menu -----"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: "; cin>>id;
	cout<<"이름: ";  cin>>name;
	cout<<"입금액: "; cin>>balance;

	accArr[accNum].accID=id;
	accArr[accNum].balance=balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney(void)
{
	int money;
	int id;
	cout<<"[입 금]"<<endl;
	cout<<"계좌ID: "; cin>>id;
	cout<<"입금액: "; cin>>money;

	for(int i=0;i<accNum;i++)
	{
		if(accArr[i].accID==id)
		{
			accArr[i].balance += money;
			cout<<"입금완료"<<endl<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout<<"[출 금]"<<endl;
	cout<<"계좌ID: "; cin>>id;
	cout<<"출금액: "; cin>>money;

	for(int i=0; i<accNum; i++)
	{
		if(accArr[i].accID==id)
		{
			if(accArr[i].balance<money)
			{
				cout<<"잔액부족"<<endl<<endl;
				return;
			}
			accArr[i].balance -= money;
			cout<<"출금완료"<<endl<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void ShowAllAccInfo(void)
{
	for(int i=0;i<accNum;i++)
	{
		cout<<"계좌ID: "<<accArr[i].accID<<endl;
		cout<<"이름: "<<accArr[i].cusName<<endl;
		cout<<"잔액: "<<accArr[i].balance<<endl;
	}
}

/*******

Banking system Ver 1.0
내용 : OOP 단계별 프로젝트의 기본 틀 구성

*******/

//
//#include<iostream>
//
//#define BUF_SIZE 30
//
//using namespace std;
//
//typedef struct __info{
//	char name[BUF_SIZE];
//	int account;
//	int money;
//}INFO;
//
//void DisplayMenu(void)
//{
//
//	cout<<"----- Menu -----"<<endl;
//	cout<<"1. 계좌개설"<<endl;
//	cout<<"2. 입 금"<<endl;
//	cout<<"3. 출 금"<<endl;
//	cout<<"4. 계좌정보 전체출력"<<endl;
//	cout<<"5. 프로그램 종료"<<endl;
//
//}
//int main()
//{
//	int choice, i, num=0, id=0;
//	int flag = 0;
//	int cus_cnt = 0;
//	INFO customer[BUF_SIZE];
//
//	while(1)
//	{
//		DisplayMenu();
//		cout<<"선택: ";
//		cin>>choice;
//		cout<<endl;
//
//		switch(choice)
//		{
//
//		case 1:
//			cout<<"[계좌개설]"<<endl<<endl;
//			cout<<"계좌ID : ";
//			cin>>customer[cus_cnt].account;
//
//			cout<<"이름 : ";
//			cin>>customer[cus_cnt].name;
//
//			cout<<"입금액 : ";
//			cin>>customer[cus_cnt].money;
//
//			cus_cnt++;
//			
//			break;
//
//		case 2:
//			cout<<"[입금]"<<endl<<endl;
//			cout<<"계좌ID: ";
//			cin>>id;
//			for(i=0; i<cus_cnt; i++)
//			{
//				if(id == customer[i].account)
//				{
//					flag = 1;
//					cout<<"입금액: ";
//					cin>>num;
//					customer[i].money += num;
//					cout<<"입금 후 잔액: "<<customer[i].money<<endl;
//
//					cout<<"입금완료"<<endl;
//					break;
//				}
//			}
//			if(flag == 0)
//			{
//				cout<<"계좌에 없는 ID입니다."<<endl;
//				break;
//			}			
//			break;
//		case 3:
//			cout<<"[출 금]"<<endl<<endl;
//			cout<<"계좌ID: ";
//			cin>>id;
//			for(i=0; i<cus_cnt; i++)
//			{
//				if(id == customer[i].account)
//				{
//					flag = 1;
//					cout<<"출금액: ";
//					cin>>num;
//					customer[i].money -= num;
//					cout<<"출금 후 잔액: "<<customer[i].money<<endl;
//
//					cout<<"출금완료"<<endl;
//					break;
//				}
//			}
//			if(flag == 0)
//			{
//				cout<<"계좌에 없는 ID입니다."<<endl;
//				break;
//			}
//			break;
//
//		case 4:
//			
//			cout<<"[전체출력]"<<endl<<endl;
//			for(i=0;i<cus_cnt;i++)
//			{
//				cout<<"계좌ID: "<<customer[i].account<<endl;
//				cout<<"이름: "<<customer[i].name<<endl;
//				cout<<"잔액: "<<customer[i].money<<endl;
//				cout<<"---------------------------"<<endl;
//			}
//			
//			break;
//
//		case 5:
//			cout<<"프로그램을 종료합니다."<<endl;
//			goto END;
//
//		default :
//			cout<<"1 ~ 5 사이의 값을 입력하세요"<<endl;
//			break;
//		}
//
//		flag = 0;
//	}
//
//
//END:
//	return 0;
//
//}
//
