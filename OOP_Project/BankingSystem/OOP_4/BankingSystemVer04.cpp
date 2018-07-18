/*
Banking system Ver 0.4
���� : const�� ������ ������ ��� ����Լ��� const�� ����

*/


#include <iostream>
#include <cstring>

using namespace std;


class Account
{
private:
	int accID;		//���¹�ȣ
	int balance;	//�ܾ�
	char *cusName;	//���̸�

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
			cout<<"�̹� �ִ� �����Դϴ�."<<endl;
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
		cout<<"����ID: "<<accID<<endl;
		cout<<"�̸�: "<<cusName<<endl;
		cout<<"�ܾ�: "<<balance<<endl;
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
		cout<<"����: ";
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
	cout<<"1. ���°���"<<endl;
	cout<<"2. �� ��"<<endl;
	cout<<"3. �� ��"<<endl;
	cout<<"4. �������� ��ü���"<<endl;
	cout<<"5. ���α׷� ����"<<endl;
}

void MakeAccount(void)
{
	int id;
	char *name = (char*)malloc(sizeof(char) *10);
	int balance;

	cout<<"[���°���]"<<endl;
	cout<<"����ID: "; cin>>id;
	cout<<"�̸�: ";  cin>>name;
	cout<<"�Աݾ�: "; cin>>balance;
	
	accArr[accNum] = new Account;
	accArr[accNum]->MakeAccount(id, balance, name);
	accNum++;
	free(name);
}

void DepositMoney(void)
{
	int money;
	int id;
	cout<<"[�� ��]"<<endl;
	cout<<"����ID: "; cin>>id;
	cout<<"�Աݾ�: "; cin>>money;

	for(int i=0;i<accNum;i++)
	{
		if(accArr[i]->GetAccID() ==id)
		{
			accArr[i]->DepositMoney(money);
			cout<<"�ԱݿϷ�"<<endl<<endl;
			return;
		}
	}
	cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout<<"[�� ��]"<<endl;
	cout<<"����ID: "; cin>>id;
	cout<<"��ݾ�: "; cin>>money;

	for(int i=0; i<accNum; i++)
	{
		if(accArr[i]->GetAccID() ==id)
		{
			if(accArr[i]->WithdrawMoeny(money)==0)
			{
				cout<<"�ܾ׺���"<<endl<<endl;
				return;
			}

			cout<<"��ݿϷ�"<<endl<<endl;
			return;
		}
	}
	cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
}

void ShowAllAccInfo(void)
{
	for(int i=0;i<accNum;i++)
	{
		accArr[i]->ShowAccInfo();
	}
}
