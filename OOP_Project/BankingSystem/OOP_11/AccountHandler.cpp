#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String"



AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::AddAccount(Account *acc)
{
	accArr[accNum++];
}

void AccountHandler::ShowMenu(void)	const
{
	cout<<"----- Menu -----"<<endl;
	cout<<"1. ���°���"<<endl;
	cout<<"2. �� ��"<<endl;
	cout<<"3. �� ��"<<endl;
	cout<<"4. �������� ��ü���"<<endl;
	cout<<"5. ���α׷� ����"<<endl;
}

void AccountHandler::MakeAccount(void)
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

void AccountHandler::MakeNormalAccount(void)
{
	int id;
	String name;
	int balance;
	int interest;

	cout<<"[���뿹�ݰ��� ����]"<<endl;
	cout<<"����ID: "; cin>>id;
	for(int i=0;i<accNum;i++)
	{
		if(accArr[i]->GetAccID()==id)
		{
			cout<<"�̹� �����ϴ� ID�Դϴ�."<<endl;
			return;
		}
	}

	cout<<"�̸�: ";  cin>>name;
	cout<<"�Աݾ�: "; cin>>balance;
	cout<<"������: "; cin>>interest;

	accArr[accNum++] = new NormalAccount(id, balance, name, interest);

}
void AccountHandler::MakeCreditAccount(void)
{
	int id;
	String name;
	int balance;
	int interest;
	int choice;

	cout<<"[�ſ�ŷڰ��� ����]"<<endl;
	cout<<"����ID: "; cin>>id;
	for(int i=0;i<accNum;i++)
	{
		if(accArr[i]->GetAccID()==id)
		{
			cout<<"�̹� �����ϴ� ID�Դϴ�."<<endl;
			return;
		}
	}
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

void AccountHandler::DepositMoney(void)
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
			if(money<0)
			{
				throw DepositException(money);
			}
			accArr[i]->DepositMoney(money);
			cout<<"�ԱݿϷ�"<<endl<<endl;
			return;
		}
	}
	cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
}

void AccountHandler::WithdrawMoney(void)
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


void AccountHandler::ShowAllAccInfo(void) const
{
	for(int i=0;i<accNum;i++)
	{
		accArr[i]->ShowAccInfo();
	}
}

AccountHandler::~AccountHandler()
{
	for(int i=0;i<accNum;i++)
	{
		delete accArr[i];
	}
}
