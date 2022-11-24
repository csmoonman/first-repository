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
	printf("���������ݣ�֮���Իس����\n");
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
	printf("��Ҫ���ң�\n");
	scanf("%d",&e);
	BSTree p=SearchBST(T,e);
	if(!T) printf("δ�и�Ԫ��!\n");
	else 	printf("%d",p->data.key);
	return 0;
}
