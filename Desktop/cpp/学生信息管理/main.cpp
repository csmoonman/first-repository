#include"struct.h"
#include"��Ϣ�����������.h"
#include"��¼�߼�.h"
#include<iostream>
#include<string>
#include"txt����.h"
#include"UI���˵�.h"

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
		cout << "��¼ʧ�ܣ�" << endl;
		return 0;
	}
	cout << "��¼�ɹ���";
	cout << "������Լ�����" << endl;
	cin.get();
	system("cls");

	while (flag)
		menu(L);

	return 0;
}