#include <stdio.h>
#include <malloc.h>
typedef int Status;
typedef char SElemType;
#define stack_INIT_SIZE     100
#define stackINCREMENT  10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 typedef struct {
       SElemType  *base;   //ջ��ָ��
       SElemType  *top;     //ջ��ָ��
       int stacksize;       //ջ�ռ�
}Sqstack;

Status iniStack(Sqstack &S) //��ʼ��ջ
{
 
  S.base=(SElemType *)malloc(stack_INIT_SIZE*sizeof(SElemType));
	S.top=S.base;
  S.stacksize=stack_INIT_SIZE;
  
  return OK;
  }//InitStack

Status push(Sqstack &S,SElemType x)
{
	
	if((S.top-S.base)>=S.stacksize)
	{
		S.base=(char *)realloc(S.base,(stackINCREMENT+S.stacksize)*sizeof(char));
		S.top=S.base+S.stacksize;
		S.stacksize=S.stacksize+stackINCREMENT;
	}
	
	*S.top++=x;
    
    return OK;
}

Status pop(Sqstack &S,SElemType &e)
{
	if(S.base==S.top)
		return ERROR;
    e=*(--S.top);
    
 
    return OK;
}

Status print_stack(Sqstack S)//��ӡջ��Ԫ��
{
    SElemType  *p=S.base;
    while(p<S.top)
    {
        printf("%c ",*p);
        p++;
    }
   return OK;
}
int main()
{
    Sqstack S;
    SElemType k;
    int n,i;
    iniStack(S);
    SElemType e;
    scanf("%c",&e);
    while(e!='0')    //����������ջԪ�أ�ֱ���ַ���0��weizhi 
       { if(push(S,e)==ERROR)
           printf("��ջʧ�ܣ�\n");
         scanf("%c",&e);
       }
    scanf("%d",&n);  //�����ջ����
    for(i=1;i<=n;i++)
     if(pop(S,k)==ERROR)
         printf("��ջʧ�ܣ�\n");
     else
        printf("��ջԪ��Ϊ��%c\n",k);
     print_stack(S);  //��ӡ��ջ��ջ��Ԫ��
    return 0;
}



