/*Banking System Ver 0.5
내용: 
	1. AccountHandler 라는 컨트롤 클래스 정의, 앞서 정의한 전역함수들을 이 클래스의 멤버 함수에 포함
	2. Account 객체의 저장을 위해 선언한 배열과 변수도 이 클래스의 멤버에 포함
	3. AccountHandler 클래스 기반으로 프로그램이 실행되도록 main함수를 변경
*/


#include <iostream>
#include <cstring>

using namespace std;



/****

클래스 이름: Account
클래스 유형: Entity 클래스

****/
class Account
{
private:
	int accID;		//계좌번호
	int balance;	//잔액
	char *cusName;	//고객이름

public:
	Account(int _accId, int _balance, char *_cusName)
		:accID(_accId), balance(_balance)
	{
		cusName = new char[strlen(_cusName)+1];
		strcpy(cusName, _cusName);
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



/*****

클래스 이름: AccountHandler
클래스 유형: control 클래스

*****/
class AccountHandler
{
private:
	int accNum;
	Account *accArr[100];
public:
	AccountHandler() : accNum(0) {}

	void AddAccount(Account *acc)
	{
		accArr[accNum++];
	}

	void ShowMenu(void)	const
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

		accArr[accNum++] = new Account(id, balance, name);
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


	void ShowAllAccInfo(void) const
	{
		for(int i=0;i<accNum;i++)
		{
			accArr[i]->ShowAccInfo();
		}
	}

	~AccountHandler()
	{
		for(int i=0;i<accNum;i++)
		{
			delete accArr[i];
		}
	}

};

enum {MAKE =1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

int main(void)
{
	int choice;
	AccountHandler accHandle;

	while(1)
	{
		accHandle.ShowMenu();

		cout<<"선택: ";
		cin>>choice;
		cout<<endl;

		switch(choice)
		{
		case MAKE:
			accHandle.MakeAccount();
			break;
		case DEPOSIT:
			accHandle.DepositMoney();
			break;
		case WITHDRAW:
			accHandle.WithdrawMoney();
			break;
		case INQUIRE:
			accHandle.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout<<"Illegal selection.."<<endl;
		}
	}

	return 0;

}
