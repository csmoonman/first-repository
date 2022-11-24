#include<iostream>
using namespace std;

int main()
{
	int x,y;
	cin>>x;
	cin>>y;
	
	cout<<"x= "<<x<<endl;
	cout<<"y= "<<y<<endl;
	/*
	(x>y)? cout<<x: cout<<y;
	*/
	
	cout<<((x>y)?"max is x": "max is y");
}
