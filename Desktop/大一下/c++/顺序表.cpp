#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int length;
 }SqList;
 
//void InitList(SqList &L);/*细节在此不表*/
int ListInsert(SqList &L,int i,ElemType e);

int main()
{
    SqList L;
	L.elem[0]=2;
	L.elem[1]=6;
	L.elem[2]=4;
	L.length=3;
    //InitList(L);
    ElemType e;
    int i;
    scanf("%d%d",&i,&e);
    int result=ListInsert(L,i,e);
    if(result==0){
        printf("Insertion Error.The value of i is unlawful or the storage space is full!");    
    }else if(result==1){
        printf("Insertion Success.The elements of the SequenceList L are:");    
        for(int j=0;j<L.length;j++){
            printf(" %d",L.elem[j]);
        }
    }
    return 0;
}

int ListInsert(SqList &L,int i,ElemType e)
{
	int index=L.length-1;
	if(L.length>=5)
		return 0;
	while(index>i-1)
	{
		L.elem[index+1]=L.elem[index];
		index--;
	}
	L.elem[i-1]=e;
	L.length++;
	
	return 1;
}


