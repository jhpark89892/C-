//Banking system ver 1.0

#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN=20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE =1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
	int accID;		//���¹�ȣ
	int balance;	//�ܾ�
	char cusName[NAME_LEN];	//���̸�

}Account;

Account accArr[100];
int accNum=0;

int main(void)
{
	int choice;

	while(1)
	{
		ShowMenu();
		cout<<"����: ";
		cin>>choice;
		cout<<endl;

		switch(choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout<<"Illegal selection.."<<endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout<<"----- Menu -----"<<endl;
	cout<<"1. ���°���"<<endl;
	cout<<"2. �� ��"<<endl;
	cout<<"3. �� ��"<<endl;
	cout<<"4. �������� ��ü���"<<endl;
	cout<<"5. ���α׷� ����"<<endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout<<"[���°���]"<<endl;
	cout<<"����ID: "; cin>>id;
	cout<<"�̸�: ";  cin>>name;
	cout<<"�Աݾ�: "; cin>>balance;

	accArr[accNum].accID=id;
	accArr[accNum].balance=balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney(void)
{
	int money;
	int id;
	cout<<"[�� ��]"<<endl;
	cout<<"����ID: "; cin>>id;
	cout<<"�Աݾ�: "; cin>>money;

	for(int i=0;i<accNum;i++)
	{
		if(accArr[i].accID==id)
		{
			accArr[i].balance += money;
			cout<<"�ԱݿϷ�"<<endl<<endl;
			return;
		}
	}
	cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout<<"[�� ��]"<<endl;
	cout<<"����ID: "; cin>>id;
	cout<<"��ݾ�: "; cin>>money;

	for(int i=0; i<accNum; i++)
	{
		if(accArr[i].accID==id)
		{
			if(accArr[i].balance<money)
			{
				cout<<"�ܾ׺���"<<endl<<endl;
				return;
			}
			accArr[i].balance -= money;
			cout<<"��ݿϷ�"<<endl<<endl;
			return;
		}
	}
	cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
}

void ShowAllAccInfo(void)
{
	for(int i=0;i<accNum;i++)
	{
		cout<<"����ID: "<<accArr[i].accID<<endl;
		cout<<"�̸�: "<<accArr[i].cusName<<endl;
		cout<<"�ܾ�: "<<accArr[i].balance<<endl;
	}
}

/*******

Banking system Ver 1.0
���� : OOP �ܰ躰 ������Ʈ�� �⺻ Ʋ ����

*******/

//
//#include<iostream>
//
//#define BUF_SIZE 30
//
//using namespace std;
//
//typedef struct __info{
//	char name[BUF_SIZE];
//	int account;
//	int money;
//}INFO;
//
//void DisplayMenu(void)
//{
//
//	cout<<"----- Menu -----"<<endl;
//	cout<<"1. ���°���"<<endl;
//	cout<<"2. �� ��"<<endl;
//	cout<<"3. �� ��"<<endl;
//	cout<<"4. �������� ��ü���"<<endl;
//	cout<<"5. ���α׷� ����"<<endl;
//
//}
//int main()
//{
//	int choice, i, num=0, id=0;
//	int flag = 0;
//	int cus_cnt = 0;
//	INFO customer[BUF_SIZE];
//
//	while(1)
//	{
//		DisplayMenu();
//		cout<<"����: ";
//		cin>>choice;
//		cout<<endl;
//
//		switch(choice)
//		{
//
//		case 1:
//			cout<<"[���°���]"<<endl<<endl;
//			cout<<"����ID : ";
//			cin>>customer[cus_cnt].account;
//
//			cout<<"�̸� : ";
//			cin>>customer[cus_cnt].name;
//
//			cout<<"�Աݾ� : ";
//			cin>>customer[cus_cnt].money;
//
//			cus_cnt++;
//			
//			break;
//
//		case 2:
//			cout<<"[�Ա�]"<<endl<<endl;
//			cout<<"����ID: ";
//			cin>>id;
//			for(i=0; i<cus_cnt; i++)
//			{
//				if(id == customer[i].account)
//				{
//					flag = 1;
//					cout<<"�Աݾ�: ";
//					cin>>num;
//					customer[i].money += num;
//					cout<<"�Ա� �� �ܾ�: "<<customer[i].money<<endl;
//
//					cout<<"�ԱݿϷ�"<<endl;
//					break;
//				}
//			}
//			if(flag == 0)
//			{
//				cout<<"���¿� ���� ID�Դϴ�."<<endl;
//				break;
//			}			
//			break;
//		case 3:
//			cout<<"[�� ��]"<<endl<<endl;
//			cout<<"����ID: ";
//			cin>>id;
//			for(i=0; i<cus_cnt; i++)
//			{
//				if(id == customer[i].account)
//				{
//					flag = 1;
//					cout<<"��ݾ�: ";
//					cin>>num;
//					customer[i].money -= num;
//					cout<<"��� �� �ܾ�: "<<customer[i].money<<endl;
//
//					cout<<"��ݿϷ�"<<endl;
//					break;
//				}
//			}
//			if(flag == 0)
//			{
//				cout<<"���¿� ���� ID�Դϴ�."<<endl;
//				break;
//			}
//			break;
//
//		case 4:
//			
//			cout<<"[��ü���]"<<endl<<endl;
//			for(i=0;i<cus_cnt;i++)
//			{
//				cout<<"����ID: "<<customer[i].account<<endl;
//				cout<<"�̸�: "<<customer[i].name<<endl;
//				cout<<"�ܾ�: "<<customer[i].money<<endl;
//				cout<<"---------------------------"<<endl;
//			}
//			
//			break;
//
//		case 5:
//			cout<<"���α׷��� �����մϴ�."<<endl;
//			goto END;
//
//		default :
//			cout<<"1 ~ 5 ������ ���� �Է��ϼ���"<<endl;
//			break;
//		}
//
//		flag = 0;
//	}
//
//
//END:
//	return 0;
//
//}
//
