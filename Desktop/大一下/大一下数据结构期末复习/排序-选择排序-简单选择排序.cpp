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

void SelectSort(SqList &L)
{
	int i;
	int k;
	int j;
	for(i=1;i<L.len;i++)
	{
		k=i;//用来记录i以后的最小值下标 
		for(j=i+1;j<=L.len;j++)
			if(L.R[j].key<L.R[k].key) k=j;
		if(k!=i)//如果i后面存在比L.R[i].key小的值，交换位置 
		{
			Elemtype t=L.R[i];
			L.R[i]=L.R[k];
			L.R[k]=t;
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
	SelectSort(L);
	
	printf("排后：\n");
	for(i=1;i<=L.len;i++)
		printf("%d ",L.R[i].key);
		
	return 0;
}
