#include<stdio.h>

int main()

{
	int A,B,C;
	scanf("%d %d %d", &A, &B, &C);
	
	if(A!=C){
		if(A!=B)
		    printf("A");
		else
		    printf("C");
		    
	} else{
		printf("B");
	}
	
	return 0;
}
