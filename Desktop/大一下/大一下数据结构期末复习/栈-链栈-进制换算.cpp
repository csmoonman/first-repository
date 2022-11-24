#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define FLOW -1
#define MaxSize 100
typedef struct SqNode
{
	int data;
	struct SqNode *next;
	int SqLen;
}SqNode,*SqLink;

void InitStack(SqLink &Sq);
int Push(SqLink &Sq,int e);
int Pop(SqLink &Sq,int &e);
int StackEmpty(SqLink Sq);

int main()
{
	SqLink Sq;
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
	while(Sq->next!=NULL)
	{
		int e;
		Pop(Sq,e);
		printf("%d",e);
	}	

	return 0;
}

void InitStack(SqLink &Sq)
{
	Sq=(SqNode*)malloc(sizeof(SqNode)); 
	Sq->next=NULL;
	Sq->SqLen=0;
}

int Push(SqLink &Sq,int e)
{
	SqNode* p=(SqNode*)malloc(sizeof(SqNode));
	p->data=e;
	p->next=Sq;
	Sq=p;
	Sq->SqLen++;
	return OK;
}

int Pop(SqLink &Sq,int &e)
{
	SqNode*p;
	if(Sq->next==NULL)
		return ERROR;

	p=Sq;
	Sq=Sq->next;
	e=p->data;
	free(p);	

	return OK;
}

int StackEmpty(SqLink Sq)
{
	if(Sq==NULL)
		return ERROR;
	
	return OK;
}

