#include<iostream>
using namespace std;

template<class T>
void insertion_sort(T* A)
{
	int array_len = sizeof(A)/sizeof(T);
	cout << array_len << endl;
	T key;
	int i = 1;
	int j = 0;
	for (i=1; i < 10; i++)
	{
		key = A[i];
		j = i - 1;
		while (j >= 0 &&  (A[j] > key))
		{
			A[j+1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}

int main()
{
	double *a=new double[10];
	for (int i = 0; i < 10; i++)
		a[i] = 10.1 - i;

	insertion_sort(a);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
}
