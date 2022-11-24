#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct LinkNode
{
	int data;
	LinkNode* next;
}LinkNode;

typedef struct LinkList
{
	LinkNode *head;
	LinkNode *rear;
}LinkList;

void iniLink(LinkList &L);
void deleteNode();
void addNode(LinkList &L,int data);
void printList(LinkList L);

int main()
{
	LinkList QQ;
	iniLink(QQ);
	int n;
	printf("是否创建链表？1/0\n");
	scanf("%d", &n);
	while(n)
	{
		printf("请输入一个数字\n");
		scanf("%d",&n);
		addNode(QQ,n);
		printf("是否继续？1/0\n");
		scanf("%d",&n);
	}
	printList(QQ);
		
	return 0;
}

void iniLink(LinkList &L)
{
	L.head=(LinkNode*)malloc(sizeof(LinkNode));
	if(!L.head)
		return;
	L.head->next=NULL;
	L.rear=L.head;
}

void deleteNode();
void addNode(LinkList &L,int data)
{
	LinkNode* p=(LinkNode*)malloc(sizeof(LinkNode));
	if(p==NULL)
		return;
	p->next=NULL;
	p->data=data;
	L.rear->next=p;
	L.rear=p;	
}

void printList(LinkList L)
{
	if(L.head->next==NULL)
		return;
	LinkNode* p=L.head->next;
	while(p)
	{
		printf("%d", p->data);
		p=p->next;
	}
}

