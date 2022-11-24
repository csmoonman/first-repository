#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0

typedef struct SqNode
{
	int data;
	struct SqNode* next;
}SqNode,*SqLink;

int InitSq(SqLink &Sq);
int Push(SqLink &Sq,int e);
int Pop(SqLink &Sq,int &e);
int StackEmpty(SqLink Sq);

int main()
{
	SqLink Sq;
	InitSq(Sq);
	printf("请输入运算对象x y z\n");
	char ch;
	int temp;
	while(ch!=EOF)
	{
		if(ch<='9'&&ch>='0')
		{
			Push(Sq,ch-'0');
			ch=getchar();
			while(ch<='9'&&ch>='0')
			{
				Pop(Sq,temp);
				Push(Sq,temp*10+ch-'0');
				ch=getchar();
			}
		}
		else if(ch=='-'||ch=='+'||ch=='*'||ch=='/')
		{
			int a,b;
			Pop(Sq,b);
			Pop(Sq,a);
			if(ch=='-')
				temp=a-b;
			else if(ch=='+')
				temp=a+b;
			else if(ch=='*')
				temp=a*b;
			else
				temp=a/b;
			Push(Sq,temp);
		}
		else if(ch=='\n')
			break;
		ch=getchar();
	}
	Pop(Sq,temp);
	printf("%d", temp);
	return 0;
}

int InitSq(SqLink &Sq)
{
	Sq=(SqLink)malloc(sizeof(SqNode));
	if(!Sq)
		return ERROR;
	Sq->next=NULL;
	
	return OK;
}
int Push(SqLink &Sq,int e)
{
	SqLink p=(SqLink)malloc(sizeof(SqNode));
	p->next=Sq;
	p->data=e;
	Sq=p;
	return OK;
}

int Pop(SqLink &Sq,int &e)
{
	SqLink p=(SqLink)malloc(sizeof(SqNode));
	if(!StackEmpty(Sq))
		return ERROR;
	p=Sq;
	e=p->data;
	Sq=Sq->next;
	return OK;
}

int StackEmpty(SqLink Sq)
{
	if(Sq->next==NULL)
		return ERROR;
	return OK;
}

