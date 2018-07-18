#ifndef __HIGHCREDITACCOUNT_H_
#define __HIGHCREDITACCOUNT_H_


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


#endif