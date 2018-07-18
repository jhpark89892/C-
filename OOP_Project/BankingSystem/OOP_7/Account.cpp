#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int _accId, int _balance, char *_cusName)
:accID(_accId), balance(_balance)
{
	cusName = new char[strlen(_cusName)+1];
	strcpy(cusName, _cusName);
}

Account::Account(const Account &copy)
:accID(copy.accID), balance(copy.balance)
{
	cusName = new char[strlen(copy.cusName)+1];
	strcpy(cusName, copy.cusName);
}

bool Account::MakeAccount(int _accID, int _balance, char *_cusName)
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

void Account::DepositMoney(int money)
{
	balance += money;
}

int Account::WithdrawMoeny(int money)
{
	if(balance<money)
		return 0;

	balance -= money;
	return 0;
}

void Account::ShowAccInfo(void) const
{
	cout<<"계좌ID: "<<accID<<endl;
	cout<<"이름: "<<cusName<<endl;
	cout<<"잔액: "<<balance<<endl;
}

int Account::GetAccID(void) const
{
	return accID;
}

Account::~Account()
{
	delete []cusName;
}