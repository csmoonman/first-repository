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

	//string::iterator ��������c++��һ������ָ��Ķ���
	string::iterator ch = str.begin();
	//auto ch = str.begin();
	cout << str << endl;
	while (ch != str.end())
		cout << *(ch++);
	cout << "#";

	return 0;
}