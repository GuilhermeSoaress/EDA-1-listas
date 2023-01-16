#include <stdio.h>
typedef int item;
#define less(a,b) (a<b)
#define exch(a,b) {item tt=a; \
                   a = b; \
                   b = tt; }

int separa(item *v, int l, int r){
    item p = v[r];
    int i=l-1, j=r;
    for(; ;){
        while (less(v[++i], p));
        while (less(p, v[--j])) if (j==l) break;
        if (i>=j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quickSort(item *v, int l, int r){
    if (l>=r) return;
    int j = separa(v, l, r);
    quickSort(v, l, j-1);
    quickSort(v, j+1, r);
}

int main(){
    int vetor[1000] = {7, 3, 5, 2, 66, 3, 24, 6, 235, 5, 2, 3, 7, 8, 9, 7,5 , 4};
    int i=0;

    while (scanf("%d", &vetor[i]) != EOF){
        i++;
    }

    quickSort(vetor, 0, i-1);
    
    for (int j=0; j<i-1; j++){
        printf("%d ", vetor[j]);
    }
    printf("%d\n", vetor[i-1]);
}