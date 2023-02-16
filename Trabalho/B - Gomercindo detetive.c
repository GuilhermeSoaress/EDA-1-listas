#include <stdio.h>
#define MAX 5001

int main() {
int n, i, idAtual;
int id[MAX];
int valor[MAX];
int prox[MAX];
scanf("%d", &n);
for (i = 0; i < n; i++) {
    scanf("%d%d%d", &id[i], &valor[i], &prox[i]);
}

idAtual = id[0];
while (idAtual != -1) {
    for (i = 0; i < n; i++) {
        if (id[i] == idAtual) {
            printf("%d\n", valor[i]);
            idAtual = prox[i];
            break;
        }
    }
}

return 0;
}