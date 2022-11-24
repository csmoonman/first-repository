#include<iostream>
#include<climits>

using namespace std;

template<class T>
int partition(T* a,unsigned int min_index,unsigned int max_index)
{
	unsigned int i=min_index-1;
	unsigned int j=min_index;
	T x=a[max_index];//选取最后一个为主元 

	for(j;j<max_index;j++)
	{
		if(a[j]<=x)
		{
			++i;
			T temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	a[max_index]=a[i+1];
	a[i+1]=x;
	
	return i+1;
 } 
 
template<class T>
void quicksort(T* a,unsigned int min_index,unsigned int max_index)
{
	if(min_index<max_index)
	{
		unsigned int mid_index=partition(a,min_index,max_index);
		quicksort(a,min_index,mid_index-1);
		quicksort(a,mid_index+1,max_index);
	}
}

template<class T>
void insertion_sort(T* a,unsigned int array_len)
{
	unsigned int i=1;
	unsigned int j=0;
	for(i;i<array_len;i++)
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
}

template<class T>
void merge(T* a,unsigned int min_index,unsigned int mid_index,unsigned int max_index)
{
	T* left=new T[mid_index-min_index+2];
	T* right= new T[max_index-mid_index+1];
	
	unsigned int i=0;
	unsigned int j=0;
	unsigned int k=min_index;
	
	for(i;i<mid_index-min_index+1;i++)
		left[i]=a[min_index+i];
	left[i]=INT_MAX;

	for(i=0;i<max_index-mid_index;i++)
		right[i]=a[mid_index+1+i];
	right[i]=INT_MAX;
	
	i=0;

	for(k;k<max_index+1;k++)
	{
		if(left[i]<right[j])
			a[k]=left[i++];
		else
			a[k]=right[j++];
	}
	
	delete [] left;
	delete [] right;
}

template<class T>
void mergesort(T* a,unsigned int min_index,unsigned int max_index)
{
	if(min_index<max_index)
	{
		unsigned int mid_index=(min_index+max_index)/2;
		mergesort(a,min_index,mid_index);
		mergesort(a,mid_index+1,max_index);
		merge(a,min_index,mid_index,max_index);
	}
}

int main()
{
	int a[10];
	int i;
	for(i=0;i<10;i++)
		a[i]=10-i;
		
	//quicksort(a,0,9);
	//insertion_sort(a,10);
	mergesort(a,0,9);
	
	for(i=0;i<10;i++)
		cout<<a[i]<<" ";
	
	cout<<endl;
}
