#include<iostream>
#include<string>

using namespace std;

int main()
{
	/*
	int Bcnt = 0,Scnt = 0;
	int sum;
	for (char ch; (ch = getchar()) != '\n';)
	{
		if (ch == 'B')Bcnt++;
		else if (ch == 'S')Scnt++;
		else sum = ch - '0';
	}
	cout << sum + Bcnt * 100 + Scnt * 10;
	*/

	int sum,Bcnt,Scnt;
	cin >> sum;
	Bcnt = sum / 100;
	Scnt = sum / 10 % 10;
	sum = sum % 10;

	for (int i = 0; i < Bcnt; i++)
		cout << "B";
	for (int i = 0; i < Scnt; i++)
		cout << "S";
	for (int i = 1; i <= sum; i++)
		cout << i;
	return 0;
}