#include<stdio.h>
#include<malloc.h>
#define len sizeof(struct BiTNode )

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

void InOrder(BiTree Tree);
 void creat(BiTree &Tree);
 
int main()
{
    BiTree Tree;
    creat(Tree);//����������
    InOrder(Tree);//�������
    return 0;
}

/* ����������д�� */
void InOrder(BiTree Tree)
{
	if(!Tree)
		return;
	InOrder(Tree->lchild);
	printf("%c", Tree->data);
	InOrder(Tree->rchild);
}
void creat(BiTree &Tree)
{
	char ch;
	scanf("%c", &ch);
	if(ch=='#')
		Tree=NULL;
	else
	{
		Tree=(BiTree)malloc(len);
		Tree->data=ch;
		creat(Tree->lchild);
		creat(Tree->rchild);
	}
}
