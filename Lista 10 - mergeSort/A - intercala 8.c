#include <stdio.h>
#include <stdlib.h>
typedef int item;
#define less(a,b) (a<b)
#define exch(a,b) {item tt=a; \
                   a = b; \
                   b = tt }

void merge(item *v, int l, int m, int r){
    int ia = l, ib = m+1;
    item *aux = malloc(sizeof(item)*(r-l+1));
    int iaux=0;

    while (ia<=m && ib<= r){
        if (less(v[ib], v[ia])){
            aux[iaux++] = v[ib++];
        }
        else{
            aux[iaux++] = v[ia++];
        }
    }
    while (ia<m){
        aux[iaux++] = v[ia++];
    }
    while(ib<=r){
        aux[iaux++] = v[ib++];
    }
    for(int i=0; i<r-l+1; i++){
        v[l++] = aux[i];
    }
}

int main(){
    int vetor1[10] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
    for(int i=0; i<10; i++)
        printf("%d ", vetor1[i]);
    
    printf("\n");

    merge(vetor1, 0, 5, 50);

    for(int i=0; i<10; i++){
        printf("%d ", vetor1[i]);
    }
}