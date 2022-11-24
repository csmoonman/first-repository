#include<iostream>

struct member
{
	char name[20];
	short age;
	union contact
	{
		char WeChat[30];
		long long QQ;
	}Mcontact;
};

int main()
{
	using namespace std;
	member father;
	father.age=56;
	cin>>father.Mcontact.WeChat;
	cout<<"charactor:father, "<<"age:"<<father.age<<", "<<"contact:"<<father.Mcontact.WeChat<<endl;
	
}
