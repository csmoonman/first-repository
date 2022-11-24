#include<iostream>
using namespace std;

class zz
{
private:
	int data[10];
	static const	int len=10;
public:
	zz();
	int& operator[](int n){return data[n];};
};

template <class T>
bool insertion_sort(T* a,int len)
{
	int i=1,j=0;
	for(i;i<len;i++)
	{
		T key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	
	return true;
}

template<class T>
bool merge(T* a,int p,int q,int r)
{
	T *left = new T[q-p+2];
	T *right = new T[r-q+1];
	int i=0,j=0;
	for(i;i<q-p+1;i++)
		left[i]=a[i+p];
	left[i]=88888;
	
	for(j;j<r-q;j++)
		right[j]=a[q+1+j];
	right[j]=88888;
		
	i=j=0;
	int k=p;
	for(k;k<r+1;k++)
	{
		if(left[i]<right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
	}
	
	return true;
}

template<class T>
bool mergesort(T* a,int p,int r)
{
	if(p>=r)
		return 0;
	int q=(p+r)/2;
	mergesort(a,p,q);
	mergesort(a,q+1,r);
	merge(a,p,q,r);
	
	return true;
}

template<class T>
int partition(T* a,int p,int r)
{
	int i=p-1;
	int j=p;
	T x=a[r];
	for(j;j<r;j++)
	{
		if(a[j]<=x)
		{
			i++;
			T temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	a[r]=a[i+1];
	a[i+1]=x;
	return i+1;
}

template<class T>
int partition(T &d,int p,int r)
{
	int i=p-1;
	int j=p;
	int x=d[r];
	for(j;j<r;j++)
	{
		if(d[j]<=x)
		{
			i++;
			int temp=d[j];
			d[j]=d[i];
			d[i]=temp;
		}
	}
	d[r]=d[i+1];
	d[i+1]=x;
	
	return i+1;
}

template<class T>
void quicksort(T*a,int p,int r)
{
	static int cnt=1;
	if(p<r)
	{
		int i;
		int q=partition(a,p,r);
		cout<<cnt++<<" "<<q<<": ";
		for(i=0;i<10;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

template<class T>
void quicksort(T &d,int p,int r)
{
	static int cnt=1;
	if(p<r)
	{
		int i;
		int q=partition(d,p,r);
		cout<<cnt++<<" "<<q<<": ";
		for(i=0;i<10;i++)
			cout<<d[i]<<" ";
		cout<<endl;
		quicksort(d,p,q-1);
		quicksort(d,q+1,r);
	}
}

zz::zz()
{
	int i;
	for(i=0;i<10;i++)
		data[i]=10-i;
}

int main()
{
	int a[10];
	double b[10];
	int c[10];
	zz d;
	int i;
	for(i=0;i<10;i++)
	{
		a[i]=10-i;
		b[i]=10.1-i;
		c[i]=19;
		d[i]=10-i;
	}
	quicksort(d,0,9);
	return 0;
}
