#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int key;
}ElemType;

typedef struct
{
	ElemType *R;
	int length;
}SSTable;

int SeachBin(SSTable R,int key);

int main()
{
	int i,key; 
	SSTable R;
	int index;
	R.R=(ElemType*)malloc(sizeof(ElemType)*12);
	for(i=1;i<10;i++)
		R.R[i].key=i;
		
	R.length=i;
	scanf("%d",&key);
	index =	SeachBin(R,key);
	if(index<0)
		printf("未找到\n");
	else
		printf("在第%d位置",index);
	return 0;
}

int SeachBin(SSTable R,int key)
{
	int low,high,mid;
	low=1;
	high=R.length;

	while(low<=high)
	{
		mid=(high+mid)/2;
		if(R.R[mid].key==key)
			return mid;
		else if(key<R.R[mid].key)
			high=mid-1;
		else
			low=mid+1;
	}
	
	return -1;
}
