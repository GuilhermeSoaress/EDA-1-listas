#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOME 27

typedef struct no_st {
    char cidade[MAX_NOME];
    struct no_st *prox, *ant;
} no_st;

typedef struct Fila{
    no_st *aux;
    no_st *inicio;
    no_st *fim;
}Fila;

Fila *inicializa_fila(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if (!fila) {
        exit(1);
    }
    fila->inicio = fila->fim = NULL;
    return fila;
}

int esta_vazia(Fila *fila){
    return fila->inicio == NULL;
}

void enfila(Fila *fila, char *cidade){
    no_st *novo = (no_st*) malloc(sizeof(no_st));
    if (!novo) {
        exit(1);
    }
    strcpy(novo->cidade, cidade);
    novo->prox = NULL;
    novo->ant = fila->fim;
    if (esta_vazia(fila)){
        fila->inicio = fila->fim = novo;
    }else{
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

void desenfila(Fila *fila){
    if (!esta_vazia(fila)){ 
        no_st *temp = fila->inicio; 
        fila->inicio = fila->inicio->prox;
        if(fila->inicio) fila->inicio->ant = NULL;
        free(temp);
    }
    if (esta_vazia(fila)) {
        fila->fim = NULL;
    }
}

char *proxCidade(Fila *fila){
    if (esta_vazia(fila)) {
        return NULL;
    }
    fila->aux = fila->inicio->prox; 
    return fila->aux->cidade;
}

int main() {
    
    char cidade[MAX_NOME];

    Fila *fila = inicializa_fila();
    
    while (scanf(" %s", cidade) != EOF) {
        enfila(fila, cidade);
    }

    char *comeco = fila->inicio->cidade; 

    char lastChar = comeco[strlen(comeco) - 1];
    lastChar = toupper(lastChar);
    printf("%s\n", comeco);
    char *prox;
    while(fila->inicio != fila->fim && !esta_vazia(fila)){
        prox = proxCidade(fila);
        char firstChar = prox[0];
        if(firstChar == lastChar){
            desenfila(fila);
            enfila(fila, prox);
            //printf("%s\n", prox);
            //desenfila(fila);
        }else{
            
            desenfila(fila);
            printf("%s\n", prox);
            //printf("%s\n", prox);
            //desenfila(fila);
            //fila->inicio = fila->inicio->prox;
            lastChar = toupper(prox[strlen(prox) - 1]);
            
        }
    }
    return 0;
}