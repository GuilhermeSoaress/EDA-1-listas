#include<stdio.h>
typedef int Item;
#define eq(A,B) (A==B)

int search(Item *v,int l,int r,int x){
    int p=-1;
    for(int i=l; i<r;i++){
        if(eq(x,v[i])){
            p=i;
        }
    }
    return printf("%d\n",p);
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int vetor[n];
    int number[m];
    for(int i=0; i<n;i++){
        scanf("%d",&vetor[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&number[i]);
    }
    for(int i=0;i<m;i++){
        search(vetor,0,n,number[i]);
    }
}