#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20

typedef struct
{
	int key;
}Elemtype;

typedef struct 
{
	Elemtype *R;
	int len;
}SqList;

void HeapAdjust(SqList &L,int s,int m)
{
	Elemtype rc=L.R[s];
	int j;
	for(j=s*2;j<=m;j*=2)
	{
		if(j<m&&L.R[j].key<L.R[j+1].key) j++;
		if(rc.key>=L.R[j].key) break;
		L.R[s]=L.R[j];
		s=j;
	}
	L.R[s]=rc;
}

void creatHeap(SqList &L)
 {
 	int n=L.len;
 	for(int i=n/2;i>0;i--)
 		HeapAdjust(L,i,n);
 }

void HeapSort(SqList &L)
{
	creatHeap(L);
	int i; 
	for(i=L.len;i>1;i--)
	{
		Elemtype x=L.R[1];
		L.R[1]=L.R[i];
		L.R[i]=x;
		HeapAdjust(L,1,i-1);
	}
 }  

int main()
{
	SqList L;
	L.len=0;
	L.R=(Elemtype*)malloc(sizeof(Elemtype)*MAXSIZE);
	int e;
	int i=1;
	printf("请输入数列,中间以空格相连，以-1结束\n");
	scanf("%d",&e);
	getchar();
	while(e!=-1)
	{
		L.R[i].key=e;
		i++;
		L.len++;
		scanf("%d",&e);
		getchar();
	}
	
	printf("排前：\n"); 
	for(i=1;i<=L.len;i++)
		printf("%d ",L.R[i].key);
	
	printf("\n"); 
	HeapSort(L);
	
	printf("排后：\n");
	for(i=1;i<=L.len;i++)
		printf("%d ",L.R[i].key);
		
	return 0;
}
