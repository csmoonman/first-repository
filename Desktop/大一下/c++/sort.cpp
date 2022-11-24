#include<iostream>

using namespace std;

template<class T>
void mergesort(T * a,int p,int q)
{
	int size=sizeof(a)/sizeof(T);
	int i=p;
	int j=p+1;
	T key;
	
	for(j;j<q;j++)
	{
		T key=a[j];
		i=j-1;
		while(i>0&&a[i]>a[j])
		{
			a[j]=a[i];
			--i;
		}
		a[i+1]=key;
	}
}

template<class T>
void merge(T* a,int p, int r)
{
	int q=(p+r)/2;
	if(p<q)
	{
		merge(a,p,q);
		merge(a,q+1,r);
		mergesort(a,p,q);
		mergesort(a,q+1,r);
	}
}

int main()
{
	double *a=new double[10];
	int i=0;
	int n=10;
	for(i;i<10;i++)
		a[i]=(n--);
		
	i=0;
	for(i;i<10;i++)
		cout<<a[i]<<" ";
		
	cout<<endl;
	merge(a,0,10);
	
	i=0;
	
	for(i;i<10;i++)
		cout<<a[i]<<" ";
	return 0;
} 


