#include<stdio.h>
#include<malloc.h>
#define len sizeof(struct BiTNode )

typedef struct BiTNode
{
    char data;  //������
    struct BiTNode *lchild;  //����ָ��
    struct BiTNode *rchild;  //�Һ���ָ��
}BiTNode,*BiTree;

 void creat(BiTree &Tree);//����������
int countleaf(BiTree Tree);//��Ҷ�ӽ�����
 
int main()
{
    BiTree Tree;
    creat(Tree);//����������
    printf("%d\n",countleaf(Tree)); //����Ҷ�ӽڵ����
    return 0;
}

/* ����������д�� */
 void creat(BiTree &Tree)//����������
 {
 	char ch;
 	scanf("%c", &ch);
 	if(ch!='#')//���� 
 	{
 		Tree= (BiTree)malloc(sizeof(BiTNode));
 		Tree->data=ch;
 		creat(Tree->lchild);
 		creat(Tree->rchild);
	}
	else//һ����Ҫ����ָ�գ��������������������� 
		Tree=NULL;
 }

int countleaf(BiTree Tree)
{
	if(Tree==NULL)
		return 0;
	else if(Tree->lchild==NULL&&Tree->rchild==NULL)
	{
		return 1;
	}
	else 
		return countleaf(Tree->lchild)+countleaf(Tree->rchild);

	/*
	if(Tree->lchild!=NULL&&Tree->rchild==NULL)
		return countleaf(Tree->lchild)+1;
	if(Tree->lchild==NULL&&Tree->rchild!=NULL)
		return countleaf(Tree->rchild);
	if(Tree->lchild!=NULL&&Tree->rchild!=NULL)
	*/
}
