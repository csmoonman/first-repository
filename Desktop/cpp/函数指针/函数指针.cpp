#include<iostream>

using namespace std;

double sum(double x, double y);
double mult(double x, double y);
double a(double (*p)(double, double));

double* cnt(double x, double y);

int main()
{
	double (*psum)(double, double);
	psum = sum;
	double (*pmult)(double, double);
	pmult = mult;
	double(*p[2])(double, double) = { sum,mult };
	double x = 3, y = 6;
	cout << (psum)(x, y) << " " << (*psum) (x, y) << endl;
	cout << pmult(x, y) << " " << (*pmult)(x, y) << endl;
	cout << (*p[0])(x, y) << " " << (*p[1])(x, y) << endl;

	cout << a(sum) << endl;//传入函数的地址

	double* (*pcnt)(double, double);
	pcnt = cnt;
	cout << pcnt(x, y) << " " << *pcnt(x, y);
}

double sum(double x, double y)
{
	return x + y;
}
double mult(double x, double y)
{
	return x * y;
}

double a(double (*p)(double, double))
{
	//p = mult;
	double x = 1, y = 2;
	return p(1, 2);
}

double* cnt(double x, double y)
{
	double* p = new double;
	*p = x + y;
	return p;
}