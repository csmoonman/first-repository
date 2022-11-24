#include<stdio.h>


int main()
{
	int i,j,n;//—≠ª∑±‰¡ø
	long fac,sum=0; 
	for(i=1;i<=10;i++)
	{
		fac=1;
		for(n=1;n<=i;n++)
		{
			fac=fac*n;
		}
		sum=sum+fac;
	}
	printf("%ld", sum);
	return 0;
}


