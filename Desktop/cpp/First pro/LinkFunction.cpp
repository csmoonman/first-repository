#include<iostream> 
#include<string>
#include<cstdlib>
#include<fstream>
#include"LinkStruct.h"
#pragma warning (disable:4996)
using namespace std;

static int flag = 0;
/*   main function    */
//菜单栏
void menu(Linklist& L)
{
	if (flag == 1)
	{
		string key;
		cout << "添加学生信息      /1：" << endl;
		cout << "打印学生姓名      /2：" << endl;
		cout << "插入学生信息      /3：" << endl;
		cout << "将链表写入txt     /4：" << endl;
		cout << "读取txt           /5：" << endl;
		cout << "退出              /0：" << endl;
		cout << "输入您的选择：  ";
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
			cout << "输入有误！";

		cout << "输入任意键以继续！" << endl;
		cin.get();
		system("cls");
	}
	else if (flag == 2)
	{
		string key;
		cout << "添加学生信息        /1：" << endl;
		cout << "删除学生信息        /2：" << endl;
		cout << "打印学生姓名        /3：" << endl;
		cout << "打印学生全部信息    /4：" << endl;
		cout << "插入节点            /5：" << endl;
		cout << "将链表写入txt       /6：" << endl;
		cout << "读取txt             /7：" << endl;
		cout << "退出                /0：" << endl;
		cout << "输入您的选择：  ";
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
			cout << "输入有误！";

		cout << "输入任意键以继续！" << endl;
		cin.get();
		system("cls");
	}
}

//登录
int login()
{
	string key;
	string EnrollAccount;

	while (1)
	{
		system("cls");
		cout << "#1-----------已  有  账  号  登  录 (校内学生）" << endl << endl;
		cout << "#2-----------通    行  证   登   录（管理人员）" << endl << endl;
		cout << "#3-----------管    理    人    员    注    册" << endl << endl;
		cout << "#0-----------退                            出" << endl << endl;
		cout << endl << endl << "您的输入：";
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
			cout << "尊敬的" << EnrollAccount << "欢迎您！" << endl;
			flag = 2;
			break;
		}
		else if (key == "0")
			exit(EXIT_FAILURE);
		else
		{
			cout << "输入有误！" << endl;
			_sleep(400);
		}
	}


	/*LoginbyAccount
	fstream inFile;
	inFile.open("account.txt");
	if (!inFile.is_open())
	{
		cout << "打开失败！" << endl;
		return 0;
	}

	inFile.close();
	int logincnt = 0;
	//用来读取已存储的账号密码
	char keyAccout[20];
	char keyWord[20];
	//存储输入的账号密码
	char passAccount[20];
	char passWord[20];

	while (logincnt < 3)
	{
		cout << "请输入账号：";
		cin.getline(passAccount, 20);
		cout << endl << "请输入密码：";
		cin.getline(passWord, 20);

		inFile.open("account.txt");

		if (++logincnt > 3)
		{
			cout << "您已输入错误三次，即将退出程序！" << endl;
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
		cout << "错误" << logincnt << "次" << endl;
	}
	*/
	return flag;
}

//打印学生姓名
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
	else cout << "空" << endl;
}

//打印全部信息
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
	else cout << "空" << endl;
}

//将链表写入txt
void writeIntxt(Linklist L)
{
	if (!empty(L))
	{
		char txtname[30];
		cout << "输入文本名称以及扩展名：";
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
		cout << "完成！" << endl;
	}
	else
		cout << "链表为空，无法写入！" << endl;
}

//读取txt
void readOuttxt(Linklist& L)
{
	pNode ptr;
	fstream inFile;
	char txtname[20];
	cout << "输入您要打开的txt文本名，以及扩展名：";
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
		cout << "文件打开失败,任意键以继续！" << endl;
		cin.get();
		return;
	}

	cout << "读取完成，任意键以继续！" << endl;
	cin.get();
}

/*   basic function   */
//创建链表
Linklist create(Linklist& L)
{
	L.Head = new struct LNode;
	if (L.Head)
	{
		L.Head->next = NULL;
		L.Rear = L.Head;
	}
	else cout << "创建失败!" << endl;

	return L;
}

//增加节点
Linklist pop(Linklist& L)
{
	struct LNode* ptr = new struct LNode;

	if (!ptr) cout << "内存申请失败！" << endl;
	else
	{
		string sname;
		string sgender;
		string sID;
		string smajor;
		cout << "输入学生学号:";
		getline(cin, sID);
		cout << "输入学生姓名:";
		getline(cin, sname);
		cout  << "输入学生性别:";
		getline(cin,sgender);
		cout << "输入学生专业:";
		getline(cin, smajor);

		ptr->name = sname;
		ptr->major = smajor;
		ptr->gender=sgender;
		ptr->STU_ID = sID;
		ptr->next = NULL;
		L.Rear->next = ptr;
		L.Rear = ptr;
		L.Rear->next = NULL;
		cout << "添加成功！" << endl;
	}

	return L;
}

//删除节点
Linklist deleteNode(Linklist& L)
{
	//链表为空
	if (L.Head == L.Rear)
	{
		cout << "链表空！" << endl;
		return L;
	}

	print(L);
	string s;
	cout << "输入您要删除的成员name：";
	getline(cin, s);

	if (L.Head->next == L.Rear) //只有一个节点
	{

		if (s == L.Rear->name)
		{
			pNode ptr = L.Rear;
			L.Rear = L.Head;
			delete ptr;
			cout << "删除成功" << endl;
		}
		else cout << "未能找到！" << endl;
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
			cout << "删除成功！" << endl;
		}
		else cout << "未能找到！" << endl;
	}

	return L;
}

//插入节点
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

	cout << "输入插入学生学号:";
	getline(cin, ID);
	cout << "输入插入学生姓名:";
	getline(cin, name);
	cout << "输入插入学生性别:";
	getline(cin, gender);
	cout << "输入插入学生专业:";
	getline(cin, major);
	newNode->name = name;
	newNode->STU_ID = ID;
	newNode->gender = gender;
	newNode->major = major;

	if (!empty(L))
	{
		int key;
		cout << "按姓名插入/按学号插入   1/2 : ";
		(cin >> key).get();
		cout << "插入在哪个信息附近？" << endl;
		getline(cin, insert);
		pindex = findNode(L, insert,key);
		if (pindex)
		{
			while (1)
			{
				cout << "插入在该结点前还是之后？ 1/0" << endl;
				cout << "退出选择 -1" << endl << "您的选择：";
				(cin >> index).get();
				cout << endl;

				if (index == 1)
				{
					while (phelpindex->next != pindex)
						phelpindex = phelpindex->next;

					phelpindex->next = newNode;
					newNode->next = pindex;
					cout << "插入成功！" << endl;
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
					cout << "插入成功！" << endl;
					break;
				}
				else if (index == -1) break;
				else cout << "请重新输入！";
			}
		}
		else
			cout << "链表中未有该元素!" << endl;
	}
	else
	{
		L.Head->next = newNode;
		L.Rear = newNode;
		cout << "插入成功！" << endl;
	}

	return L;
}

//判断是否为空
int empty(Linklist L)
{
	if (L.Head == L.Rear) return 1;

	return 0;
}

//找节点
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

//已有帐号登录
int LoginbyAccount(int flag)
{
	fstream inFile;
	inFile.open("account.txt");
	if (!inFile.is_open())
	{
		cout << "打开失败！" << endl;
		return 0;
	}

	inFile.close();
	int logincnt = 0;
	//用来读取已存储的账号密码
	char keyAccout[20];
	char keyWord[20];
	//存储输入的账号密码
	char passAccount[20];
	char passWord[20];

	while (logincnt < 3)
	{
		cout << "请输入账号：";
		cin.getline(passAccount, 20);
		cout << endl << "请输入密码：";
		cin.getline(passWord, 20);

		inFile.open("account.txt");

		if (++logincnt > 3)
		{
			cout << "您已输入错误三次，即将退出程序！" << endl;
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
		cout << "错误" << logincnt << "次" << endl;
	}
	return flag;
}

//通行证登录
int LoginbyPass(int flag)
{
	fstream inFile;
	inFile.open("passAccount.txt");
	if (!inFile.is_open())
	{
		cout << "通行证目录文件打开失败！";
		return 0;
	}
	inFile.close();

	int Logincnt = 0;
	string Rpass = "gaoyukun";//标准通行证
	string pass;//用户输入
	while (Logincnt < 3)
	{
		inFile.open("passAccount.txt");
		cout << "通行证：";
		getline(cin, pass);

		if (Logincnt > 3)
		{
			cout << "您已错误三次，正在退出！" << endl;
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
			cout << "尊敬的" << Rpass << "欢迎您！" << endl;
			_sleep(100);
			flag = 2;
			break;
		}
		else
		{
			Logincnt++;
			cout << "错误" << Logincnt << "次!" << endl;
			if (Logincnt > 2)
			{
				cout << "您的输入已错误三次，即将退出！" << endl;
				_sleep(100);
				exit(EXIT_FAILURE);
			}
		}
		*/
		Logincnt++;
		cout << "您已错误" << Logincnt << "次！" << endl;
	}
	return flag;
}

//管理人员注册
string& Enroll(string& s)
{
	ofstream outFile;
	int cnt = 0;
	const string answer1 = "西南石油大学";
	string answerUser1;
	const string answer2 = "SWPU";
	string answerUser2;
	cout << "我校全称 :";
	getline(cin, answerUser1);
	while ((answerUser1 != answer1))
	{
		cnt++;
		if (cnt < 3)
		{
			cout << "错误" << cnt << "次" << endl;
			cout << "我校全称 :";
			getline(cin, answerUser1);
		}
		else
		{
			cout << "错误三次！正在退出！" << endl;
			exit(EXIT_FAILURE);
		}
	}

	cout << "我校英文缩写（大写） :";
	getline(cin, answerUser2);
	while ((answerUser2 != answer2))
	{
		if (++cnt < 3)
		{
			cout << "错误" << cnt << "次" << endl;
			cout << "我校全称 :";
			getline(cin, answerUser2);
		}
		else
		{
			cout << "错误三次！正在退出！" << endl;
			exit(EXIT_FAILURE);
		}
	}
	system("cls");
	cout << "已验证为校内人员！ 任意键继续；" << endl;
	cin.get();

	cout << "输入注册的用户名：";
	getline(cin, s);

	outFile.open("passAccount.txt", ios::app | ios::out);
	outFile << s << endl;
	return s;
}