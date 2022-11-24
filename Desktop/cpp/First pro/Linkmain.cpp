#include<iostream> 
#include<string>
#include<cstdlib>
#include<fstream>
#include"LinkStruct.h"
#pragma warning (disable:4996)
using namespace std;


int main()
{

	struct Linklist L;
	L = create(L);

	int flag = login();
	if (!flag)
	{
		cout << "登录失败！" << endl;
		return 0;
	}
	cout << "登录成功！";
	cout << "任意键以继续！" << endl;
	cin.get();
	system("cls");

	while (flag)
		menu(L);

	return 0;
}