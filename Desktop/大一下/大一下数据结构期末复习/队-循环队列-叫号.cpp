#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
#define FLOW -1
#define MaxSize 100

typedef struct 
{
	int *base;
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue &Q);
void EnQueue(SqQueue &Q,int e);
void DeQueue(SqQueue &Q,int &e);
int QueueEmpty(SqQueue Q);

int main()
{
	int n;
	int e;
	int cnt=1;
	SqQueue Q;
	InitQueue(Q);
	while(1)
	{
		printf("1--ȡ��\n");
		printf("2--�к�\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
				EnQueue(Q,cnt);
				cnt++;
				break;
			case 2:
				if(!QueueEmpty(Q))
					printf("δ�����Ŷ�\n");
				else
				{
					DeQueue(Q,e);
					printf("��%dǰ����̨\n",e);
					break;	
				} 
			case 3:
				break;
		} 
	}
	return 0;
}

int InitQueue(SqQueue &Q)
{
	Q.front=0;
	Q.rear=Q.front;
	Q.base=(int*)malloc(sizeof(int)*MaxSize);
	if(!Q.base)
		return ERROR;
	
	return OK;
}
void EnQueue(SqQueue &Q,int e)
{
	if((Q.rear+1)%MaxSize==Q.front)
		return;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MaxSize;
}
void DeQueue(SqQueue &Q,int &e)
{
	if(Q.rear==Q.front)
		return;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MaxSize;
}
int QueueEmpty(SqQueue Q)
{
	if(Q.front==Q.rear)
		return ERROR;
		
	return OK;
}
