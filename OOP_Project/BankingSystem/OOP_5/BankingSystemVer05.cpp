/*Banking System Ver 0.5
����: 
	1. AccountHandler ��� ��Ʈ�� Ŭ���� ����, �ռ� ������ �����Լ����� �� Ŭ������ ��� �Լ��� ����
	2. Account ��ü�� ������ ���� ������ �迭�� ������ �� Ŭ������ ����� ����
	3. AccountHandler Ŭ���� ������� ���α׷��� ����ǵ��� main�Լ��� ����
*/


#include <iostream>
#include <cstring>

using namespace std;



/****

Ŭ���� �̸�: Account
Ŭ���� ����: Entity Ŭ����

****/
class Account
{
private:
	int accID;		//���¹�ȣ
	int balance;	//�ܾ�
	char *cusName;	//���̸�

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



/*****

Ŭ���� �̸�: AccountHandler
Ŭ���� ����: control Ŭ����

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

		accArr[accNum++] = new Account(id, balance, name);
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

		cout<<"����: ";
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
