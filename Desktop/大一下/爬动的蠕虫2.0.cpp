#include<stdio.h>

int main()
{
	int n,u,d;

	scanf("%d %d %d", &n, &u, &d);
	
	int s;
	int t;
	for(t = 0;s<n; t++)
	{
		if(t%2==0)
		{
			s += u;
		}
		else
		{
			s -= d;
		}
	}
	printf("%d",t);
	
	return 0;
}
