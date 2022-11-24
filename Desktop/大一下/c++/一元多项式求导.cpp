#include<iostream>

using namespace std;
int main()
{
	int x,y;
	int i=0;

	while(1)
	{	
		cin>>x>>y;
		cout<<x*y;
		if(y!=0)
			cout<<" "<<y-1;
		if(cin.get()=='\n')
		{
			break;
		}
		cout<<" ";
	} 

}
