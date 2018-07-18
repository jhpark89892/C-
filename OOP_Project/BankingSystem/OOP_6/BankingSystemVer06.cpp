/*Banking System Ver 0.6
����:
	1. '���뿹�ݰ���'�� �ǹ��ϴ� NormalAccount Ŭ���� ����
	2. '�ſ�ŷڰ���'�� �ǹ��ϴ� HighCreditAccount Ŭ���� ����
*/


#include <iostream>
#include <cstring>

using namespace std;


enum {A=7, B=4, C=2};

enum {MAKE =1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

/****

Ŭ���� �̸�: Account
Ŭ���� ����: Entity Ŭ����

****/
class Account
{
private:
	int accID;		//���¹�ȣ
	char *cusName;	//���̸�

protected:
	int balance;	//�ܾ�

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
		cout<<"����ID: "<<accID<<endl;
		cout<<"�̸�: "<<cusName<<endl;
		cout<<"�ܾ�: "<<balance<<endl;
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

Ŭ���� �̸�: NormalAccount
Ŭ���� ����: Entity Ŭ����

*****/


class NormalAccount : public Account
{
private:
	int interest;	//������
public:
	NormalAccount(int _accId, int _balance, char *_cusName, int _interest)
		:Account(_accId, _balance, _cusName), interest(_interest)
	{ }

	virtual void ShowAccInfo(void) const
	{
		Account::ShowAccInfo();
		cout<<"������: "<<interest<<endl;
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

Ŭ���� �̸�: HighCreditAccount
Ŭ���� ����: Entity Ŭ����

*****/


class HighCreditAccount : public NormalAccount
{
private:
	int credit;	//�ſ���
public:
	HighCreditAccount(int _accId, int _balance, char *_cusName, int _interest, int _credit)
		: NormalAccount(_accId, _balance, _cusName, _interest), credit(_credit)
	{ }

	virtual void ShowAccInfo(void) const
	{
		NormalAccount::ShowAccInfo();
		cout<<"�ſ���(A=7, B=4, C=2): "<<credit<<endl;
	}

	virtual void DepositMoney(int money)
	{
		balance=(balance+(balance*(NormalAccount::GetInterest()+credit)/100))+money;
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
		int select;

		cout<<"[������������]"<<endl;
		cout<<"1. ���뿹�ݰ���  2. �ſ�ŷڰ���"<<endl;
		cout<<"����: ";
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
			cout<<"�߸��� �Է��Դϴ�."<<endl;
			cout<<"1 �Ǵ� 2�� �Է��ϼ���."<<endl;
		}

	}

	void MakeNormalAccount(void)
	{
		int id;
		char name[10];
		int balance;
		int interest;

		cout<<"[���뿹�ݰ��� ����]"<<endl;
		cout<<"����ID: "; cin>>id;
		cout<<"�̸�: ";  cin>>name;
		cout<<"�Աݾ�: "; cin>>balance;
		cout<<"������: "; cin>>interest;

		accArr[accNum++] = new NormalAccount(id, balance, name, interest);

	}
	void MakeCreditAccount(void)
	{
		int id;
		char name[10];
		int balance;
		int interest;
		int choice;

		cout<<"[�ſ�ŷڰ��� ����]"<<endl;
		cout<<"����ID: "; cin>>id;
		cout<<"�̸�: ";  cin>>name;
		cout<<"�Աݾ�: "; cin>>balance;
		cout<<"������: "; cin>>interest;
		cout<<"�ſ���(1toA, 2toB, 3toC): "; cin>>choice;
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
			cout<<"�ſ����� �߸� �Է��ϼ̽��ϴ�."<<endl;
			break;
		}

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
