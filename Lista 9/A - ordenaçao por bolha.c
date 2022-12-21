#include <stdio.h>
typedef int item;
#define key(a) (a)
#define less(a, b) (key(a)<key(b))
#define exch(a, b) item tt=a; \
                        a = b; \
                        b = tt

void bubblesort(item *v, int l, int r){
    for (int i=l; i<r; i++){
        for (int j=l; j<r; j++){
            if (less(v[j+1], v[j])){
                exch(v[j+1], v[j]);
            }
        }
    }
}

int main(){
    int vetor[1000];
    int i=0;

    while (scanf("%d", &vetor[i]) != EOF){
        i++;
    }

    bubblesort(vetor, 0, i-1);
    
    for (int j=0; j<i-1; j++){
        printf("%d ", vetor[j]);
    }
    printf("%d\n", vetor[i-1]);
}