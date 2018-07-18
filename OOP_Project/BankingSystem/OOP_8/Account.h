#ifndef __ACCOUNT_H_
#define __ACCOUNT_H_


class Account
{
private:
	int accID;		//���¹�ȣ
	char *cusName;	//���̸�

protected:
	int balance;	//�ܾ�

public:
	Account(int _accId, int _balance, char *_cusName);
	Account(const Account &copy);

	bool MakeAccount(int _accID, int _balance, char *_cusName);
	virtual void DepositMoney(int money);
	int WithdrawMoeny(int money);
	virtual void ShowAccInfo(void) const;
	int GetAccID(void) const;
	Account& operator=(const Account& ref);

	
	~Account();
};




#endif