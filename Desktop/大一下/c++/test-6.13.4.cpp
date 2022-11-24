#define MAXSIZE 50     // MAXSIZE为最大数据元素数目
typedef int ElemType;
typedef  struct
{  ElemType  r[MAXSIZE +1];    // r[0]闲置或另作它用
   int  length;
}SqList;

int main ()
{  SqList L;  int low,high;
   create(L);
   low=1; high=L.length;
   QuickSort(L,low,high);
   print(L);
   return 0;
}

void QuickSort(SqList &L, int low, int high)
{  
    int i;
    if (low<high )
    {  
        i=Partition(L,low , high );
        QuickSort(L, low, i-1);
        QuickSort(L,i+1 ,high );
    }
}

