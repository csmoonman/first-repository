#include<iostream>
using namespace std;

typedef struct BiNode
{                
    char data;                    
    struct BiNode *lchild,*rchild;    
}BiTNode,*BiTree;


void CreateBiTree(BiTree &T)
{    
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

int Depth(BiTree T)
{ 
    int m,n;
    if(
T==NULL
) return 0;        
    else 
    {                            
        
m=Depth(T->lchild)
;            
        
n=Depth(T->rchild)
;            
        if(m>n) return(m+1);        
        else return (n+1);
    }
}

int main()
{
    BiTree tree;
    CreateBiTree(tree);
    cout<<Depth(tree);
    return 0;

}
