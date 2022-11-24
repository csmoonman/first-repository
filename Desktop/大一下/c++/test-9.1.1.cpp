#include<iostream>

using namespace std;

int main()
{
	
	string str;
	getline(cin,str);
	char* pstr = &str[0];
	cout<<"pstr:"<<*pstr<<endl;
	cout<<"&pstr:"<<&pstr<<endl;
	
	string::iterator ch =str.begin();
	cout<<str<<endl;
	while(ch!=str.end())
		cout<<*(ch++);
	cout<<"#"<<endl;
	
	string str2[3]={"I","love","you"};
	for(int i=0;i<3;i++)
		cout<<str2[i]<<" ";	
	
	/*
	cout<<"begin "<<str.begin()<<endl;
	cout<<"end "<<str.end()<<endl;
	cout<<"rbegin "<<str.rbegin()<<endl;
	cout<<"rend "<<str.rend()<<endl;
	*/
	
	/*
	for(char ch;(ch=getchar())!='\n';)
	{
		cout<<char(ch);
	}
	cout<<endl;
	*/
	
	return 0;
 } 
