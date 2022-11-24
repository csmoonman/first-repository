#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
#define FLOW -1

typedef struct QNode
{
	int data;
	struct QNode * next;
}QNode,*QNodePtr;

typedef struct
{
	QNodePtr front;
	QNodePtr rear;
}QLink;

int InitQueue(QLink &Q);
int EnQueue(QLink &Q,int e);
int DeQueue(QLink &Q,int &e);
int QueueEmpty(QLink Q);

int main()
{
	int n;
	int e;
	int cnt=1;
	QLink Q;
	InitQueue(Q);
	while(1)
	{
		printf("1--取号\n");
		printf("2--叫号\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
				EnQueue(Q,cnt);
				cnt++;
				break;
			case 2:
				if(!QueueEmpty(Q))
					printf("未有人排队\n");
				else
				{
					DeQueue(Q,e);
					printf("请%d前往柜台\n",e);
					break;	
				} 
			case 3:
				break;
		} 
	}
	return 0;
}

int InitQueue(QLink &Q)
{
	Q.front=(QNodePtr)malloc(sizeof(QNode));
	if(!Q.front)
		return ERROR;
	Q.front->next==NULL;
	Q.rear=Q.front;
	
	return OK;
}

int EnQueue(QLink &Q,int e)
{
	QNodePtr p=(QNodePtr)malloc(sizeof(QNode));
	p->next=NULL;
	p->data=e;
	Q.rear->next=p;
	Q.rear=p;
	
	return OK;
}
int DeQueue(QLink &Q,int &e)
{
	QNodePtr p=(QNodePtr)malloc(sizeof(QNode));
	p->next=NULL;
	if(Q.front==Q.rear)
		return ERROR;
	if(Q.front->next==Q.rear)
	{
		p=Q.rear;
		Q.rear=Q.front;
	}
	else
	{
		p=Q.front->next;
		Q.front->next=p->next;
	}
	e=p->data;
	free(p);
	
	return OK;
}
int QueueEmpty(QLink Q)
{
	if(Q.front==Q.rear)
		return ERROR;
	
	return OK;
}
