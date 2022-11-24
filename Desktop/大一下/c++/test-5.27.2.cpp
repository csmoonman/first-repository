#include<stdio.h>
#include<math.h>

int main()
{
 int m,n;
 scanf("%d %d",&m,&n);
 int r=m%n;

 while(r)
 {
  m=n;
  n=r;
  r=m%n;
 }
 
 printf("%d", n);
}
