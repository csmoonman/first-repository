#include<stdio.h>
int main()
{
	int a[10],i,n,m;
	printf("������ʮλѧ���ĳɼ�:");
	for(i=0;i<10;i++)
		scanf("%d", &a[i]);
		
	printf("����ǰ:");
	
	for(i=0;i<10;i++)
		printf("%5d",a[i]);
	
    for(n=1;n<10;n++)
    {
    	for(i=0;i<10-n;i++)
    	{
    		if(a[i]>a[i+1])
    		{
    			m=a[i];
    			a[i]=a[i+1];
    			a[i+1]=m;
			}
		}
	}
	
	printf("\n������˳��:");
	for(i=0;i<10;i++)
	{
		printf("%5d",a[i]);
	}
	
	return 0;
}
