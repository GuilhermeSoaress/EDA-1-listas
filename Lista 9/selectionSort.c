#include <stdio.h>
#include <stdlib.h>

void selection_sort(int lista[], int tamanho) {
  for (int i = 0; i < tamanho - 1; i++) {
    int menor_indice = i;
    for (int j = i + 1; j < tamanho; j++) {
      if (lista[j] < lista[menor_indice]) {
        menor_indice = j;
      }
    }
    int temp = lista[i];
    lista[i] = lista[menor_indice];
    lista[menor_indice] = temp;
  }
}

int main() {
  int lista[1000];
   int i=0;

    while (scanf("%d", &lista[i]) != EOF){
        i++;
    }
  int tamanho = sizeof(lista) / sizeof(lista[0]);

  selection_sort(lista, tamanho);

  for (int i = 0; i < tamanho; i++) {
    printf("%d ", lista[i]);
  }
  return 0;
}
