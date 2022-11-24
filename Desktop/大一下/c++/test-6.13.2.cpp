void Sift(int R[],int low,int high)
{
    int i=low,j=2*i; 
    int temp=R[i];
    while (j<=high) 
    {    
      if (j<high && R[j]<R[j+1])
        j++; 
        if (temp<R[j]) 
        {    
            R[i]=R[j];
            i=j;   
            j=
2*i
;
        }
        else break;                         
    }
    R[i]=
temp
;                              
}

void HeapSort(int R[],int n)    
{
    int i,j;
    int temp;
    for (i=
n
;i>=1;i--)      
       Sift(R,i,n); 
    for (i=n;i>=2;i--)       
    {      
       swap(R[1],R[i]);  //将R[1]与R[i]进行交换。
           
Sift(R,i,n)
; 
    }
}
