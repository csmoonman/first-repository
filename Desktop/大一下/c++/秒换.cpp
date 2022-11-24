#include<iostream>

int main()
{
	using namespace std;
	long long seconds,cseconds;
	cout<<"Enter the number of secondes"<<endl;
	cin>>seconds;
	cseconds=seconds;
	cout<<"seconds = "<<cseconds/86400<<" days,";
	cseconds%=86400;
	cout<<cseconds/3600<<" hours,";
	cseconds%=3600;
	cout<<cseconds/60<<" minutes,";
	cseconds%=60;
	cout<<cseconds<<" seconds.";
}
