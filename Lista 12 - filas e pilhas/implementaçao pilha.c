#include <stdio.h>

struct Elemento {
    int valor;
    struct Elemento* prox;
};

struct Elemento* topo = NULL;

void empilha(int x) {
    struct Elemento* novo = (struct Elemento*) malloc(sizeof(struct Elemento));
    novo->valor = x;
    novo->prox = topo;
    topo = novo;
}

int desempilha() {
    if (topo == NULL) {
        printf("Pilha vazia\n");
    return -1;
    }
    struct Elemento* temp = topo;
    int valor = temp->valor;
    topo = topo->prox;
    free(temp);
    return valor;
}

int espia() {
  if (topo == NULL) {
    return -1;
  }
  return topo->valor;
}

int main() {
    empilha(1);
    empilha(2);
    empilha(3);
    desempilha();
    desempilha();
    desempilha();
    printf("%d", espia());
    return 0;
}