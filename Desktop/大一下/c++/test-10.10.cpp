#include<iostream>

using namespace std;

int main()
{
	char ch;
	char a[10];
	cin.getline(a,10);
	cin.clear();
		while(cin.get()!='\n');
	cout<<a<<endl;
	string s;
	getline(cin,s);
	cout<<s<<endl;
} 
