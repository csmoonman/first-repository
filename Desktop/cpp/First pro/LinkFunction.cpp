#include<iostream> 
#include<string>
#include<cstdlib>
#include<fstream>
#include"LinkStruct.h"
#pragma warning (disable:4996)
using namespace std;

static int flag = 0;
/*   main function    */
//�˵���
void menu(Linklist& L)
{
	if (flag == 1)
	{
		string key;
		cout << "���ѧ����Ϣ      /1��" << endl;
		cout << "��ӡѧ������      /2��" << endl;
		cout << "����ѧ����Ϣ      /3��" << endl;
		cout << "������д��txt     /4��" << endl;
		cout << "��ȡtxt           /5��" << endl;
		cout << "�˳�              /0��" << endl;
		cout << "��������ѡ��  ";
		getline(cin, key);

		if (key == "1")
			L = pop(L);
		else if (key == "2")
			printname(L);
		else if (key == "3")
			L = insertNode(L);
		else if (key == "4")
			writeIntxt(L);
		else if (key == "5")
			readOuttxt(L);
		else if (key == "0")
			exit(EXIT_FAILURE);
		else
			cout << "��������";

		cout << "����������Լ�����" << endl;
		cin.get();
		system("cls");
	}
	else if (flag == 2)
	{
		string key;
		cout << "���ѧ����Ϣ        /1��" << endl;
		cout << "ɾ��ѧ����Ϣ        /2��" << endl;
		cout << "��ӡѧ������        /3��" << endl;
		cout << "��ӡѧ��ȫ����Ϣ    /4��" << endl;
		cout << "����ڵ�            /5��" << endl;
		cout << "������д��txt       /6��" << endl;
		cout << "��ȡtxt             /7��" << endl;
		cout << "�˳�                /0��" << endl;
		cout << "��������ѡ��  ";
		getline(cin, key);

		if (key == "1")
			L = pop(L);
		else if (key == "2")
			L = deleteNode(L);
		else if (key == "3")
			printname(L);
		else if (key == "4")
			print(L);
		else if (key == "5")
			L = insertNode(L);
		else if (key == "6")
			writeIntxt(L);
		else if (key == "7")
			readOuttxt(L);
		else if (key == "0")
			exit(EXIT_FAILURE);
		else
			cout << "��������";

		cout << "����������Լ�����" << endl;
		cin.get();
		system("cls");
	}
}

//��¼
int login()
{
	string key;
	string EnrollAccount;

	while (1)
	{
		system("cls");
		cout << "#1-----------��  ��  ��  ��  ��  ¼ (У��ѧ����" << endl << endl;
		cout << "#2-----------ͨ    ��  ֤   ��   ¼��������Ա��" << endl << endl;
		cout << "#3-----------��    ��    ��    Ա    ע    ��" << endl << endl;
		cout << "#0-----------��                            ��" << endl << endl;
		cout << endl << endl << "�������룺";
		getline(cin, key);

		if (key == "1")
		{
			flag = LoginbyAccount(flag);
			break;
		}
		else if (key == "2")
		{
			flag = LoginbyPass(flag);
			break;
		}
		else if (key == "3")
		{
			EnrollAccount = Enroll(EnrollAccount);
			cout << "�𾴵�" << EnrollAccount << "��ӭ����" << endl;
			flag = 2;
			break;
		}
		else if (key == "0")
			exit(EXIT_FAILURE);
		else
		{
			cout << "��������" << endl;
			_sleep(400);
		}
	}


	/*LoginbyAccount
	fstream inFile;
	inFile.open("account.txt");
	if (!inFile.is_open())
	{
		cout << "��ʧ�ܣ�" << endl;
		return 0;
	}

	inFile.close();
	int logincnt = 0;
	//������ȡ�Ѵ洢���˺�����
	char keyAccout[20];
	char keyWord[20];
	//�洢������˺�����
	char passAccount[20];
	char passWord[20];

	while (logincnt < 3)
	{
		cout << "�������˺ţ�";
		cin.getline(passAccount, 20);
		cout << endl << "���������룺";
		cin.getline(passWord, 20);

		inFile.open("account.txt");

		if (++logincnt > 3)
		{
			cout << "��������������Σ������˳�����" << endl;
			break;
		}

		while (!inFile.eof())
		{
			inFile >> keyAccout;
			inFile >> keyWord;

			if (!strcmp(passAccount, keyAccout))
				if (!strcmp(passWord, keyWord))
				{
					flag = 1;
					return flag;
				}

			inFile.get();
		}
		inFile.close();
		system("cls");
		cout << "����" << logincnt << "��" << endl;
	}
	*/
	return flag;
}

//��ӡѧ������
void printname(Linklist L)
{
	if (L.Head != L.Rear)
	{
		pNode ptr = L.Head->next;
		while (ptr != NULL)
		{
			cout << ptr->name << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
	else cout << "��" << endl;
}

//��ӡȫ����Ϣ
void print(Linklist L)
{
	if (L.Head != L.Rear)
	{
		pNode ptr = L.Head->next;
		while (ptr != NULL)
		{
			cout << ptr->STU_ID << ' ' << ptr->name << " " << ptr->gender << " " << ptr->major << endl;
			ptr = ptr->next;
		}
		cout << endl;
	}
	else cout << "��" << endl;
}

//������д��txt
void writeIntxt(Linklist L)
{
	if (!empty(L))
	{
		char txtname[30];
		cout << "�����ı������Լ���չ����";
		cin.getline(txtname, 30);

		ofstream outFile;
		outFile.open(txtname, ios::app | ios::out);

		pNode ptr = L.Head->next;
		while (ptr)
		{
			outFile << endl;
			outFile << ptr->STU_ID << " " << ptr->name << " " << ptr->gender << " " << ptr->major;
			if (ptr != NULL && ptr->next != NULL)
				outFile << endl;
			ptr = ptr->next;
		}
		cout << "��ɣ�" << endl;
	}
	else
		cout << "����Ϊ�գ��޷�д�룡" << endl;
}

//��ȡtxt
void readOuttxt(Linklist& L)
{
	pNode ptr;
	fstream inFile;
	char txtname[20];
	cout << "������Ҫ�򿪵�txt�ı������Լ���չ����";
	cin.get(txtname, 20);
	inFile.open(txtname);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			ptr = new LNode;
			ptr->next = NULL;
			inFile >> ptr->STU_ID >> ptr->name >> ptr->gender >> ptr->major;
			L.Rear->next = ptr;
			L.Rear = ptr;
		}
	}
	else
	{
		cout << "�ļ���ʧ��,������Լ�����" << endl;
		cin.get();
		return;
	}

	cout << "��ȡ��ɣ�������Լ�����" << endl;
	cin.get();
}

/*   basic function   */
//��������
Linklist create(Linklist& L)
{
	L.Head = new struct LNode;
	if (L.Head)
	{
		L.Head->next = NULL;
		L.Rear = L.Head;
	}
	else cout << "����ʧ��!" << endl;

	return L;
}

//���ӽڵ�
Linklist pop(Linklist& L)
{
	struct LNode* ptr = new struct LNode;

	if (!ptr) cout << "�ڴ�����ʧ�ܣ�" << endl;
	else
	{
		string sname;
		string sgender;
		string sID;
		string smajor;
		cout << "����ѧ��ѧ��:";
		getline(cin, sID);
		cout << "����ѧ������:";
		getline(cin, sname);
		cout  << "����ѧ���Ա�:";
		getline(cin,sgender);
		cout << "����ѧ��רҵ:";
		getline(cin, smajor);

		ptr->name = sname;
		ptr->major = smajor;
		ptr->gender=sgender;
		ptr->STU_ID = sID;
		ptr->next = NULL;
		L.Rear->next = ptr;
		L.Rear = ptr;
		L.Rear->next = NULL;
		cout << "��ӳɹ���" << endl;
	}

	return L;
}

//ɾ���ڵ�
Linklist deleteNode(Linklist& L)
{
	//����Ϊ��
	if (L.Head == L.Rear)
	{
		cout << "����գ�" << endl;
		return L;
	}

	print(L);
	string s;
	cout << "������Ҫɾ���ĳ�Աname��";
	getline(cin, s);

	if (L.Head->next == L.Rear) //ֻ��һ���ڵ�
	{

		if (s == L.Rear->name)
		{
			pNode ptr = L.Rear;
			L.Rear = L.Head;
			delete ptr;
			cout << "ɾ���ɹ�" << endl;
		}
		else cout << "δ���ҵ���" << endl;
	}
	else
	{
		pNode ptrfront = L.Head;
		pNode ptrback = ptrfront->next;
		while (ptrback->name != s)
		{
			ptrback = ptrback->next;
			ptrfront = ptrfront->next;
		}

		if (ptrback != NULL)
		{
			if (ptrback->next == NULL)
			{
				L.Rear = ptrfront;
				ptrfront->next = NULL;
				delete ptrback;
			}
			else
			{
				ptrfront->next = ptrback->next;
				delete ptrback;
			}
			cout << "ɾ���ɹ���" << endl;
		}
		else cout << "δ���ҵ���" << endl;
	}

	return L;
}

//����ڵ�
Linklist insertNode(Linklist& L)
{
	print(L);
	string name;
	string ID;
	string gender;
	string major;
	string insert;
	int index;
	pNode newNode = new LNode;
	pNode pindex = NULL;
	pNode phelpindex = L.Head;
	newNode->next = NULL;

	cout << "�������ѧ��ѧ��:";
	getline(cin, ID);
	cout << "�������ѧ������:";
	getline(cin, name);
	cout << "�������ѧ���Ա�:";
	getline(cin, gender);
	cout << "�������ѧ��רҵ:";
	getline(cin, major);
	newNode->name = name;
	newNode->STU_ID = ID;
	newNode->gender = gender;
	newNode->major = major;

	if (!empty(L))
	{
		int key;
		cout << "����������/��ѧ�Ų���   1/2 : ";
		(cin >> key).get();
		cout << "�������ĸ���Ϣ������" << endl;
		getline(cin, insert);
		pindex = findNode(L, insert,key);
		if (pindex)
		{
			while (1)
			{
				cout << "�����ڸý��ǰ����֮�� 1/0" << endl;
				cout << "�˳�ѡ�� -1" << endl << "����ѡ��";
				(cin >> index).get();
				cout << endl;

				if (index == 1)
				{
					while (phelpindex->next != pindex)
						phelpindex = phelpindex->next;

					phelpindex->next = newNode;
					newNode->next = pindex;
					cout << "����ɹ���" << endl;
					break;
				}
				else if (index == 0)
				{
					if (pindex->next == NULL)
						pindex->next = newNode;
					else
					{
						newNode->next = pindex->next;
						pindex->next = newNode;
					}
					cout << "����ɹ���" << endl;
					break;
				}
				else if (index == -1) break;
				else cout << "���������룡";
			}
		}
		else
			cout << "������δ�и�Ԫ��!" << endl;
	}
	else
	{
		L.Head->next = newNode;
		L.Rear = newNode;
		cout << "����ɹ���" << endl;
	}

	return L;
}

//�ж��Ƿ�Ϊ��
int empty(Linklist L)
{
	if (L.Head == L.Rear) return 1;

	return 0;
}

//�ҽڵ�
pNode findNode(Linklist L, const string s, const int key)
{
	if (empty(L)) return NULL;

	pNode ptr = L.Head->next;

	if(key==1)
		while (ptr != NULL && ptr->name != s)
			ptr = ptr->next;
	else if(key==2)
		while (ptr != NULL && ptr->STU_ID != s)
			ptr = ptr->next;

	if (!ptr)	return NULL;
	else	return ptr;
}

//�����ʺŵ�¼
int LoginbyAccount(int flag)
{
	fstream inFile;
	inFile.open("account.txt");
	if (!inFile.is_open())
	{
		cout << "��ʧ�ܣ�" << endl;
		return 0;
	}

	inFile.close();
	int logincnt = 0;
	//������ȡ�Ѵ洢���˺�����
	char keyAccout[20];
	char keyWord[20];
	//�洢������˺�����
	char passAccount[20];
	char passWord[20];

	while (logincnt < 3)
	{
		cout << "�������˺ţ�";
		cin.getline(passAccount, 20);
		cout << endl << "���������룺";
		cin.getline(passWord, 20);

		inFile.open("account.txt");

		if (++logincnt > 3)
		{
			cout << "��������������Σ������˳�����" << endl;
			break;
		}

		while (!inFile.eof())
		{
			inFile >> keyAccout;
			inFile >> keyWord;

			if (!strcmp(passAccount, keyAccout))
				if (!strcmp(passWord, keyWord))
				{
					flag = 1;
					return flag;
				}

			inFile.get();
		}
		inFile.close();
		system("cls");
		cout << "����" << logincnt << "��" << endl;
	}
	return flag;
}

//ͨ��֤��¼
int LoginbyPass(int flag)
{
	fstream inFile;
	inFile.open("passAccount.txt");
	if (!inFile.is_open())
	{
		cout << "ͨ��֤Ŀ¼�ļ���ʧ�ܣ�";
		return 0;
	}
	inFile.close();

	int Logincnt = 0;
	string Rpass = "gaoyukun";//��׼ͨ��֤
	string pass;//�û�����
	while (Logincnt < 3)
	{
		inFile.open("passAccount.txt");
		cout << "ͨ��֤��";
		getline(cin, pass);

		if (Logincnt > 3)
		{
			cout << "���Ѵ������Σ������˳���" << endl;
			exit(EXIT_FAILURE);
		}

		while (!inFile.eof())
		{
			inFile >> Rpass;
			if (pass == Rpass)
			{
				flag = 2;
				return flag;
			}
			inFile.get();
		}
		inFile.close();

		/*
		if (pass == Rpass)
		{
			system("cls");
			cout << "�𾴵�" << Rpass << "��ӭ����" << endl;
			_sleep(100);
			flag = 2;
			break;
		}
		else
		{
			Logincnt++;
			cout << "����" << Logincnt << "��!" << endl;
			if (Logincnt > 2)
			{
				cout << "���������Ѵ������Σ������˳���" << endl;
				_sleep(100);
				exit(EXIT_FAILURE);
			}
		}
		*/
		Logincnt++;
		cout << "���Ѵ���" << Logincnt << "�Σ�" << endl;
	}
	return flag;
}

//������Աע��
string& Enroll(string& s)
{
	ofstream outFile;
	int cnt = 0;
	const string answer1 = "����ʯ�ʹ�ѧ";
	string answerUser1;
	const string answer2 = "SWPU";
	string answerUser2;
	cout << "��Уȫ�� :";
	getline(cin, answerUser1);
	while ((answerUser1 != answer1))
	{
		cnt++;
		if (cnt < 3)
		{
			cout << "����" << cnt << "��" << endl;
			cout << "��Уȫ�� :";
			getline(cin, answerUser1);
		}
		else
		{
			cout << "�������Σ������˳���" << endl;
			exit(EXIT_FAILURE);
		}
	}

	cout << "��УӢ����д����д�� :";
	getline(cin, answerUser2);
	while ((answerUser2 != answer2))
	{
		if (++cnt < 3)
		{
			cout << "����" << cnt << "��" << endl;
			cout << "��Уȫ�� :";
			getline(cin, answerUser2);
		}
		else
		{
			cout << "�������Σ������˳���" << endl;
			exit(EXIT_FAILURE);
		}
	}
	system("cls");
	cout << "����֤ΪУ����Ա�� �����������" << endl;
	cin.get();

	cout << "����ע����û�����";
	getline(cin, s);

	outFile.open("passAccount.txt", ios::app | ios::out);
	outFile << s << endl;
	return s;
}