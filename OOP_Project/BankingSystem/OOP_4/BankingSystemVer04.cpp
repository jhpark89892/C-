/*
Banking system Ver 0.4
내용 : const로 선언이 가능한 모든 멤버함수를 const로 선언

*/


#include <iostream>
#include <cstring>

using namespace std;


class Account
{
private:
	int accID;		//계좌번호
	int balance;	//잔액
	char *cusName;	//고객이름

public:
	Account()
		:accID(0), balance(0), cusName(0)
	{
	}

	Account(const Account &copy)
		:accID(copy.accID), balance(copy.balance)
	{
		cusName = new char[strlen(copy.cusName)+1];
		strcpy(cusName, copy.cusName);
	}

	bool MakeAccount(int _accID, int _balance, char *_cusName)
	{
		if(accID == _accID)
		{
			cout<<"이미 있는 계정입니다."<<endl;
			return false;
		}
		
		accID = _accID;
		balance = _balance;
		cusName = new char[strlen(_cusName)+1];
		strcpy(cusName, _cusName);
		return true;
	}

	void DepositMoney(int money)
	{
		balance += money;
	}

	int WithdrawMoeny(int money)
	{
		if(balance<money)
			return 0;

		balance -= money;
		return 0;
	}

	void ShowAccInfo(void) const
	{
		cout<<"계좌ID: "<<accID<<endl;
		cout<<"이름: "<<cusName<<endl;
		cout<<"잔액: "<<balance<<endl;
		cout<<endl;
	}

	int GetAccID(void) const
	{
		return accID;
	}

	~Account()
	{
		delete []cusName;
	}
};



void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);


enum {MAKE =1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
int accNum = 0;
Account *accArr[100];

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
			for(int i=0; i<accNum; i++)
				delete accArr[i];
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
	char *name = (char*)malloc(sizeof(char) *10);
	int balance;

	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: "; cin>>id;
	cout<<"이름: ";  cin>>name;
	cout<<"입금액: "; cin>>balance;
	
	accArr[accNum] = new Account;
	accArr[accNum]->MakeAccount(id, balance, name);
	accNum++;
	free(name);
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
		if(accArr[i]->GetAccID() ==id)
		{
			accArr[i]->DepositMoney(money);
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
		if(accArr[i]->GetAccID() ==id)
		{
			if(accArr[i]->WithdrawMoeny(money)==0)
			{
				cout<<"잔액부족"<<endl<<endl;
				return;
			}

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
		accArr[i]->ShowAccInfo();
	}
}
