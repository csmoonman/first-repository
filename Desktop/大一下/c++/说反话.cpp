#include<iostream>
using namespace std;

int main()
{
	int i=0;
	char word[80][81];
	while(cin>>word[i++]&&cin.get()!='\n');
	while(--i)
		cout<<word[i]<<" ";
	cout<<word[0] ;
	
}
