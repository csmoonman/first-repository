#include<iostream>
using namespace std;

void swap(char *a,char *b);
void array_swap(int a[],int cnt);
void print(int a[],int cnt);

int main()
{
	int a[100];
	int cnt;
	cout<<"��������Ҫ�棿"<<endl;
	cin>>cnt;
	getchar();
	cout<<"�������룬�ո����:";
	for(int i=0;i<cnt;i++)
		cin>>a[i];
	getchar();
	cout<<"swapǰ��";
	print(a,cnt);
	cout<<endl<<"swap��";
	array_swap(a,cnt);
	print(a,cnt);
}

void swap(char *a,char *b)
{
	*a=*a ^ *b;
	*b=*a ^ *b;
	*a=*a ^ *b;
}

void array_swap(int a[],int cnt)
{
	int first=0,last=cnt-1;
	for(first;first<=last;first++,last--)
	{
		if(first==last) break;
		else
			swap(a[first],a[last]);
	}
}

void print(int a[],int cnt)
{
	for(int i=0;i<cnt;i++)
		cout<<a[i]<<" ";
}
