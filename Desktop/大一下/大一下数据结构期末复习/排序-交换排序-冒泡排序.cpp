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

void BubbleSort(SqList &L)
{
	int flag=1;
	int m=L.len-1;
	while(flag==1&&m>0)
	{
		flag=0;
		int i;
		for(i=1;i<=m;i++)
			if(L.R[i].key>L.R[i+1].key)
			{
				flag=1;
				Elemtype t=L.R[i];
				L.R[i]=L.R[i+1];
				L.R[i+1]=t; 
			}
		m--;
	}
}

int main()
{
	SqList L;
	L.len=0;
	L.R=(Elemtype*)malloc(sizeof(Elemtype)*MAXSIZE);
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
	BubbleSort(L);
	
	printf("�ź�\n");
	for(i=1;i<=L.len;i++)
		printf("%d ",L.R[i].key);
		
	return 0;
}
