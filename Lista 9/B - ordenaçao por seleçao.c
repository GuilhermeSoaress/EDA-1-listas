    #include <stdio.h>
    typedef int item;
    #define key(a) (a)
    #define less(a, b) (key(a)<key(b))
    #define exch(a, b) item tt=a; \
                            a = b; \
                            b = tt

void selectionSort(item *v, int l, int r){
    for (int i=l; i<r; i++){
        int min = i;
        for (int j=i+1; j<=r; j++){
            if (less(v[j],v[min])){
                min = j;
            }
        }
        exch(v[i], v[min]);
    }
}


int main(){
    int vetor[1000];
    int i=0;

    while (scanf("%d", &vetor[i]) != EOF){
        i++;
    }

    selectionSort(vetor, 0, i-1);
    
    for (int j=0; j<i-1; j++){
        printf("%d ", vetor[j]);
    }
    printf("%d\n", vetor[i-1]);
}