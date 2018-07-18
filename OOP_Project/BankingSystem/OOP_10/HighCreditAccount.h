#ifndef __HIGHCREDITACCOUNT_H_
#define __HIGHCREDITACCOUNT_H_

#include "String.h"

class HighCreditAccount : public NormalAccount
{
private:
	int credit;	//�ſ���
public:
	HighCreditAccount(int _accId, int _balance, String _cusName, int _interest, int _credit)
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


#endif