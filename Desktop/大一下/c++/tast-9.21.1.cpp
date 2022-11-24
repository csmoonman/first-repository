#include<iostream>

int main()
{
	using namespace std;
	
	char s[6];
	cin.get(s,6); 
	while(char ch=cin.get()!=10);
	char ch1=cin.get();
	char ch2=cin.get();
	char ch3=cin.get();
	cout<<ch1<<ch2<<ch3;
	//if(cin.get()==10) cout<<"there have a \' \'"<<endl;
	//else cout<<"nothing there"<<endl;
	
	
	/*cin.getline()对末尾回车键的处理 
	char s[6];
	cin.getline(s,6);
	char ch=cin.get();
	cout<<(int)ch;
	//if(cin.get()==10) cout<<"there have a \' \'"<<endl;
	//else cout<<"nothing there"<<endl;
	*/
 } 
