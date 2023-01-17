#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define key(a) (a)
#define less(a, b) (key(a)<key(b))
#define lesseq(a, b) (key(a)<=key(b))

#define exch(a, b) item tt=a; \
                        a = b; \
                        b = tt

void merge(Item *V, int l, int m, int r)
{
  Item *R=malloc(sizeof(Item)*(r-l+1));
  int i=l,j=m+1,k=0;

  while(i<=m && j<=r)
  {
    if(lesseq(V[i],V[j]))
      R[k++]=V[i++];
    else
      R[k++]=V[j++];
  }

  while(i<=m)
      R[k++]=V[i++];
  while(j<=r)
      R[k++]=V[j++];


  k=0;
  for(i=l;i<=r;i++)
    V[i]=R[k++];
  free(R);
}

void mergesort(Item *V,int l, int r)
{
  if (l>= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}

int main(){
    int vetor[1000];
    int i=0;

    while (scanf("%d", &vetor[i]) != EOF){
        i++;
    }

    mergesort(vetor, 0, i-1);
    
    for (int j=0; j<i-1; j++){
        printf("%d ", vetor[j]);
    }
    printf("%d\n", vetor[i-1]);
}