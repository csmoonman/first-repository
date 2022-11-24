#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode
{
	char data;
	BiTNode* lchild,*rchild;
}BiTNode,*BiTree;

int CreateBiTree(BiTree &T)
{
	char ch;
	scanf("%c",&ch);
	if(ch!='#')
	{
		T=(BiTree)malloc(sizeof(BiTNode));
		T->lchild=NULL;
		T->rchild=NULL;	
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	else T=NULL;
	
	return 1;
}

void PreOrder(BiTree T)
{
	if(T==NULL)	return;
	else
	{
		printf("%c",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BiTree T)
{
	if(T==NULL)	return;
	else
	{
		InOrder(T->lchild);
		printf("%c",T->data);
		InOrder(T->rchild);
	}
}

void PostOrder(BiTree T)
{
	if(T==NULL)	return;
	else
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c",T->data);
	}
}

int cntLeaf(BiTree T)
{
	static int cnt=0;
	if(T)
	{
		cntLeaf(T->lchild);
		cntLeaf(T->rchild);
		if(T->lchild==NULL&&T->rchild==NULL) cnt++;
	}
	return cnt;
}

int cntDegree1Node(BiTree T)
{
	static int cnt=0;
	if(T)
	{
		cntDegree1Node(T->lchild);
		cntDegree1Node(T->rchild);
		if(T->lchild==NULL&&T->rchild!=NULL || T->lchild!=NULL&&T->rchild==NULL) cnt++;
	}
	return cnt;
}

int cntDegree2Node(BiTree T)
{
	static int cnt=0;
	if(T)
	{
		cntDegree2Node(T->lchild);
		cntDegree2Node(T->rchild);
		if(T->lchild!=NULL&&T->rchild!=NULL) cnt++;
	}
	return cnt;
}

int cntNode(BiTree T)
{
	if(T==NULL) return 0;
	else return cntNode(T->lchild)+cntNode(T->rchild)+1;
}

int cntDepth(BiTree T)
{
	int m,n;
	if(T==NULL) return 0;
	else
	{
		m=cntDepth(T->lchild);
		n=cntDepth(T->rchild);
	}
	if(m>=n) return m+1;
	else return n+1;
}



int main()
{
	BiTree T;
	printf("�밴�������룺\n"); 
	CreateBiTree(T);
	
	int n;
	int e;
	while(1)
	{
		printf("1--�������\n2--�������\n3--�������\n");
		printf("4--ͳ��Ҷ�ӽ��\n5--ͳ�ƶ�Ϊһ�Ľ��\n6--ͳ�ƶ�Ϊ���Ľ��\n");
		printf("7--ͳ�����н����\n8--ͳ������\n0--�˳�\n");
		scanf("%d",&n);
		getchar();
		switch(n)
		{
			case 1:
				PreOrder(T);
				printf("\n");
				break;
			case 2:
				InOrder(T);
				printf("\n");
				break;
			case 3:
				PostOrder(T);
				printf("\n");
				break;
			case 4:
				e=cntLeaf(T);
				printf("Ҷ�������%d\n",e);
				break;
			case 5:
				e=cntDegree1Node(T);
				printf("��Ϊ1�Ľ������%d\n",e);
				break;
			case 6:
				e=cntDegree2Node(T);
				printf("��Ϊ2�Ľ����:%d\n",e);
				break;
			case 7:
				e=cntNode(T);
				printf("���Ľ������%d\n",e);
				break;
			case 8:
				e=cntDepth(T);
				printf("���ĸ߶�Ϊ��%d\n",e);
				break;
			case 0:
				break;
		}
		if(n==0) break;
	}
	return 0;
}
