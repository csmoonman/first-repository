#include<stdio.h>

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a!=b){
		if(a!=c){
			printf("A");
		}else{
			printf("B");
		}
	}else{
		printf("C");
	}
	
	return 0;
}

