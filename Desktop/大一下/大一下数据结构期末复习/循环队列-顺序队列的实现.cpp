#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100 
typedef struct 
{
	int *base;
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue &Q)
{
	Q.base=(int*)malloc(sizeof(int)*MAXSIZE);
	Q.front=0;
	Q.rear=0;
	return 1;
}

int EnQueue(SqQueue &Q,int e)
{
	if((Q.rear+1)%MAXSIZE==Q.front)
		return -1;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return 1;
}

int DeQueue(SqQueue &Q,int &e)
{
	if(Q.front==Q.rear)
		return 0;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	
	return 1;
}

int main()
{
	SqQueue Q;
	int n=1,e;
	int t;
	InitQueue(Q);
	while(1)
	{
		printf("�Ŷ�or�к�or�˳���1/2/0\n");
		scanf("%d",&t);
		getchar();
		switch(t)
		{
			case 1:
				EnQueue(Q,n);
				printf("�Ŷӳɹ������ĺ��룺%d\n",n);
				n++;
				break;
			case 2:
				if(Q.front!=Q.rear)
				{
					DeQueue(Q,e);
					printf("%dȡ��\n",e);
				}
				else
					printf("�����Ŷ�\n");
				break;
			case 0:
				break;
		}
		if(t==0)
			break;
	}
}
