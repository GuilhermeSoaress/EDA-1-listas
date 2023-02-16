#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int n, m, x, y, i, j, k, l, cont;
char mat[MAX][MAX];

void preencherMatriz() {
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf(" %c", &mat[i][j]);
    }
  }
}

int contarTs() {
  int t = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (mat[i][j] == 't') {
        t++;
      }
    }
  }
  return t;
}

void marcarPontos(int t) {
  int raio;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (mat[i][j] == 't') {
        scanf("%d", &raio);
        for (k = i - raio; k <= i + raio; k++) {
          for (l = j - raio; l <= j + raio; l++) {
            if (k >= 0 && k < n && l >= 0 && l < m) {
              if (mat[k][l] == '#') {
                mat[k][l] = '.';
                cont++;
              }
            }
          }
        }
      }
    }
  }
}

void imprimirMatriz() {
  printf("%d\n", cont);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%c", mat[i][j]);
    }
    printf("\n");
  }
}

int main() {
  scanf("%d %d", &n, &m);

  preencherMatriz();
  int t = contarTs();
  marcarPontos(t);
  imprimirMatriz();

  return 0;
}
