#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef struct
{
	char name[20];
	double price;
}Book;

typedef struct 
{
	Book *Elem;
	int lenth;
}List;

void InitList(List &L)
{
	L.Elem=(Book*)malloc(sizeof(Book)*MaxSize);
	L.lenth=0;
	if(!L.Elem)
		return;

	L.lenth=0;
}

void createList(List &L)
{
	int n;
	int i=0;
	printf("几本书要入库？\n");
	scanf("%d",&n);
	printf("输入格式:名称 价格\n");
	getchar();
	for(i;i<n;i++)
	{
		scanf("%s %lf",L.Elem[i].name,&L.Elem[i].price);
		getchar();
		L.lenth++;
	} 
}

void printList(List L)
{
	for(int i=0;i<L.lenth;i++)
		printf("%s\n",L.Elem[i].name);
}

int main()
{
	List L;
	InitList(L);
	createList(L);
	printList(L);
	
	return 0;
}
