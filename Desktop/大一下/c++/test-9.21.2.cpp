#include<iostream>

int main()
{
	using namespace std;
	char a[10];
	char* pa=a;
	cin.getline(pa,10);
	cout<<a<<endl;
	cout<<(int*)a<<endl;
	cout<<(int*)pa<<endl;
	cout<<&a<<endl;
	cout<<&(a[0])<<endl;
	cout<<*a<<endl;
 } 
