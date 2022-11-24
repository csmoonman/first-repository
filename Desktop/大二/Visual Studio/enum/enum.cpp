#include<iostream>

using namespace std;

int main()
{
	enum color {red=1,blue,black,white} c;
	c = blue;
	cout << c;
	
	return 0;
}
/*
	将c定义为color
	中括号中，若未赋初值则从0开始累加1
*/