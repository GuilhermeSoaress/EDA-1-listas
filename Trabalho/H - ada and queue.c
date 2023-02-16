#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_st {
    struct no_st* anterior;
    int valor;
    struct no_st* prox;
} no_st;

typedef struct fila {
    no_st* comeco;
    no_st* fim;
} fila;

no_st* cria_no(int valor) {
    struct no_st* temp = (no_st*)malloc(sizeof(no_st));
    temp->anterior = NULL;
    temp->valor = valor;
    temp->prox = NULL;
    return temp;
}

fila* cria_fila() {
    fila* fila1 = (fila*)malloc(sizeof(fila));
    fila1->comeco = NULL;
    fila1->fim = NULL;
    return fila1;
}

void toFront(fila* fila1, int valor) {
    no_st* temp = cria_no(valor);
    if (fila1->comeco == NULL) {
        fila1->comeco = temp;
        fila1->fim = temp;
        return;
    }
    temp->anterior = fila1->comeco;
    fila1->comeco->prox = temp;
    fila1->comeco = temp;
}
int taVazia(fila* fila1) {
    if (fila1->comeco == NULL && fila1->fim == NULL) {
        return 1;
    }
    return 0;
}

void push_back(fila* fila1, int valor) {
    no_st* temp = cria_no(valor);
    if (fila1->fim == NULL) {
        fila1->comeco = temp;
        fila1->fim = temp;
        return;
    }
    temp->prox = fila1->fim;
    fila1->fim->anterior = temp;
    fila1->fim = temp;
}

int back(fila* fila1) {
    if (fila1->fim == NULL) {
        return printf("No job for Ada?\n");
    }
    if(fila1->fim->prox==NULL && fila1->fim->anterior==NULL){
        int valor = fila1->fim->valor;
        fila1->comeco=NULL;
        fila1->fim=NULL;
        return printf("%d\n", valor);
    }
    no_st* temp;
    temp = fila1->fim;
    int num = fila1->fim->valor;
    fila1->fim = fila1->fim->prox;
    temp->prox = NULL;
    if (fila1->fim == NULL) {
        return printf("%d\n", num);
    }
    fila1->fim->anterior = NULL;
    return printf("%d\n", num);
}

int front(fila* fila1) {
    if (fila1->comeco == NULL) {
        return printf("No job for Ada?\n");
    }
    if(fila1->comeco->prox==NULL && fila1->comeco->anterior==NULL){
        int valor = fila1->comeco->valor;
        fila1->comeco=NULL;
        fila1->fim=NULL;
        return printf("%d\n", valor);
    }
    no_st* temp;
    temp = fila1->comeco;
    int valor = fila1->comeco->valor;
    fila1->comeco = fila1->comeco->anterior;
    temp->anterior = NULL;
    if (fila1->comeco == NULL) {
        return printf("%d\n", valor);
    }
    fila1->comeco->prox = NULL;
    return printf("%d\n", valor);
}

int inverter = 0;

void inversa(fila* fila1) {
    if (taVazia(fila1) == -1) {
        return;
    }
    if (inverter > 0) {
        inverter = 0;
        return;
    }
    inverter = 1;
    return;
}

int main() {
    fila* adaQueue = cria_fila();
    int comandos;
    scanf("%d", &comandos);
    char resposta[100];
    int num;

    char strBack[100] = "back";
    char strPushBack[100] = "push_back";
    char strFront[100] = "front";
    char strToFront[100] = "toFront";
    char strReverse[100] = "reverse";

    for (int i = 0; i < comandos; i++) {
        scanf(" %s", resposta);
        if (strcmp(resposta, strBack) == 0) {
            switch (inverter) {
                case 1: {
                    front(adaQueue);
                    break;
                }
                case 0: {
                    back(adaQueue);
                    break;
                }
            }
        }
        if (strcmp(resposta, strPushBack) == 0) {
            scanf("%d", &num);
            switch (inverter) {
                case 1: {
                    toFront(adaQueue, num);
                    break;
                }
                case 0: {
                    push_back(adaQueue, num);
                    break;
                }
            }
        }
        if (strcmp(resposta, strFront) == 0) {
            switch (inverter) {
                case 1: {
                    back(adaQueue);
                    break;
                }
                case 0: {
                    front(adaQueue);
                    break;
                }
            }
        }
        if (strcmp(resposta, strToFront) == 0) {
            scanf("%d", &num);
            switch (inverter) {
                case 1: {
                    push_back(adaQueue, num);
                    break;
                }
                case 0: {
                    toFront(adaQueue, num);
                    break;
                }
            }
        }
        if (strcmp(resposta, strReverse) == 0) {
            inversa(adaQueue);
        }
    }
}