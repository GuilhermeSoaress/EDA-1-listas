#include <stdio.h>
typedef int item;
#define less(a,b) (a<b)
#define cmpexch(A,B) {if(less(B,A)) exch(A,B)}
#define exch(a,b) {item tt=a; \
                   a = b; \
                   b = tt; }

int separa(item *v, int l, int r){
    item p = v[r];
    int i=l-1, j=r;
    for( ; ; ){
        while (less(v[++i], p));
        while (less(p, v[--j])) if (j==l) break;
        if (i>=j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quickSort(item *v, int l, int r){
    if(l>=r) return;

    cmpexch(v[(l+r)/2],v[r]);
    cmpexch(v[l],v[(l+r)/2]);
    cmpexch(v[r],v[(l+r)/2]);

    int j = separa(v, l, r);
    quickSort(v, l, j-1);
    quickSort(v, j+1, r);

}

int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];

    for(int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }

    quickSort(vetor, 0, n-1);
    
    for (int j=0; j<n-1; j++){
        printf("%d ", vetor[j]);
    }
    printf("%d\n", vetor[n-1]);
}