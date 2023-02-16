#include <stdio.h>

int buscaBinaria(int *v, int l, int r, int b){
    
    int meio = (r+l)/2;
    if (v[meio] == b)
        printf("%d", meio);
    
    else if (v[meio] > b){
        r = meio;
        return buscaBinaria(v, l, r, b);
    }

    else if (v[meio] < b){
        l = meio;
        return buscaBinaria(v, l, r, b);
    }
    else{
        printf("valor nao existe no vetor");
    }
}

int main(){
    int b;
    scanf("%d", &b);
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    buscaBinaria(vetor, 0, 9, b);
}