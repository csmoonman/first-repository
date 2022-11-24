#include<stdio.h>

int main()
{
	double sum=152;
	double a,b,c,d,e;
	scanf("%lf %lf %lf %lf %lf", &a,&b,&c,&d,&e);
	printf("使用不方便：%.1f \n查询速度慢：%.1f\n某些功能要改进：%.1f\n维护响应太慢：%.1f\n其他：%.1f\n",100.0*a/sum,100.0*b/sum,100.0*c/sum,100.0*d/sum,100.0*e/sum);
	return 0;	
}
