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
		k=i;//������¼i�Ժ����Сֵ�±� 
		for(j=i+1;j<=L.len;j++)
			if(L.R[j].key<L.R[k].key) k=j;
		if(k!=i)//���i������ڱ�L.R[i].keyС��ֵ������λ�� 
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
	SelectSort(L);
	
	printf("�ź�\n");
	for(i=1;i<=L.len;i++)
		printf("%d ",L.R[i].key);
		
	return 0;
}
