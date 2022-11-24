#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	char data;
	LNode* next;
}LNode,*Link;

typedef struct
{
	Link Head;
	Link Rear;
}ListLink;

void InitLink(ListLink &L)
{
	L.Head=(Link)malloc(sizeof(LNode));
	if(!L.Head)
		return;
	L.Head->next=NULL;
	L.Rear=L.Head;
} 

void AddNode(ListLink &L,char e)
{
	LNode* p=(Link)malloc(sizeof(LNode));
	
	p->next=NULL;
	p->data=e;
	L.Rear->next=p;
	L.Rear=p;
}

void printLink(ListLink L)
{
	LNode *p=L.Head->next;
	while(p!=NULL)
	{
		printf("%c",p->data);
		p=p->next;
	}
}

int main()
{
	ListLink L;
	InitLink(L);
	printf("插入几个数据元素？\n");
	int n;
	char e;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++)
	{
		scanf("%c",&e);
		AddNode(L,e);
	}
	printLink(L);
	
	return 0;
}
