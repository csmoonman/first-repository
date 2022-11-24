#include<stdio.h>
int main()
{
        int year,month,day,sex;
        printf("请输入您的身份证号：");
        scanf("%*6d%4d%2d%2d%*2d%1d%*1d",&year,&month,&day,&sex);
        printf("您的生日是：%d年%d月%d日;",year,month,day);
        if(sex%2==1)printf("您的性别是：男性\n");
        else printf("您的性别是：女性\n");
        return 0;
}
