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

int partition(SqList &L,int low,int high)
{
	L.R[0]=L.R[low];
	int pivotkey=L.R[low].key;
	while(low<high)
	{
		while(low<high&&L.R[high].key>=pivotkey) high--;
		L.R[low]=L.R[high];
		while(low<high&&L.R[low].key<=pivotkey) low++;
		L.R[high]=L.R[low];
	}
	L.R[low]=L.R[0];
	
	return low;
}

void QSort(SqList &L,int low,int high)
{
	int pivotloc;
	if(low<high)
	{
		pivotloc=partition(L,low,high);
		QSort(L,low,pivotloc-1);
		QSort(L,pivotloc+1,high);
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
	QSort(L,1,L.len);
	
	printf("排后：\n");
	for(i=1;i<=L.len;i++)
		printf("%d ",L.R[i].key);
		
	return 0;
}
