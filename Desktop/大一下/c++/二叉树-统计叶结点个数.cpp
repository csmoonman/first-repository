#include<stdio.h>
#include<malloc.h>
#define len sizeof(struct BiTNode )

typedef struct BiTNode
{
    char data;  //数据域
    struct BiTNode *lchild;  //左孩子指针
    struct BiTNode *rchild;  //右孩子指针
}BiTNode,*BiTree;

 void creat(BiTree &Tree);//构建二叉树
int countleaf(BiTree Tree);//求叶子结点个数
 
int main()
{
    BiTree Tree;
    creat(Tree);//创建二叉树
    printf("%d\n",countleaf(Tree)); //输入叶子节点个数
    return 0;
}

/* 请在这里填写答案 */
 void creat(BiTree &Tree)//构建二叉树
 {
 	char ch;
 	scanf("%c", &ch);
 	if(ch!='#')//先序 
 	{
 		Tree= (BiTree)malloc(sizeof(BiTNode));
 		Tree->data=ch;
 		creat(Tree->lchild);
 		creat(Tree->rchild);
	}
	else//一定不要忘了指空！！！！！！！！！！！ 
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
