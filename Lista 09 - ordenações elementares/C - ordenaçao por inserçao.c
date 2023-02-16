#include <stdio.h>
typedef int item;
#define key(a) (a)
#define less(a, b) (key(a)<key(b))
#define exch(a, b) {item tt=a; \
                        a = b; \
                        b = tt; \
                        }
#define cmpexch(a,b) {if (less(b,a)) exch(a,b)}

void insercionSort(item *v, int l, int r){
    for (int i=r; i>l; i--){
        cmpexch(v[i-1], v[i]);
    }

    for (int i=l+2; i<=r; i++){
        item m=v[i];
        int j=i;
        while (less(m, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j]=m;
    }
}

int main(){
    int vetor[50000];
    int i=0;

    while (scanf("%d", &vetor[i]) != EOF){
        i++;
    }

    insercionSort(vetor, 0, i-1);
    
    for (int j=0; j<i-1; j++){
        printf("%d ", vetor[j]);
    }
    printf("%d\n", vetor[i-1]);
}