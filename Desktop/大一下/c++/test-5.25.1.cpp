#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct hnode
{ int weight;
   int lchild,rchild,parent;
 }HTNode,*HuffmanTree;/*����������Ĵ洢���*/
typedef char **HuffmanCode;
void Select(HTNode HT[],int len,int &s1,int &s2)//ѡ��Ȩֵ��С��������㣬�±�ͨ��s1��s2����ȥ
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
void CreateHuffman_tree(HuffmanTree &Ht,int n);/*������������*/
void Huffman_code(HuffmanTree HT,HuffmanCode &HC,int n);/*������������*/

int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int i, n;
    scanf("%d",&n);
    CreateHuffman_tree(HT, n);/*������������*/
    Huffman_code(HT,HC,n);/*������������*/
    for(i=1;i<=n;i++)/*����ַ���Ȩֵ������*/
       printf("�����ǣ�%s\n",HC[i]);
    return 0;
}


/* ����������д�� */
void CreateHuffman_tree(HuffmanTree &HT,int n)
{
	//ѭ������ 
	int i;
	// ����ʱvoid���� �����ؿ�ֵ
	//printf("���Ե�2\n");
	if(n<=1)
		return;
	//m��HuffmanTree�������
	int m=2*n-1;
	//�����ڴ棬�������0�ŵ�Ԫû�涫��������n+1����Ԫ
	//printf("���Ե�3\n");
	HT=new HTNode[m+1];
		if(!HT)
			return; 
	//��ʼ��HuffmanTree�����н�� 
	//printf("���Ե�4\n");
	for(i=1;i<=m;i++)
	{
		HT[i].parent=0;
		HT[i].rchild=0;
		HT[i].lchild=0; 
	}
	//��Ҷ�ڵ㸳ֵ 
	//printf("���Ե�5\n");
	for(i=1;i<=n;i++)
	{
		//printf("�������%d��Ԫ�ص�Ȩ�أ�",i);
		scanf("%d", &HT[i].weight); 
	}
	//�𲽹������ṹ 
	//printf("���Ե�6\n");
	for(i=n+1;i<=m;i++)
	{
		int s1,s2;
		//�Ӹ������У����������ɵģ��ҳ�Ȩ����С���������������丸ֵΪ0 
		//ע��s1��s2Ϊ�±�ֵ 
		//printf("���Ե�7\n");
		Select(HT,i-1,s1,s2);
		//printf("���Ե�9\n");
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	//printf("���Ե�10\n");
}

void Huffman_code(HuffmanTree HT,HuffmanCode &HC,int n)
{
    HC=new char*[n+1];//����Ų���
	int start;
	int c,f;
	char cd[n] ;//��ʱ���ÿһ��Ҷ����HuffmanCode 
	cd[n-1]='\0'; 
	for(int i=1;i<=n;i++)
	{
		start=n-1;
		c=i;
		f=HT[i].parent;
		//��Ҷ��㿪ʼһֱ������� 
		while(f!=0)//�����Ǹ����ʱ 
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
		strcpy(HC[i],&cd[start]);//ע��Ҫ��cd[start]��ʼ�� 
	}
}
