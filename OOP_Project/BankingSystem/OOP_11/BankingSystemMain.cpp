#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void)
{
	int choice;
	AccountHandler accHandle;

	while(1)
	{
		accHandle.ShowMenu();

		cout<<"¼±ÅÃ: ";
		cin>>choice;
		cout<<endl;

		switch(choice)
		{
		case MAKE:
			accHandle.MakeAccount();
			break;
		case DEPOSIT:
			try
			{
				accHandle.DepositMoney();
			}
			catch(DepositException& expn)
			{
				expn.ShowExceptionInfo();
			}
			break;
		case WITHDRAW:
			try
			{
				accHandle.WithdrawMoney();
			}
			catch(WithdrawException& expn)
			{
				expn.ShowExceptionInfo();
			}
			break;
		case INQUIRE:
			accHandle.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout<<"Illegal selection.."<<endl;
		}
	}

	return 0;

}