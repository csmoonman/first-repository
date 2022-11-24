#include<iostream>
#include<string>
using namespace std;

int main()
{

	string str;
	getline(cin, str);
	char* pstr = &str[0];
	cout << "pstr:" << *pstr << endl;
	cout << "&pstr:" << &pstr << endl;

	//string::iterator 迭代器，c++中一种类似指针的东西
	string::iterator ch = str.begin();
	//auto ch = str.begin();
	cout << str << endl;
	while (ch != str.end())
		cout << *(ch++);
	cout << "#";

	return 0;
}