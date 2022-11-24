/*
#include<iostream>
using namespace std;

template<class T>
void merge(T* A, int p, int q, int r)
{
	int i = 0, j = 0;
	T* L = new int[q - p + 2];
	T* R = new int[r - q + 1];
	L[q - p + 1] = 88888;
	R[r - q] = 88888;

	for (i; i < q-p + 1; i++)
		L[i] = A[p + i];

	for (j; j < r - q; j++)
		R[j] = A[q + 1 + j];

	i = 0;
	j = 0;
	int k = p;
	for (k; k < r + 1; k++)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}

	delete[]L;
	delete[]R;
}

template<class T>
void mergesort(T* A, int p, int r)
{

	if (p<r)
	{
		int q = (p + r) / 2;
		mergesort(A, p, q);
		mergesort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main()
{
	int* a = new int[10];
	int j = 0;
	for (j; j < 10; j++)
		a[j] = 10 - j;

	int i = 0;
	for (i; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;

	mergesort(a, 0, 9);
	
	for (i=0; i < 10; i++)
		cout << a[i] << " ";
}
*/