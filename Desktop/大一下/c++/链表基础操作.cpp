#include<stdio.h>
#include<stdlib.h>
#define  OK  1;
#define ERROR  0; 

typedef int statue;

typedef struct _list
{
	int data;
	struct _list* next;
}linklist;

typedef struct _head
{
	linklist *head;
	linklist *tail;
}headlist;

int initLinklist(headlist &head,headlist &tail);
int createLinklist(linklist &head,linklist &tail); 
void printlist(linklist &head);

int main()
{
	headlist* myQQ;
	int initFlag=initLinklist(myQQ,myQQ);
	
	while(initFlag)
	{
		initFlag=createLinklist(myQQ->head,myQQ->tail);
	}
	
	if(myQQ)
		printlist(myQQ->head);
		
	return 0;
}	

int initLinklist(headlist &head,headlist &tail)
{
	head=(linklist*)malloc(sizeof(linklist));
	tail=head;
	
	if(head==NULL)
		return ERROR;
		
	return OK;
}

int createLinklist(linklist &head,linklist &tail)
{
	linklist *p;
	p=(linklist*)malloc(sizeof(linklist));
	if(p==NULL)
		return ERROR;
		
	p->next=NULL;
	scanf("%d", &p->data);
	if(p->data==-1)//ÒÔ-1Îª½áÊø·û 
	{
		return ERROR;
	}
	
	if(head->next==NULL)
	{
		head->next=p;
	}
	else
	{
		tail->next=p;
		tail=p;
	}
	return OK;
}

void printlist(linklist &head)
{
	linklist *p=head;
	while(p)
	{
		scanf("%d",p->data);
		p=p->next;
	}
}
