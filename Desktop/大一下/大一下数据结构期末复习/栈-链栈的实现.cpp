#include<stdio.h>
#include<stdlib.h>

typedef struct StackNode
{
	int data;
	StackNode* next;
}StackNode,*LinkStack;

int InitLinkStack(LinkStack &Sq)
{
	Sq=NULL;
	
	return 1;
}

int PushLinkStack(LinkStack &Sq,int e)
{
	StackNode* p=(StackNode*)malloc(sizeof(StackNode));
	p->data=e;
	p->next=NULL;
	p->next=Sq;
	Sq=p;
	return 1;
}

int PopLinkStack(LinkStack &Sq,int &e)
{
	StackNode *p=Sq;
	if(Sq==NULL)	
		return 0;
	e=p->data;
	if(Sq->next==NULL)
		Sq=NULL;
	else
		Sq=Sq->next;
	free(p); 
	return 1;
}

int main()
{
	LinkStack Sq;
	InitLinkStack(Sq);
	int e;
	int n;
	printf("逐个输入元素，以-1结束\n");
	while(1)
	{
		scanf("%d",&e);
		if(e==-1)	break;
		PushLinkStack(Sq,e);
	}
	/*
	while(Sq!=NULL)
	{
		PopLinkStack(Sq,e);
		printf("%d",e);
	}
	*/
	while(1)
	{
		printf("出栈or入栈or退出？1/2/0\n"); 
		scanf("%d",&n);
		getchar();
		switch(n)
		{
			case 2:
				scanf("%d",&e);
				getchar();
				PushLinkStack(Sq,e);
				break;
			case 1:
				if(Sq!=NULL)
				{
					PopLinkStack(Sq,e);
					printf("%d\n",e);
				}
				else
					printf("空\n"); 
				break;
			case 0:
				break;
		}
		if(n==0) break;
	}
	return 0;
}
