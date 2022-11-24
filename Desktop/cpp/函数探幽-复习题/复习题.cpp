#include<iostream>
#include<string>
#include<cctype>
#include<cstring>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;
using std::string;

//decltype
/*
template<typename T1,typename T2>
auto mult(T1 x, T2 y)->decltype(x* y); //c++11用法

int main()
{
	cout << mult(1.2, 3);
}
template<typename T1, typename T2>
auto mult(T1 x, T2 y)->decltype(x* y)
{
	return x * y;
}
*/

//8.7 T2 函数默认参数值
/* 规定默认值只在原型中即可，默认值只能从右向左规定
void song(const char* name="123", int times = 1);
int main()
{
	song();
	song("hhh");
	song("www", 3);
}
void song(const char* name, int times)
{
	cout << name << " " << times << endl;
}
*/

//8.7 T3
/*
void iquote(int x);
void iquote(double x);
void iquote(string s);

int main()
{
	iquote(2);
	iquote(2.1);
	iquote("string");
}
void iquote(int x)
{
	cout << "\"" << x << "\"" << endl;
}
void iquote(double x)
{
	cout << "\"" << x << "\"" << endl;
}
void iquote(string s)
{
	cout << "\"" << s << "\"" << endl;
}
*/

//8.7 T6
/*
void repeat(int x = 5, const char* c = "hello");
void repeat(const char* c);
int main()
{
	repeat(10, "nihao");
	repeat();
	repeat("xiexieni");
}

void repeat(int x, const char* c)
{
	for (int i = 0; i < x; i++)
		cout << c << endl;
}

void repeat(const char* c)
{
	for (int i = 0; i < 5; i++)
		cout << c << endl;
}
*/

//8.7 T7 
//函数模板实例化,注意：具体化和显式实例化不要在一起出现！ 
//显式具体化一般在使用函数模板时才会使用，不要单独使用

/*
struct box
{
	double v;
};

//template <> void mymax(box x1, box x2);

template<typename T1, typename T2>
void mymax(T1 x, T2 y);

void mymax(char x, char y);

int main()
{
	box x1 = { 3 };
	box x2 = { 4 };
	string s1 = "abc";
	string s2 = "abcd";
	//char c = max('a', 'A');
	mymax(1, 3);
	mymax(1.3, 4);
	mymax<int>(3.3, 3);
	mymax('a', 'A');
	mymax(s1, s2) ;
	mymax(s1, "bcd");
}
template<typename T1, typename T2>
void mymax(T1 x, T2 y)
{
	cout << ((x > y) ? x : y) << endl;
}

void mymax(char x, char y)
{
	cout << (((x > y) ? x : y)) << endl;
}
*/

//8.7 T8
/*
struct box
{
	int v;
};
template<typename T1,typename T2>
void max(T1 x, T2 y);

template<> void max<box>(box x1, box x2);

void show(box b)
{
	cout << b.v << endl;
}

int main()
{
	box b1 = { 2 };
	box b2 = { 4 };
	max(23.3, 23);
	max(b1, b2);
}

template<typename T1, typename T2>
void max(T1 x, T2 y)
{
	cout << ((x > y) ? x : y) << endl;
}

template<> void max<box>(box x1, box x2)
{
	x1.v > x2.v ? show(x1) : show(x2);
}
*/

//8.8 T1
/*
void print(string s, int n = 1);

int main()
{
	print("hello",0);
	print(",babe", 3);
}

void print(string s, int n)
{
	if (n != 0)
	{
		cout << s << endl;
		print(s, --n);
	}
}
*/

//8.8 T2
/*
struct CandyBar
{
	string name;
	double w;
	int c;
};

CandyBar& init(CandyBar& candy, const char* ch, double w, int c);

int main()
{
	CandyBar candy;
	init(candy, "BigDick", 1.3, 300);
	cout << candy.name << " " << candy.w << " " << candy.c << endl;
}
CandyBar& init(CandyBar& candy, const char* ch, double w, int c)
{
	candy.name = ch;
	candy.w = w;
	candy.c = c;
	return candy;
}
*/

//8.8 T3
/*
void toup(string& s);

int main()
{
	string s;
	cout << "input string" << endl;
	getline(cin, s);
	while (s != "q")
	{
		toup(s);
		cout << s<<endl;
		cout << "input string" << endl;
		getline(cin, s);
	}
}

void toup(string& s)
{
	for (char &ch : s)
		if (isalpha(ch) && !isupper(ch))
			ch=toupper(ch);
}
*/

//8.8 T4
/*
using namespace std;

struct stringy
{
	char* str;
	int ct;
};

void set(stringy& sy, const char* cs);
void show(stringy sy, int n = 1);
void show(const char* cs, int n = 1);

int main()
{
	stringy beany;
	char testing[] = "do you really love me?";
	set(beany, testing);
	show(beany);
	show(beany, 3);
	show("yes");
	show("yes", 4);
	return 0;
}

void set(stringy& sy, const char* cs)
{
	int n = strlen(cs);
	sy.ct = n;
	sy.str = new char[n + 1];
	strcpy(sy.str, cs);
}
void show(stringy sy, int n )
{
	for (int i = 0; i < n; i++)
		cout << sy.str << endl;
}
void show(const char* cs, int n )
{
	for (int i = 0; i < n; i++)
		cout << cs << endl;
}
*/

//8.8 T5
/*
template<typename T>
T max5(T a[5]);

int main()
{
	int inta[5] = { 1,3,2,45,1 };
	double doublea[5] = { 1.3,1.112,1.131,1.22,1.13 };
	cout << max5(inta) << endl;
	cout << max5(doublea) << endl;
	return 0;
}

template<typename T>
T max5(T a[5])
{
	T max = a[0];

	for (int i=1;i<5;i++)
		max = a[i] > max ? a[i] : max;
	return max;
}
*/

//8.8 T6
/*
template<typename T>
T maxn(T a[], int n);

template<>  const char* maxn(const char* a[], int n);

int main()
{
	char a1[] = "I ";
	char a2[] = "love ";
	char a3[] = "you!";
	const char* a[3] = { a1,a2,a3 };
	int inta[5] = { 1,3,2,3,1, };
	double doublea[5] = { 1.2,1.3,1.45,1.3112,12123.12 };
	cout << maxn(inta, 5) << endl;
	cout << maxn(doublea, 5) << endl;
	cout << maxn(a, 3);
	return 0;
}

template<typename T>
T maxn(T a[], int n)
{
	if (n < 0)
	{
		cout << "error" << endl;
		exit(0);
	}
	T max = a[0];
	for (int i = 1; i < n; i++)
		max = max > a[i] ? max : a[i];
	return max;
}

template<> const char* maxn(const char* a[], int n)
{
	int max = strlen(a[0]);
	int index = 0;

	for (int i = 1; i < n; i++)
	{
		if (strlen(a[index]) < strlen(a[i]))
		{
			index = i;
			max = strlen(a[i]);
		}
	}
	return a[index];
}
*/

//8.8 T7
/*
struct debts
{
	double cost;
};

template<typename T>
void sum(T *a, int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	cout << "1--" << sum << endl;
}

template<typename T> void sum(T** a, int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += *a[i];
	cout << "2--" << sum << endl;
}

int main()
{
	debts d1 = { 1.312 };
	debts d2 = { 1.32 };
	debts d3 = { 2.12 };
	double* d[3] = { &d1.cost,&d2.cost,&d3.cost };
	double thing[5] = { 12.21,21,12,12,32 };
	sum(d, 3);
	sum(thing, 5);
}
*/