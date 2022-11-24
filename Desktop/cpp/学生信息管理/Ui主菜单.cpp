#include"struct.h"
#include"信息链表基础操作.h"
#include"登录逻辑.h"
#include<iostream>
#include<string>
#include"txt操作.h"

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::get;
//菜单栏
void menu(Linklist& L)
{
	string key;
	cout << "添加元素          /1：" << endl;
	cout << "删除指定元素      /2：" << endl;
	cout << "打印链表          /3：" << endl;
	cout << "插入节点          /4：" << endl;
	cout << "将链表写入txt     /5：" << endl;
	cout << "读取txt           /6：" << endl;
	cout << "退出              /0：" << endl;
	cout << "输入您的选择：  ";
	getline(cin, key);

	if (key == "1")
		L = pop(L);
	else if (key == "2")
		L = deleteNode(L);
	else if (key == "3")
		print(L);
	else if (key == "4")
		L = insertNode(L);
	else if (key == "5")
		writeIntxt(L);
	else if (key == "6")
		readOuttxt(L);
	else if (key == "0")
		exit(EXIT_FAILURE);
	else
		cout << "输入有误！";

	cout << "输入任意键以继续！" << endl;
	cin.get();
	system("cls");
}
