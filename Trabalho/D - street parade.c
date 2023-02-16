#include <stdio.h>
#define MAX 1001

void empilha(int *pilha, int valor, int *topo){
    pilha[++(*topo)] = valor;
}

void manipula(int *vetor, int n){

    int pilha[MAX], topo = -1, i, move = 0;

    for(i = 0; i < n; i++){
        while(topo != -1 && pilha[topo] == move + 1){
            topo--;
            move++;
        }

        if(vetor[i] == move + 1) 
            move++;
       
        else if(topo != -1 && vetor[i] > pilha[topo]){
            printf("no\n");
            return;
        }
       
        else {
            empilha(pilha, vetor[i], &topo);
        }
    }
    printf("yes\n");
}

int main(){    
    int vetor[MAX], n, i;

    while(scanf("%d", &n) && n != 0){
        for(i = 0; i < n; i++)
            scanf("%d", &vetor[i]);
            manipula(vetor, n);
        }
}