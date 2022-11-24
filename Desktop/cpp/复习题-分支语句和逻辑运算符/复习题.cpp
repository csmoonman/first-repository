#include<iostream>
#include<fstream>
#include<cctype>
#include<array>
#pragma warning (disable:4996)

//6.10 T2
/*
int main()
{
	using namespace std;
	char ch;
	int ch1, ch2;
	ch1 = ch2 = 0;
	while ((ch = cin.get()) != '$')
	{
		cout << ch;
		ch1++;
		if (ch == '$')
			ch2++;
		cout << ch;
	}
	cout << "ch1 = " << ch1 << ", ch2 = " << ch2 << '\n';
}
*/

//6.10 T5
/*
int main()
{
	int x = 1;
	if (!!x == x) std::cout << "equal!";
	else std::cout << "not equal";
}
*/

//6.10 T6
/*
int main()
{
	int x;
	std::cin >> x;
	std::cin.get();
	(x < 0) ? x = (-1 * x) : x = x;

	std::cout <<  x;
}
*/

//6.10 T7
/*
int main()
{
	int line = 0;
	char ch;
	while ((ch= std::cin.get()) != 'Q')
	{
		if (ch == '\n')
			line++;
	}
	std::cout << line;
}
*/

//6.11 T1
/*
int main()
{
	using namespace std;
	char ch;
	char ch2;
	cin.get(ch);
	while (ch != '@')
	{
		if (isdigit(ch))
		{
			cin.get(ch);
			continue;
		}
		if (isalpha(ch))
			if (isupper(ch))
			{
				ch2 = tolower(ch);
				cout << ch2<<endl;
			}
			else
			{
				ch2=toupper(ch);
				cout << ch2<<endl;
			}
		cin.get(ch);
	}
}
*/

//6.11 T2
/*
int main()
{
	using namespace std;
	array<double, 10> donation;
	int i = 0;
	int cnt = 0;
	double sum=0;
	for (i; i < 10; i++)
	{
		cout << "#" << i + 1 << endl;
		(cin >> donation.at(i)).get();
		sum += donation.at(i);
	}
	sum /= 10;
	for (double x : donation)
		if (x > sum) cnt++;

	cout << "average:" << sum << endl;
	cout << cnt << endl;
}
*/

//6.11 T4
/*
#define SIZE 30;

typedef struct bop
{
	char fullname[30];
	char title[30];
	char bopname[30];
	int perference;
};

void menu();
void dispname(struct bop **vip, int size);
void disptitle(struct bop** vip, int size);
void dispbopname(struct bop** vip, int size);
void disppreferrence(struct bop** vip, int size);


int main()
{
	menu();
}

void menu()
{
	bop mem1 =
	{
		"gaoyukun",
		"doctor",
		"number1",
		1
	};
	bop mem2;
	strcpy(mem2.fullname, "wumou");
	strcpy(mem2.title, "artist");
	strcpy(mem2.bopname, "number2");

	mem2.perference = 2;
	bop mem3 =
	{
		"liyulong",
		"tuanzhang",
		"number3",
		2
	};
	bop* vip[3] =  {&mem1,&mem2,&mem3};

	int size = sizeof(vip) / sizeof(vip[1]);

	using namespace std;
	while (1)
	{
		char key;
		cout << "a.display by name" << endl;
		cout << "b.display by title" << endl;
		cout << "c.display by bopname" << endl;
		cout << "d.display by preference" << endl;
		cout << "q.exit" << endl;
		cout << "enter your choice:";
		cin.get(key);
		switch (key)
		{
		case 'a':
		case 'A':dispname(vip, size); break;
		case 'b':
		case 'B':disptitle(vip,size); break;
		case 'c':
		case 'C':dispbopname(vip,size); break;
		case 'd':
		case 'D':disppreferrence(vip,size); break;
		case 'q':
		case 'Q':exit(1);
		default:cout << "please enter a,b,c,d or q" << endl;
		}
		cout << "enter the enter key continue!";
		cin.get();
		cin.get();
		system("cls");
	}
}
using namespace std;
void dispname(struct bop** vip,int size)
{
	int i = 0;
	for (i; i < size; i++)
		cout << (vip[i])->fullname << endl;
}
void disptitle(struct bop** vip, int size)
{
	int i = 0;
	for (i; i < size; i++)
		cout << vip[i]->title << endl;
}
void dispbopname(struct bop** vip, int size)
{
	int i = 0;
	for (i; i < size; i++)
		cout << vip[i]->bopname << endl;
}
void disppreferrence(struct bop** vip, int size)
{
	int i = 0;
	int key;
	cout << "enter the number you preference:";
	(cin >> key).get();

	if (key == 1)
		for (i; i < size; i++)
			cout << vip[i]->title << endl;
	else if (key == 2)
		for (i; i < size; i++)
			cout << vip[i]->fullname << endl;
	else 
		for (i; i < size; i++)
				cout << vip[i]->bopname << endl;
}
*/

//6.11 T5
/*
int main()
{
	using namespace std;

	double earning;
	double tax;
	(cin >> earning).get();
	while (earning > 0)
	{
		if (earning <= 5000) tax = 0;
		else if (earning <= 15000) tax = (earning - 5000) * 0.1;
		else if (earning <= 35000) tax = (earning - 15000) * 0.15 + 1000;
		else tax = 1000 + 3000 + (earning - 35000) * 0.2;
		cout << tax << endl;
		(cin >> earning).get();
	}
}
*/

//6.11 T7
/*
int main()
{
	using namespace std;
	char word;
	int cntvowels=0;
	int cntcon = 0;
	int others = 0;
	while ((word = cin.get()) != 'q')
	{
		if (isalpha(word))
		{
			if (word == 'a' || word == 'e' || word == 'o' || word == 'i' || word == 'u')
				cntvowels++;
			else
				cntcon++;
		}
		else 
		{
			others++;
		}
		char ch = cin.get();
		while (ch != ' '&&ch!='\n')
			ch = cin.get();
	}
	cout << "vowels:" << cntvowels << endl << "con:" << cntcon << endl << "others:" << others << endl;
}
*/

//6.11 T8
/*
int main()
{
	using namespace std;
	ifstream inFile;
	char name[15];
	char ch;
	int cnt = 0;
	cout << "enter the name of text you want to open:";
	cin.getline(name, 15);
	cout << endl;
	inFile.open(name);

	while (inFile.get(ch))
		cnt++;
	cout << cnt << endl;

	if (!inFile.eof()) cout << "到达结尾" << endl;
	else if (inFile.fail()) cout << "类型不匹配" << endl;

	if (!inFile.is_open()) exit(EXIT_FAILURE);
}
*/

//6.11 T9
/*
int main()
{
	using namespace std;
	ifstream inFile;
	char name[16];
	cout << "enter  name of the file you want to open :";
	cin.getline(name,16);
	inFile.open(name);

	char text[1000];
	//cin.getline(text, 1000);
	inFile.read(text,1000);
	cout << text;
}
*/