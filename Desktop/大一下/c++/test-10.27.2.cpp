#include<iostream>

using namespace std;
int main()
{
	double a=3;
	int b=3;
	cout<<a<<endl;
	ios_base::fmtflags orig=cout.setf(ios_base::fixed,ios_base::floatfield);
	streamsize prec=cout.precision(3);
	
	cout<<"precision(3)"<<a<<endl;
	
	cout.precision(2);
	cout<<a<<endl;
	
	cout.setf(orig ,ios_base::floatfield);
	cout.precision(prec);
	cout<<a<<endl;
}
