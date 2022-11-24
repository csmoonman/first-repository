#include<iostream>
#include<iomanip>
using namespace std;

class Date{
	int year,month,day;
public:
	void set(int y,int m,int d);
	bool isLeapYear();
	void print();
};

void Date::set(int y,int m, int d)
{
	year=y;
	month=m;
	day=d;
}

bool Date::isLeapYear()
{
	return (year%4==0&&year%100!=0)||(year%400==0);
}

void Date::print()
{
	cout<<setfill('0');
	cout<<setw(4)<<year<<'-'<<setw(2)<<month<<'-'<<setw(2)<<day<<endl;
	cout<<setfill(' ');
}
int main()
{
	Date d;
	d.set(2000,9,5);
	if(d.isLeapYear())
		d.print();
}
