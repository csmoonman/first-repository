#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct hnode
{ int weight;
   int lchild,rchild,parent;
 }HTNode,*HuffmanTree;/*定义二叉树的存储结点*/
typedef char **HuffmanCode;
void Select(HTNode HT[],int len,int &s1,int &s2)//选出权值最小的两个结点，下标通过s1和s2传出去
{
    int i,min1=32767,min2=32767;
    for(i=1;i<=len;i++)
    {
        if(HT[i].weight<min1&&HT[i].parent==0)
        {
            s2=s1;
            min2=min1;
            min1=HT[i].weight;
            s1=i;
        }
        else if(HT[i].weight<min2&&HT[i].parent==0)
        {    min2=HT[i].weight;
            s2=i;
        }
    }
}
void CreateHuffman_tree(HuffmanTree &Ht,int n);/*建立哈夫曼树*/
void Huffman_code(HuffmanTree HT,HuffmanCode &HC,int n);/*哈夫曼树编码*/

int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int i, n;
    scanf("%d",&n);
    CreateHuffman_tree(HT, n);/*建立哈夫曼树*/
    Huffman_code(HT,HC,n);/*哈夫曼树编码*/
    for(i=1;i<=n;i++)/*输出字符、权值及编码*/
       printf("编码是：%s\n",HC[i]);
    return 0;
}


/* 请在这里填写答案 */
void CreateHuffman_tree(HuffmanTree &HT,int n)
{
	//循环变量 
	int i;
	// 函数时void类型 ，返回空值
	//printf("测试点2\n");
	if(n<=1)
		return;
	//m是HuffmanTree结点总数
	int m=2*n-1;
	//分配内存，我这里第0号单元没存东西，申请n+1个单元
	//printf("测试点3\n");
	HT=new HTNode[m+1];
		if(!HT)
			return; 
	//初始化HuffmanTree的所有结点 
	//printf("测试点4\n");
	for(i=1;i<=m;i++)
	{
		HT[i].parent=0;
		HT[i].rchild=0;
		HT[i].lchild=0; 
	}
	//将叶节点赋值 
	//printf("测试点5\n");
	for(i=1;i<=n;i++)
	{
		//printf("请输入第%d个元素的权重：",i);
		scanf("%d", &HT[i].weight); 
	}
	//逐步构造树结构 
	//printf("测试点6\n");
	for(i=n+1;i<=m;i++)
	{
		int s1,s2;
		//从各个树中，包括新生成的，找出权重最小的两个数，并且其父值为0 
		//注意s1、s2为下标值 
		//printf("测试点7\n");
		Select(HT,i-1,s1,s2);
		//printf("测试点9\n");
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	//printf("测试点10\n");
}

void Huffman_code(HuffmanTree HT,HuffmanCode &HC,int n)
{
    HC=new char*[n+1];//第零号不用
	int start;
	int c,f;
	char cd[n] ;//临时存放每一个叶结点的HuffmanCode 
	cd[n-1]='\0'; 
	for(int i=1;i<=n;i++)
	{
		start=n-1;
		c=i;
		f=HT[i].parent;
		//从叶结点开始一直到根结点 
		while(f!=0)//当不是根结点时 
		{
			start--; 
			if(HT[f].lchild==c)
				cd[start]='0';
			else 
				cd[start]='1';
			c=f;
			f=HT[f].parent;
		}
		HC[i]=new char[n-start];
		strcpy(HC[i],&cd[start]);//注意要从cd[start]开始传 
	}
}
