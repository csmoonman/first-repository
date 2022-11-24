#include<stdio.h>
#include<stdlib.h>
#define m 20

typedef struct
{
	int key;
}Elemtype;

typedef struct 
{
	Elemtype *R;
	int len;
}SqList;

void InsertSort(SqList &L)
{
	int i,j;
	for(i=2;i<=L.len;i++)
	{
		if(L.R[i].key<L.R[i-1].key)
		{
			L.R[0]=L.R[i];
			L.R[i]=L.R[i-1];
			for(j=i-2;L.R[j].key>L.R[0].key;j--)
				L.R[j+1]=L.R[j];
			L.R[j+1]=L.R[0];
		}
	}
}

int main()
{
	SqList L;
	L.len=0;
	L.R=(Elemtype*)malloc(sizeof(Elemtype)*m);
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
	InsertSort(L);
	
	printf("排后：\n");
	for(i=1;i<=L.len;i++)
		printf("%d ",L.R[i].key);
		
	return 0;
}


