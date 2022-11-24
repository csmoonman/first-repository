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

void InitBiT(BiTree &T);
void InOrdBiT(BiTree T);
int CntLeafNode(BiTree T);
int CntDegree1Node(BiTree T);
int CntDegree2Node(BiTree T);
int CntNode(BiTree T);
int CntDepth(BiTree T);

int main()
{
	BiTree T;
	InitBiT(T);
	InOrdBiT(T);

	printf("\n叶结点个数：%d\n", CntLeafNode(T));
	printf("度为一结点个数：%d\n", CntDegree1Node(T));
	printf("度为二结点个数：%d\n", CntDegree2Node(T));
	printf("结点个数：%d\n", CntNode(T));
	printf("深度：%d\n", CntDepth(T));
	return 0;
}

void InitBiT(BiTree &T)
{
	char ch;
	cin >> ch;
	if (ch == '#') T = NULL;
    else
    {
		T = (BiTree)malloc(sizeof(BiTreeNode));
		T->data = ch;
		InitBiT(T->lchild);
		InitBiT(T->rchild);
	}
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

int CntDegree1Node(BiTree T)
{
	static int cnt=0;
	if(T)
	{
		CntDegree1Node(T->lchild);
		CntDegree1Node(T->rchild);
		if((T->lchild==NULL&&T->rchild!=NULL)||(T->lchild!=NULL&&T->rchild==NULL))
			cnt++;
	}
	return cnt;
}
int CntDegree2Node(BiTree T)
{
	static int cnt=0;
	if(T)
	{
		CntDegree2Node(T->lchild);
		CntDegree2Node(T->rchild);
		if(T->lchild!=NULL&&T->rchild!=NULL) cnt++;
	}
	return cnt;
}
int CntNode(BiTree T)
{
	static int cnt;
	if(T)
	{
		CntNode(T->lchild);
		CntNode(T->rchild);
		cnt++;
	}
	return cnt;
}
int CntDepth(BiTree T)
{
	int deep=0;
	if(T==NULL) return 0;
	else
	{
		int lcnt=CntDepth(T->lchild);
		int rcnt=CntDepth(T->rchild);
		deep=lcnt>rcnt ?  lcnt+1 :  rcnt+1;
	}
	return deep;
}
