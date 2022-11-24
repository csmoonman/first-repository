#include<iostream>
using namespace std;

typedef struct BNode
{
	char data;
	BNode* lchild,* rchild;
}*BTree;

int CreateBiTree(BTree& T)
{
	char ch;
	cin>>ch;
	if(cin&&ch!='#')
	{
		T=new BNode;
		T->lchild=NULL;
		T->rchild=NULL;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	else T=NULL;
	
	return 1;
}

void PreOrder(const BTree T)
{
	if(T==NULL) return;
	else
	{
		cout<<T->data;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	 } 
}

int main()
{
	BTree T;
	CreateBiTree(T);
	PreOrder(T);
}
