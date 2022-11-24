#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0

typedef int status;

typedef struct QNode
{
	char ch;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct Queue
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

status iniQueue(LinkQueue &Q);
status enQueue(LinkQueue &Q,char ch);
status ouQueue(LinkQueue &Q,char &ch);

int main()
{
	int n;
	char chS,chH;
	scanf("%d", &n);
	
	if(n<2||n>10)
	{
		printf("ERROR");
		return 0;
	}
	
	LinkQueue QS;
	LinkQueue QH; 
	iniQueue(QS);
	iniQueue(QH);
	char s[n];
	scanf("%s", s);
	
	for(int i=0;i<n;i++)
	{
		if(s[i]=='S')
			enQueue(QS,s[i]);
		else
			enQueue(QH,s[i]);
	}
	
	int i=1;
	while(i<=n)
	{
		if(ouQueue(QH,chH))
			printf("%c", chH);
		if(ouQueue(QS,chS))
			printf("%c", chS);
		i++;
	}
	
	return 0;
}

status iniQueue(LinkQueue &Q)
{
	Q.front=(QueuePtr)malloc(sizeof(QNode));
	if(Q.front==NULL)
		return ERROR;
	Q.rear=Q.front;
	Q.front->next=NULL;
	return OK;
}

status enQueue(LinkQueue &Q,char ch)
{
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(s==NULL)
		return NULL;
	
	s->ch=ch;
	Q.rear->next=s;
	Q.rear=s;
	return OK;
}

status ouQueue(LinkQueue &Q,char &ch)
{
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	s=Q.front->next;
	if(Q.front==Q.rear)
		return ERROR;
	if(s==Q.rear)
	{
		Q.rear=Q.front;
		ch=s->ch;
		free(s);
	}
	else
	{
		Q.front->next=s->next;
		ch=s->ch;
		free(s);
	}
	
	return OK;
}
