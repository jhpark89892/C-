#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int _accId, int _balance, String _cusName)
:accID(_accId), balance(_balance)
{
	cusName = _cusName;
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
	cout<<"����ID: "<<accID<<endl;
	cout<<"�̸�: "<<cusName<<endl;
	cout<<"�ܾ�: "<<balance<<endl;
}

int Account::GetAccID(void) const
{
	return accID;
}
