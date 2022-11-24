#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define OK 1;
#define ERROR -2;

typedef struct
{
	char name[10];
	char tel[11];
	char QQ[12];
}Book;

typedef struct
{
	Book *mem;
	int length;
}Sqlist;

int init(Sqlist &L)
{
	L.mem=(Book*)malloc(1*sizeof(Book));
	if(!L.mem)
		return ERROR;
	
	L.length=0;
	
	return 0;
}

void input(Sqlist &L)
{
	strcpy(L.mem[0].name,"∏ﬂÓ⁄¿§");
	//strcpy(L.mem[0].QQ,"1243556946");
	strcpy(L.mem[0].tel,"18202866587");
	strcpy(L.mem[0].QQ,"1243556946");
	L.length=1;
}

int main()
{
	Sqlist mylist;
	//≥ı ºªØinit:
	init(mylist);
	//input:
	input(mylist); 
	//output:
	printf("%s  %s  %s\n", 
		mylist.mem[0].name, mylist.mem[0].QQ, mylist.mem[0].tel);
	free(mylist.mem);
	
	system("pause");
	
	return 0;
}
