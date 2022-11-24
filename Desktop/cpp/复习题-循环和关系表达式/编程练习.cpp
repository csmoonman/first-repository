#include<iostream>
#include<cstdio>
#include<array>
#include<string>
#include<vector>
#pragma warning(disable:4996)

using std::string;
using std::cout;
using std::endl;
using std::cin;

/* 2
long double cntf(int n);//µÝ¹é¼ÆËã½×³Ë

int main()
{
	using namespace std;
	array<long double,101> a;
	int n,i;
	cin >> n;
	if (n == 0 || n == 1) cout << 1;
	else
	{
		a[0] = 1, a[1] = 1;
		for (i = 2; i <= n; i++)
			a[i] = i * a[i - 1];
	}
	cout << a[i - 1];
	cout << endl << cntf(n);
}

long double cntf(int n)
{
	if (n == 1 || n == 0) return 1;
	else return cntf(n - 1)*n;
}
*/


/* 5.9 T3
typedef struct LNode
{
	double date;
	struct LNode* next;
}*pLNode;
typedef struct LLink
{
	pLNode Head;
	pLNode Rear;
}*Link;

pLNode create(LLink &L);
pLNode push(LLink& L, double n);
void print(LLink L);

int main()
{
	using namespace std;
	double sum=0;
	int x;
	LLink L;
	L.Head=create(L);
	cin >> x;
	cin.get();
	while (x!=0)
	{
		L.Rear=push(L, x);
		sum += x;
		print(L);
		cin >> x;
		cin.get();
	}
}

pLNode create(LLink& L)
{
	L.Head = new struct LNode;
	if (L.Head == NULL) return NULL;
	L.Head->next = NULL;
	L.Rear = L.Head;
	return L.Head;
}
pLNode push(LLink& L, double n)
{
	pLNode ptr = new LNode;
	if (ptr == NULL) return NULL;
	
	L.Rear->next = ptr;
	ptr->next = NULL;
	ptr->date = n;
	L.Rear = ptr;
	return L.Rear;
}

void print(LLink L)
{
	int sum = 0;
	if (L.Head == NULL) return;
	else if (L.Head->next == L.Rear) std::cout << L.Rear->date;
	else
	{
		pLNode ptr = L.Head->next;
		while (ptr != NULL)
		{
			std::cout << ptr->date << " ";
			sum += ptr->date;
			ptr = ptr->next;
		}
		std::cout <<"sum = " << sum << " ";
		std::cout << std::endl;
	}
}
*/

/*5.9 T4
int main()
{
	double incleo, inda=10;
	double cleo=100,da = 100;
	int year = 0;
	do
	{
		year++;
		da += 10;
		incleo = 0.05*cleo;
		cleo += incleo;

	} while (cleo<=da);
	std::cout << "after" << year << ",cleo :" << cleo << "than da:" << da;
}
*/

/*5.9 T6
int main()
{
	char year[12][5] ;
	
	int sales[13]={0};
	strcpy(year[0], "jan");
	strcpy(year[1], "feb");
	strcpy(year[2], "mar");
	strcpy(year[3], "ari");
	strcpy(year[4], "may");
	strcpy(year[5], "jun");
	strcpy(year[6], "jul");
	strcpy(year[7], "aut");
	strcpy(year[8], "sep");
	strcpy(year[9], "oct");
	strcpy(year[10], "nov");
	strcpy(year[11], "dec");
	for (int i = 0; i < 12; i++)
	{
		std::cout << year[i]<<": ";
		std::cin>>sales[i+1];
		std::cin.get();
		sales[0] += sales[i + 1];
		std::cout << std::endl;
	}
	std::cout << sales[0];
}
*/

/*5.9 T5
int main()
{
	char** year = new char* [12];
	for (int i = 0; i < 12; i++)
	{
		year[i] = new char[5];
	}
	
	int sales[13] = { 0 };
	strcpy(*year, "jan");
	strcpy(*(year+1), "feb");
	strcpy(*(year + 2), "mar");
	strcpy(*(year + 3), "ari");
	strcpy(*(year + 4), "may");
	strcpy(*(year + 5), "jun");
	strcpy(*(year + 6), "jul");
	strcpy(*(year + 7), "aut");
	strcpy(*(year + 8), "sep");
	strcpy(*(year + 9), "oct");
	strcpy(*(year + 10), "nov");
	strcpy(*(year + 11), "dec");
	for (int i = 0; i < 12; i++)
	{
		std::cout << year[i] << ": ";
		std::cin >> sales[i + 1];
		std::cin.get();
		sales[0] += sales[i + 1];
		std::cout << std::endl;
	}
	std::cout << sales[0];
	delete[]year;
}
*/

/*5.9 7
struct car
{
	std::string name;
	int year;
};

int main()
{
	int car_num;
	cout << "enter the number of cars:";
	cin >> car_num;
	cin.get();
	car *user = new struct car[car_num];
	int cnt = 1;
	
	for (cnt; cnt <= car_num; cnt++)
	{
		cout << "Car #" << cnt<<": " << endl << "Please enter the make:";
		getline(cin, user[cnt-1].name);
		cout << endl << "Please enter the year made:";
		cin >> user[cnt - 1].year;
		cin.get();
	}
	for (int i = 0; i < car_num; i++)
	{
		cout << user[i].year << " " << user[i].name << endl;
	}
	delete[]user;
}
*/

/*5.9 T8
int main()
{
	int cnt = -1;
	char word[20];
	int flag = 1;
	do
	{
		cnt++;
		cin >> word;
		flag = strcmp(word, "done");
	} while (flag != 0);
	cout << endl << cnt;
}
*/

/*5.9 T9
int main()
{
	int cnt = 0;
	string word;
	cin >> word;
	while (word != "done")
	{
		cnt++;
		cin >> word;
	}
	cout << "you entered a total of " << cnt << " words";
}
*/

/*5.9 T10
int main()
{
	int row;
	cin >> row;
	cin.get();
	for (int i = 1; i <= row; i++)
	{
		for (int j = row - i; j > 0; j--)
		{
			cout << ".";
		}
		for (int k = 1; k <= i; k++)
			cout << "*";
		cout << endl;
	}
}
*/

/*2-D vector
using std::vector;
int main()
{
	vector < vector<int> > a;
	vector<int> b;

	b.push_back(0);
	b.push_back(1);
	b.push_back(2);
	a.push_back(b);

	vector<int> c(3,1);
	a.push_back(c);
	int x = b.size();
	int y = a.size();
	cout << y << " " << x << endl;
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			cout << a[i][j] << " ";
}
*/