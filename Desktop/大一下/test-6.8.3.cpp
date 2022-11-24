#include<stdio.h>
#include<stdlib.h>
#define MaxNum 100
typedef int StackType;

typedef struct StackNode
{
	StackType *top;
	StackType *base;
	int StackMaxSize;
}StackNode;

void InitStack(StackNode &Sq);
int Push(StackNode &Sq,StackType e);
int Pop(StackNode &Sq,StackType &e);
int EmptyStack(StackNode Sq);

int main()
{
	StackNode Sq;
	InitStack(Sq);
	int m,n,r;
	printf("换算进制\n");
	printf("将10换至：\n");
	scanf("%d", &n);
	printf("输入十进制数:\n"); 
	scanf("%d", &m);
	
	r=m%n;
	while(m!=0)
	{
		m/=n;
		Push(Sq,r);
		r=m%n;
	}
	while(Sq.base!=Sq.top)
	{
		int e;
		Pop(Sq,e);
		printf("%d",e);
	}	
	return 0;
}

void InitStack(StackNode &Sq)
{
	Sq.base=(StackType*)malloc(sizeof(StackType)*MaxNum);
	
	Sq.StackMaxSize=MaxNum;
	Sq.top=Sq.base;
}

int Push(StackNode &Sq,StackType e)
{
	if(Sq.top-Sq.base==Sq.StackMaxSize)
		return 0;
	else
		*(Sq.top++) = e;
		
	return 1;
}
int Pop(StackNode &Sq,StackType &e)
{
	if(!EmptyStack(Sq))
		return 0;
	else
		e=*--Sq.top;
	return 1;
}

int EmptyStack(StackNode Sq)
{
	if(Sq.base==Sq.top)
		return 0;
	else return 1;
}
