#include<stdio.h>
#include<stdlib.h> 

typedef struct QNode
{
	char data;
	struct QNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* read;
}Queue;

void ini(Queue &Q)
{
	Q.head=(QNode*)malloc(sizeof(QNode));
	Q.head->next=NULL;
	Q.read=Q.head;
}
void EnQueue(Queue &Q,char e)
{
	QNode* p=(QNode*)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	Q.read->next=p;
	Q.read=p;	
}
void DeQueue(Queue &Q,char &e)
{
	QNode* s=(QNode*)malloc(sizeof(QNode));
	
	if(Q.head==Q.read)
		return;
	else if(Q.head->next==Q.read)
	{
		s=Q.read;
		Q.read=Q.head;
	}
	else
	{
		s=Q.head->next;
		Q.head->next=s->next;
	}
	e=s->data;
	free(s);
}

void printQueue(Queue q)
{
	char e;
	while(q.head!=q.read)
	{
		DeQueue(q,e);
		printf("%c", e);
	}
}

int main ()
{
	Queue q;
	char e;
	scanf("%c", &e);
	ini(q);
	while(e!='#')
	{
		EnQueue(q,e);
		scanf("%c",&e); 
	}
	printQueue(q);
	return 0;
}
