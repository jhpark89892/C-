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
		cout<<money<<"�� 0���� ���� ���Դϴ�."<<endl;
	}
};

class WithdrawException
{
public:
	void ShowExceptionInfo()
	{
		cout<<"�ܾ׺���"<<endl;
	}
};


#endif