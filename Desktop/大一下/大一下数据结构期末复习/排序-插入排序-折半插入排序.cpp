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

void BinSort(SqList &L)
{
	int i,j;
	for(i=2;i<=L.len;i++)
	{
		L.R[0]=L.R[i];
		int low=1,high=i-1,mid;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(L.R[mid].key>L.R[0].key) high=mid-1;
			else low=mid+1;
		}
		for(j=i-1;j>=high+1;j--) L.R[j+1]=L.R[j];
		L.R[high+1]=L.R[0];
	}	
}

int main()
{
	SqList L;
	L.len=0;
	L.R=(Elemtype*)malloc(sizeof(Elemtype)*m);
	int e;
	int i=1;
	printf("����������,�м��Կո���������-1����\n");
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
	
	printf("��ǰ��\n"); 
	for(i=1;i<=L.len;i++)
		printf("%d ",L.R[i].key);
	
	printf("\n"); 
	BinSort(L);
	
	printf("�ź�\n");
	for(i=1;i<=L.len;i++)
		printf("%d ",L.R[i].key);
		
	return 0;
}

