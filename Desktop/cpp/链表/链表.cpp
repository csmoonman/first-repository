#include<iostream> 
#include<string>
#include<cstdlib>
#include<fstream>
#pragma warning (disable:4996)
using namespace std;

//�����ڵ�
typedef struct LNode
{
	string name;
	struct LNode* next;
}*pNode;

//��������
typedef struct Linklist
{
	struct LNode* Head;
	struct LNode* Rear;
	string Linkname;
}*pLinklist;

//������
typedef struct Link
{
	//string Linkname;
	pLinklist Links;
}Links;

//��Ϣ�������
Linklist create(Linklist& LS);
Linklist pop(Linklist& L);
Linklist deleteNode(Linklist& L);
Linklist insertNode(Linklist& L);
pNode findNode(Linklist L,string s);
int empty(Linklist L);
void print(Linklist L);

//ui
void menu(Linklist& L);

//txt����
void writeIntxt(Linklist L);
void readOuttxt(Linklist& L);

//��¼�߼�
int login();
int LoginbyAccount(int flag);
int LoginbyPass(int flag);
void Enroll();

int main()
{
	
	struct Linklist L;
	L = create(L);

	int flag=login();
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

/*   main function    */
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

//��¼
int login()
{
	string key;
	int flag = 0;

	while (1)
	{
		system("cls");
		cout << "#1-----------��  ��  ��  ��  ��  ¼" << endl;
		cout << "#2-----------ͨ    ��  ֤   ��   ¼" << endl;
		cout << "#3-----------ע                  ��" << endl;
		cout << "#0-----------��                  ��" << endl;
		cout << endl << endl << "�������룺";
		getline(cin,key);

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
			;
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

//��ӡ����
void print(Linklist L)
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

//������д��txt
void writeIntxt(Linklist L)
{
	if (!empty(L))
	{
		char txtname[30];
		cout << "�����ı������Լ���չ����";
		cin.getline(txtname, 30);

		ofstream outFile;
		outFile.open(txtname);

		pNode ptr = L.Head->next;
		while (ptr)
		{
			outFile << ptr->name;
			if (ptr != NULL && ptr->next != NULL)
				outFile << "->";
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
			inFile >> ptr->name;
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
		string s;
		cout << "�����Աname:";
		getline(cin, s);
		ptr->name = s;
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
	string insertname;
	int index;
	pNode newNode = new LNode;
	pNode pindex = NULL;
	pNode phelpindex = L.Head;
	newNode->next = NULL;

	cout << "�����������:";
	getline(cin,name);
	newNode->name = name;

	if (!empty(L))
	{
		cout << "�������ĸ��ڵ㸽����" << endl;
		getline(cin, insertname);
		pindex = findNode(L, insertname);
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
pNode findNode(Linklist L, string s)
{
	if (empty(L)) return NULL;
	
	pNode ptr = L.Head->next;

	while (ptr != NULL && ptr->name != s)
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
	int Logincnt = 0;
	string Rpass="gaoyukun";//��׼ͨ��֤
	string pass;//�û�����
	while (1)
	{
		cout << "ͨ��֤��";
		getline(cin, pass);
		if (pass == Rpass)
		{
			system("cls");
			cout << "�𾴵�" << Rpass << "��ӭ����" << endl;
			_sleep(100);
			flag = 1;
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
	}
	return flag;
}

//zhuce
void Enroll();