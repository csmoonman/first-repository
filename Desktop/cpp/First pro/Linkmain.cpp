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