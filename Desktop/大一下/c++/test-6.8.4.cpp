#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
void InitStrack(LinkList &LS) {
	LS->next = NULL;
}
int StackEmpty(LinkList LS) {
	if (LS->next == NULL)
		return 1;
	return 0;

}
void push(LinkList &LS, ElemType e) {
	LinkList s= (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = LS;
	LS = s;
}
void pop(LinkList &LS, ElemType &e) {
	if (LS->next == NULL)
		return;
	e = LS->data;
	LinkList s = LS; LS = LS->next;
	free(s);

}
void GetElem(LinkList LS, ElemType e) {
	if (LS->next == NULL)
		return;
	e = LS->data;
	
}
int main()
{
	LinkList Sq;
	InitStrack(Sq);
	int m,n,r;
	printf("换算进制\n");
	printf("将10换至：\n");
	scanf("%d", &n);
	printf("输入十进制数:\n"); 
	scanf("%d", &m);
	
	r=m%n;
	while(m!=0)
	{
		m/=n;
		push(Sq,r);
		r=m%n;
	}
	while(!StackEmpty(Sq))
	{
		int e;
		pop(Sq,e);
		printf("%d",e);
	}	

	return 0;
}
