#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct
{
	int *base;
	int *top;
	int len;
}SqStack;

void InitStack(SqStack &Sq)
{
	Sq.base=(int *)malloc(sizeof(int)*MAXSIZE);
	Sq.top=Sq.base;
	Sq.len=0;
}

int Push(SqStack &Sq,int e)
{
	if(Sq.top-Sq.base==MAXSIZE)
		return 0;
	*Sq.top++ = e;
	Sq.len++;
	 
	return 1;
}

int Pop(SqStack &Sq,int &e)
{
	if(Sq.base==Sq.top)
		return 0;
	e=*--Sq.top;
	Sq.len--;
	
	return 1;
}

int main()
{
	int e;
	SqStack Sq;
	InitStack(Sq);
	printf("逐个输入入栈元素,以-1为结束\n");
	while(1)
	{
		scanf("%d",&e);
		if(e==-1) break;
		Push(Sq,e);
	}
	printf("\n");
	while(Sq.top!=Sq.base)
	{
		Pop(Sq,e);
		printf("%d",e);
	}
	return 0;
}
