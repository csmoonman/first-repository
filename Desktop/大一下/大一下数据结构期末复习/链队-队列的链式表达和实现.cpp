#include<stdio.h>
#include<stdlib.h>

typedef struct QNode
{
	int data;
	QNode* next;
}QNode,*QueuePtr;

typedef struct 
{
	QueuePtr front;
	QueuePtr rear;
}QLink;

int InitQueue(QLink &Q)
{
	Q.front=(QueuePtr)malloc(sizeof(QNode));
	if(Q.front==NULL) return 0;
	
	Q.front->next=NULL;
	Q.rear=Q.front;
	
	return 1;
}

int EnQueue(QLink &Q,int e)
{
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(p==NULL) return 0;
	
	p->next=NULL;
	p->data=e;
	Q.rear->next=p;
	Q.rear=p;
	
	return 1;
}

int DeQueue(QLink &Q,int &e)
{
	QueuePtr p;
	if(Q.front==Q.rear)  return 0;
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
	
	return 1;
}

int main()
{
	QLink Q;
	InitQueue(Q);
	int cnt=1,n,e;
	while(1)
	{
		printf("排队or叫号or退出？1/2/0\n");
		scanf("%d",&n);
		getchar();
		switch(n)
		{
			case 1:
				EnQueue(Q,cnt);
				cnt++; 
				break;
			case 2:
				if(Q.front==Q.rear)
					printf("无人排队！\n");
				else
				{
					DeQueue(Q,e);
					printf("%d前来取餐\n",e);
				}
				break;
			case 0: break;
		}
		if(n==0) break;
	}
}
