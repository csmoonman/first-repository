#include<iostream>

using namespace std;

//7.12 T3
/*
void T3(int arr[], int x,int len)
{
	for (int i = 0; i < len; i++)
		arr[i] = x;
}
*/

//7.12 T4 填充数组
/*
void T4(int* begin, int* end, int x)
{
	for (int* i = begin; i != end; i++)
	{
		*i = x;
	}
}
*/

//7.12 T5 返回最大值
/*
double T5(double arr[], int len)
{
	int max = arr[0];
	for (int i = 1; i < len; i++)
		if (max > arr[i])
			max = arr[i];
}
*/

//7.12 T11
/*
int judge(int (*p)(const char* pchar));
*/

//7.12 T12
/*
struct applicant
{
	char name[30];
	int credit_ratings[3];
};

void a(struct applicant a)
{
	for (int i = 0; i < 3; i++)
		cout << a.credit_ratings[i];
	cout << a.name;
}

void b(const struct applicant* pb)
{
	for (int i = 0; i < 3; i++)
		cout << pb->credit_ratings[i];
	cout << pb->name;
}
*/

//7.12 T13
/*
struct applicant
{
	char name[30];
	int credit_ratings[3];
};
void f1(applicant* a);
const char* f2(const applicant* a1, const applicant* a2);

typedef const char* F2;
int main()
{
	void (*p1)(applicant * a) = f1;
	const char* (*p2)(const applicant * a1, const applicant * a2) = f2;

	void* ap[5];
	F2(*pa)[10];
}
*/

//7.13 T1
/*
double H_aver(double x, double y);

int main()
{
	double x, y;
	cin >> x;
	cin >> y;
	while (x != 0 && y != 0)
	{
		cout << H_aver(x, y) << endl;
		cin >> x >> y;
	}
}

double H_aver(double x, double y)
{
	return 2.0 * x * y / (x + y);
}
*/

//7.13 T2
/*
int input(double* scores);
void out(const double* scores,int cnt);
void aver(double* scores,int cnt);

int main()
{
	double scores[10];
	int len = input(scores);
	if (len != 0)
	{
		out(scores, len);
		aver(scores, len);
	}
}

int input(double* scores)
{
	int cnt=0;
	cout << "输入至多十个成绩，以q结束" << endl;
	cin >> *scores;
	//if (cin) cnt++;

	while (cin)
	{
		cnt++;
		cin >> *(++scores);
	}
	cin.clear();

	return cnt;
}
void out(const double* scores, int cnt)
{
	int i = 0;
	for (i; i < cnt; i++)
		cout << scores[i] << " ";
	cout << endl;
}
void aver(double* scores, int cnt)
{
	double aver = 0;
	for (int i = 0; i < cnt; i++)
		aver += scores[i];
	cout << aver / cnt;
}
*/

//7.13 T3
/*
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void out(struct box b);
void set(struct box* b);

int main()
{
	struct box b =
	{
		"fucker",
		10,
		10,
		10,
		0
	};
	set(&b);
	out(b);
}

void out(struct box b)
{
	cout << b.maker << endl;
	cout << "height:" << b.height << endl;
	cout << "length:" << b.length << endl;
	cout << "width:" << b.width << endl;
	cout << "volume:" << b.volume << endl;
}
void set(struct box* b)
{
	b->volume = b->height * b->length * b->width;
}
*/

//7.13 T5
/*
long long f(long long x);

int main()
{
	int x;
	while (1)
	{
		cin >> x;
		if (!cin || x < 0) break;
		x = f(x);
		cout << x << endl;
	}
}

long long f(long long x)
{
	if (x == 0 || x == 1) return 1;
	return x * f(x - 1);
}
*/

//7.13 T6
/*
int Fill_array(double* a, int len);

int main()
{
	int len;
	cout << "len:";
	(cin >> len).get();
	double* a = new double[len+1];

	int n = 0;
	n = Fill_array(a, len);
	cout << n << endl;
	delete[]a;
}

int Fill_array(double* a, int len)
{
	(cin >> *a).get();
	int cnt = 0;
	while (cin || cnt < len)
	{
		cnt++;
		(cin >> *(++a));
	}

	return cnt;
}
*/

//7.13 T10
/*
double calculate(double x, double y, int key,double (*p[2])(double a, double b));
double add(double x, double y)
{
	return x + y;
}
double mult(double x, double y)
{
	return x * y;
}

int main()
{
	cout << "每次输入三个数字，前两个为运算因子，第三个为运算指示符（0为加法，其余为乘）" << endl;
	double (*p[2])(double x, double y) = {add,mult};
	double(*(*pa)[2])(double x, double y) = &p;
	double x, y;
	int n;
	cin >> x >> y>>n;
	while (cin)
	{
		cout << calculate(x, y, n,*pa) << endl;
		cin >> x >> y>>n;
	}
}

double calculate(double x, double y,int n, double (*p[2])(double a, double b))
{
	if(n==0)
		return p[0](x, y);
	return p[1](x, y);
}
*/