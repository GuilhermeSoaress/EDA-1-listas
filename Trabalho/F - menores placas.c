#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define key(a) (a)
#define less(a, b) (key(a)<key(b))
#define lesseq(a, b) (key(a)<=key(b))
#define exch(a, b) item tt=a; \
                        a = b; \
                        b = tt

#define MAX 100

void merge(Item *V, int l, int m, int r){
  
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

void mergesort(Item *V,int l, int r){
  
  if (l>= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}

int main(){

    int op, num, t;
    int placas[MAX];
    int cont = 0;

    while (scanf("%d", &op) != EOF){

      if (op == 1) {
          scanf("%d", &num);

          if (cont <100){
            placas[cont++] = num;
            mergesort(placas, 0, cont - 1);
          }
          
          else if (cont >= 100) {
            if (num < placas[99]){
              placas[99] = num;
              mergesort(placas, 0, cont - 1);
              }
            cont = 100;
          }
      }
      else if (op == 2) {
          scanf("%d", &t);

          for (int i = 0; i < t-1; i++) {
              printf("%d ", placas[i]);
          }
          printf("%d\n", placas[t-1]);
        }
    }
    return 0;
}
