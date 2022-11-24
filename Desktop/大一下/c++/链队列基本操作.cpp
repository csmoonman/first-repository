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
       SElemType  *base;   //栈底指针
       SElemType  *top;     //栈顶指针
       int stacksize;       //栈空间
}Sqstack;

Status iniStack(Sqstack &S) //初始化栈
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

Status print_stack(Sqstack S)//打印栈中元素
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
    while(e!='0')    //不断输入入栈元素，直到字符‘0’weizhi 
       { if(push(S,e)==ERROR)
           printf("入栈失败！\n");
         scanf("%c",&e);
       }
    scanf("%d",&n);  //输入出栈次数
    for(i=1;i<=n;i++)
     if(pop(S,k)==ERROR)
         printf("出栈失败！\n");
     else
        printf("出栈元素为：%c\n",k);
     print_stack(S);  //打印出栈后栈中元素
    return 0;
}



