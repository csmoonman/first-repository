#include<stdio.h>

int main()
{
	char ch;
	int cnt=0,cntQ=0,cntH=0;
	scanf("%c", &ch);
	while(1)
	{
		if(ch=='!')
			cntH++;
		else if(ch=='?')
			cntQ++;
		else if(ch=='\n')
			break;
		else 
			cnt++;
		
		scanf("%c",&ch);
	}
	
	printf("cnt? = %d, cnt! = %d, cnt = %d\n",cntQ,cntH,cnt);
	
	return 0;
}
