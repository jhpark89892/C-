#ifndef __NORMALACCOUNT_H_
#define __NORMALACCOUNT_H_

#include "String.h"

class NormalAccount : public Account
{
private:
	int interest;	//이자율
public:
	NormalAccount(int _accId, int _balance, String _cusName, int _interest)
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



#endif