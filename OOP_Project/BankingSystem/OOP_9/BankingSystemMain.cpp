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
			accHandle.DepositMoney();
			break;
		case WITHDRAW:
			accHandle.WithdrawMoney();
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