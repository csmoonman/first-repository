#include"struct.h"
#include"��Ϣ�����������.h"
#include"��¼�߼�.h"
#include<iostream>
#include<string>
#include"txt����.h"

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::get;
//�˵���
void menu(Linklist& L)
{
	string key;
	cout << "���Ԫ��          /1��" << endl;
	cout << "ɾ��ָ��Ԫ��      /2��" << endl;
	cout << "��ӡ����          /3��" << endl;
	cout << "����ڵ�          /4��" << endl;
	cout << "������д��txt     /5��" << endl;
	cout << "��ȡtxt           /6��" << endl;
	cout << "�˳�              /0��" << endl;
	cout << "��������ѡ��  ";
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
		cout << "��������";

	cout << "����������Լ�����" << endl;
	cin.get();
	system("cls");
}
