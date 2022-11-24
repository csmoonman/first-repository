#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	int key;
}Elemtype;

typedef struct BSTNode
{
	Elemtype data;
	BSTNode* lchild,* rchild;
}BSTNode,*BSTree;

void Insert(BSTree &T,int e)
{
	if(!T)
	{
		BSTNode* p=(BSTree)malloc(sizeof(BSTNode));
		p->data.key=e;
		p->lchild=NULL;
		p->rchild=NULL;
		T=p;
	}
	else if(e<T->data.key) Insert(T->lchild,e);
	else Insert(T->rchild,e);
}

void createBST(BSTree &T)
{
	T=NULL;
	int e;
	printf("请输入数据，之间以回车相隔\n");
	scanf("%d",&e);
	getchar();
	while(e!=-1)
	{
		Insert(T,e);
		scanf("%d",&e);
		getchar();
	}
}

BSTree SearchBST(BSTree T,int e)
{
	if(!T||T->data.key==e)
		return T;
	else if(e<T->data.key) return SearchBST(T->lchild,e);
	else return SearchBST(T->rchild,e);
}

int main()
{
	BSTree T;
	createBST(T);
	
	int e;
	printf("您要查找？\n");
	scanf("%d",&e);
	BSTree p=SearchBST(T,e);
	if(!T) printf("未有该元素!\n");
	else 	printf("%d",p->data.key);
	return 0;
}
