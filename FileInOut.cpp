#include <iostream>
#include <fstream>
#include <string>
#include <sstream>	//ostringstream

using namespace std;

class User
{
private:
	string name;
	int age;

public:
	User(string _name, int _age) : name(_name), age(_age) { }
	string getInfo()
	{
		//int to string
		ostringstream ostr;
		ostr<<age;

		return "name: "+name+"age: "+ostr.str();
	}
	friend ofstream& operator<<(ofstream& of, User& usr);

};


ofstream& operator<<(ofstream& outFile, User& usr)
{
	outFile<<usr.getInfo();
	return outFile;
}


int main()
{
	User usr1("Hong Gil Dong", 88);
	string filePath = "test.txt";

	//write File
	ofstream writeFile(filePath.data());
	if(writeFile.is_open())
	{
		writeFile<<usr1;
		writeFile.close();
	}
	else
		cout<<"File Open Failed!!"<<endl;


	//readFile
	ifstream openFile(filePath.data());
	if(openFile.is_open())
	{
		string line;
		while(getline(openFile, line))
			cout<<line<<endl;
		openFile.close();
	}
	else
		cout<<"File Open Failed!!"<<endl;
	

	return 0;
}



//#include <fstream>
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	string filePath = "test.txt";
//
//	// write File
//	ofstream writeFile(filePath.data());
//	if( writeFile.is_open() ){
//		writeFile << "Hello World!\n";
//		writeFile << "This is C++ File Contents.\n";
//		writeFile.close();
//	}
//
//	// read File
//	ifstream openFile(filePath.data());
//	if( openFile.is_open() ){
//		string line;
//		while(getline(openFile, line)){
//			cout << line << endl;
//		}
//		openFile.close();
//	}
//
//	return 0;
//}
