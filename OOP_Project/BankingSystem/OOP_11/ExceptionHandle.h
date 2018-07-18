#ifndef __EXCEPTION_HANDLE_H_
#define __EXCEPTION_HANDLE_H_
#include <iostream>
using namespace std;

class DepositException
{
private:
	int money;
public:
	DepositException(int _money) : money(_money) { }
	void ShowExceptionInfo()
	{
		cout<<money<<"은 0보다 작은 값입니다."<<endl;
	}
};

class WithdrawException
{
public:
	void ShowExceptionInfo()
	{
		cout<<"잔액부족"<<endl;
	}
};


#endif