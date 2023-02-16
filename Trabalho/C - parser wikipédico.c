#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000001

typedef struct pilha {
  char elementos[MAX_SIZE];
  int topo;
} Pilha;

Pilha *cria_pilha() {
  Pilha *p = (Pilha *) malloc(sizeof(Pilha));
  p->topo = -1;
  return p;
}

void empilha(Pilha *p, char elemento) {
  p->topo++;
  p->elementos[p->topo] = elemento;
}

void desempilha(Pilha *p) {
  p->topo--;
}

char topo(Pilha *p) {
  return p->elementos[p->topo];
}

int pilha_vazia(Pilha *p) {
  return p->topo == -1;
}

int main() {
  int n, i, j, cont = 0;
  char str[MAX_SIZE];
  Pilha *p = cria_pilha();

  scanf("%d", &n);

  for (i = 0; i < n+1; i++) {
    fgets(str, MAX_SIZE, stdin);
    int len = strlen(str);
    for (j = 0; j < len; j++) {
      if (str[j] == '*' || str[j] == '/' || str[j] == '_') {
        if (pilha_vazia(p) || topo(p) != str[j]) {
          empilha(p, str[j]);
        } else {
          desempilha(p);
        }
      }
    }
  }

  if (pilha_vazia(p)) {
    printf("C\n");
  } else {
    printf("E\n");
  }

  free(p);

  return 0;
}
