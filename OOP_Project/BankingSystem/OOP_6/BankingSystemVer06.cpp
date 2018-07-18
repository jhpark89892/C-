/*Banking System Ver 0.6
내용:
	1. '보통예금계좌'를 의미하는 NormalAccount 클래스 정의
	2. '신용신뢰계좌'를 의미하는 HighCreditAccount 클래스 정의
*/


#include <iostream>
#include <cstring>

using namespace std;


enum {A=7, B=4, C=2};

enum {MAKE =1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

/****

클래스 이름: Account
클래스 유형: Entity 클래스

****/
class Account
{
private:
	int accID;		//계좌번호
	char *cusName;	//고객이름

protected:
	int balance;	//잔액

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

	virtual void DepositMoney(int money)
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

	virtual void ShowAccInfo(void) const
	{
		cout<<"계좌ID: "<<accID<<endl;
		cout<<"이름: "<<cusName<<endl;
		cout<<"잔액: "<<balance<<endl;
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

클래스 이름: NormalAccount
클래스 유형: Entity 클래스

*****/


class NormalAccount : public Account
{
private:
	int interest;	//이자율
public:
	NormalAccount(int _accId, int _balance, char *_cusName, int _interest)
		:Account(_accId, _balance, _cusName), interest(_interest)
	{ }

	virtual void ShowAccInfo(void) const
	{
		Account::ShowAccInfo();
		cout<<"이자율: "<<interest<<endl;
	}
	
	virtual void DepositMoney(int money)
	{
		balance=(balance+(balance*interest/100))+money;
	}
	int GetInterest(void) const
	{
		return interest;
	}
};


/*****

클래스 이름: HighCreditAccount
클래스 유형: Entity 클래스

*****/


class HighCreditAccount : public NormalAccount
{
private:
	int credit;	//신용등급
public:
	HighCreditAccount(int _accId, int _balance, char *_cusName, int _interest, int _credit)
		: NormalAccount(_accId, _balance, _cusName, _interest), credit(_credit)
	{ }

	virtual void ShowAccInfo(void) const
	{
		NormalAccount::ShowAccInfo();
		cout<<"신용등급(A=7, B=4, C=2): "<<credit<<endl;
	}

	virtual void DepositMoney(int money)
	{
		balance=(balance+(balance*(NormalAccount::GetInterest()+credit)/100))+money;
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
		int select;

		cout<<"[계좌종류선택]"<<endl;
		cout<<"1. 보통예금계좌  2. 신용신뢰계좌"<<endl;
		cout<<"선택: ";
		cin>>select;

		if(select == 1)
		{
			MakeNormalAccount();
		}
		else if(select == 2)
		{
			MakeCreditAccount();

		}
		else
		{
			cout<<"잘못된 입력입니다."<<endl;
			cout<<"1 또는 2를 입력하세요."<<endl;
		}

	}

	void MakeNormalAccount(void)
	{
		int id;
		char name[10];
		int balance;
		int interest;

		cout<<"[보통예금계좌 개설]"<<endl;
		cout<<"계좌ID: "; cin>>id;
		cout<<"이름: ";  cin>>name;
		cout<<"입금액: "; cin>>balance;
		cout<<"이자율: "; cin>>interest;

		accArr[accNum++] = new NormalAccount(id, balance, name, interest);

	}
	void MakeCreditAccount(void)
	{
		int id;
		char name[10];
		int balance;
		int interest;
		int choice;

		cout<<"[신용신뢰계좌 개설]"<<endl;
		cout<<"계좌ID: "; cin>>id;
		cout<<"이름: ";  cin>>name;
		cout<<"입금액: "; cin>>balance;
		cout<<"이자율: "; cin>>interest;
		cout<<"신용등급(1toA, 2toB, 3toC): "; cin>>choice;
		switch(choice)
		{
		case 1:
			accArr[accNum++] = new HighCreditAccount(id, balance, name, interest, A);
			break;

		case 2:
			accArr[accNum++] = new HighCreditAccount(id, balance, name, interest, B);
			break;

		case 3:
			accArr[accNum++] = new HighCreditAccount(id, balance, name, interest, C);
			break;

		default:
			cout<<"신용등급을 잘못 입력하셨습니다."<<endl;
			break;
		}

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
