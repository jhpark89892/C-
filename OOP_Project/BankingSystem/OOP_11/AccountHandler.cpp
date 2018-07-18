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
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
}

void AccountHandler::MakeAccount(void)
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

void AccountHandler::MakeNormalAccount(void)
{
	int id;
	String name;
	int balance;
	int interest;

	cout<<"[보통예금계좌 개설]"<<endl;
	cout<<"계좌ID: "; cin>>id;
	for(int i=0;i<accNum;i++)
	{
		if(accArr[i]->GetAccID()==id)
		{
			cout<<"이미 존재하는 ID입니다."<<endl;
			return;
		}
	}

	cout<<"이름: ";  cin>>name;
	cout<<"입금액: "; cin>>balance;
	cout<<"이자율: "; cin>>interest;

	accArr[accNum++] = new NormalAccount(id, balance, name, interest);

}
void AccountHandler::MakeCreditAccount(void)
{
	int id;
	String name;
	int balance;
	int interest;
	int choice;

	cout<<"[신용신뢰계좌 개설]"<<endl;
	cout<<"계좌ID: "; cin>>id;
	for(int i=0;i<accNum;i++)
	{
		if(accArr[i]->GetAccID()==id)
		{
			cout<<"이미 존재하는 ID입니다."<<endl;
			return;
		}
	}
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

void AccountHandler::DepositMoney(void)
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
			if(money<0)
			{
				throw DepositException(money);
			}
			accArr[i]->DepositMoney(money);
			cout<<"입금완료"<<endl<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void AccountHandler::WithdrawMoney(void)
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
