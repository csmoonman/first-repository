#include<iostream>
using namespace std;

int main()
{
	cout<<oct<<18<<" "<<showbase<<18<<endl;
	cout<<hex<<18<<" "<<showbase<<18<<endl;
	cout<<123.0<<" "<<showpoint<<123.0<<endl;
		
	cout<<"showpos is "<<showpos<<12<<endl;

	cout<<dec<<endl;
	
	cout.width(10);
	cout.fill('o');
	cout<<noshowpos<<222<<endl;
}
