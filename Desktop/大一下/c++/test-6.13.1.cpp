#include<iostream>
using namespace std;

#define m 16 
#define NULLKEY 0 

struct HashTable{
   int  key;
};

void CreateHash(HashTable HT[],int key){
  int H0=key%13;
  int Hi;
  if (
HT[H0].key==0 
) {
    HT[H0].key=key; 
    return;
  }
  else{             
     for(int i=1;i<m;++i){                
    
Hi=(H0+i)%m
;
        if (
HT[Hi].key==0
) {
            HT[Hi].key=key; 
            return;
        }
     }
  }
}

int main()
{    int key;
    int result;
    int i,j,n;
    HashTable HT[m];
    for(i=0;i<m;i++)
     HT[i].key=0;
    cin >> n;
    if(n>m) return 0;
    for(j=1;j<=n;j++){
        cin >> key;
        CreateHash(HT,key);
    }
    for(i=0;i<m;i++)
        cout << HT[i].key << " ";
    return 0;
}
