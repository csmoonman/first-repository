#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	cout<<setw(5)<<setfill('G')<<11<<endl;
	for(int n=1;n<=10;n++)
	{
		cout<<setfill(' ')<<setw(n)<<" "//一共n个字符，除了“ ”外全部用“ ”填充； 
			<<setfill('M')<<setw(21-2*n)<<'M'<<endl;//与上同理； 
	}
}
