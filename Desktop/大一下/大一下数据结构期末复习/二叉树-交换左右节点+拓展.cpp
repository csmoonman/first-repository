# include<stdio.h>
# include<stdlib.h>
# include<iostream>
using namespace std;
typedef char ElemType;

typedef struct BiTreeNode
{
	ElemType data;
	struct BiTreeNode* lchild,* rchild;
}BiTNode,*BiTree;

int CntLeafNode(BiTree T);
void InitBiT(BiTree &T);
void Exchange(BiTree &T);
void InOrdBiT(BiTree T);

int main()
{
	BiTree T;
	InitBiT(T);
	InOrdBiT(T);
	printf("\n叶结点个数：%d\n", CntLeafNode(T));
	Exchange(T);
	InOrdBiT(T);
	return 0;
}

void InOrdBiT(BiTree T)
{
	if(T) 
    {
		InOrdBiT(T->lchild);
		cout << T->data;
		InOrdBiT(T->rchild);
    }
}

void InitBiT(BiTree &T)
{
	char ch;
	scanf("%c", &ch);
	if(ch!='#')
	{
		T=(BiTree)malloc(sizeof(BiTNode));
		T->data=ch;
		InitBiT(T->lchild);
		InitBiT(T->rchild);
	}
	else T=NULL;
}

int CntLeafNode(BiTree T)
{
	static int cnt=0;
	if(T)
	{
		CntLeafNode(T->lchild);
		CntLeafNode(T->rchild);
		if(T->lchild==NULL&&T->rchild==NULL) cnt++;
	}
	return cnt;
}

void Exchange(BiTree &T)
{
	if(T)
	{
		Exchange(T->lchild);
		Exchange(T->rchild);
		if(T->lchild&&T->rchild)
		{
			char ch=T->lchild->data;
			T->lchild->data=T->rchild->data;
			T->rchild->data=ch;
		}

	}
}
