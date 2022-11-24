#include<iostream>

using namespace std;

int main()
{
	int a[3] = { 1,2,3 };
	int b[3] = { 4,5,6 };
	int c[3] = { 7,8,9 };

	int* pA[3] = { a,b,c };

	for (int *x : pA)
	{
		cout << *x << " " << *(x+1) << " " << *(x + 2) << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << *(pA[i] + j) << " " << endl;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << *(*(pA + i) + j) << " ";
		}
	}
}