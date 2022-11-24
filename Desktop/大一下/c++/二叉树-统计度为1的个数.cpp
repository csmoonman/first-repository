#include<iostream>
using namespace std;
typedef struct BiNode{                
    char data;
    struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T){    
    char ch;
    cin >> ch;
    if(ch=='#')  T=NULL;            
    else{                            
        T=new BiTNode;
        T->data=ch;                
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

int NodeCount ( BiTree T)
{ 
	if(T==NULL) return 0;
	if(T->lchild==NULL&&T->rchild!=NULL)
		return NodeCount(T->rchild)+1;
 	if(T->lchild!=NULL&&T->rchild==NULL)
  		return NodeCount(T->lchild)+1;
 
	return NodeCount(T->rchild)+NodeCount(T->lchild);
}

int main(){
    BiTree T;
    CreateBiTree(T);
    printf("%d", NodeCount(T));
    return 0;
}
