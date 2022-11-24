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

int main()
{
	BiTree T;
	InitBiT(T);
	InOrdBiT(T);
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
	if (T == NULL) return;
    else
    {
		cout << T->data;
		InOrdBiT(T->lchild);
		cout << T->data;
		InOrdBiT(T->rchild);
    }
}
