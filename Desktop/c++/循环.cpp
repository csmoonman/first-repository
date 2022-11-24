#include<stdio.h>

int main()

{
	int x;
	int n=1;
	
	scanf("%d", &x);
	x /= 10;
	while(x>0){
		x /= 10;
		n++;
	}
	printf("%d",n);
	
	return 0;
}
