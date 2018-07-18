#ifndef __ACCOUNT_H_
#define __ACCOUNT_H_

#include "String.h"

class Account
{
private:
	int accID;		//���¹�ȣ
	String cusName; //���̸�

protected:
	int balance;	//�ܾ�

public:
	Account(int _accId, int _balance, String _cusName);
	virtual void DepositMoney(int money);
	int WithdrawMoeny(int money);
	virtual void ShowAccInfo(void) const;
	int GetAccID(void) const;
};




#endif