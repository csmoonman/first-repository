#include<stdio.h>
int main()
{
        int year,month,day,sex;
        printf("�������������֤�ţ�");
        scanf("%*6d%4d%2d%2d%*2d%1d%*1d",&year,&month,&day,&sex);
        printf("���������ǣ�%d��%d��%d��;",year,month,day);
        if(sex%2==1)printf("�����Ա��ǣ�����\n");
        else printf("�����Ա��ǣ�Ů��\n");
        return 0;
}
