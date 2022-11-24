#include"struct.h"
#include"信息链表基础操作.h"
#include"登录逻辑.h"
#include<iostream>
#include<string>
#include"txt操作.h"
#include"UI主菜单.h"

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::get;

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