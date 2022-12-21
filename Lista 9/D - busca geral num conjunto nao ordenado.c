#include <stdio.h>

int main(){
    long int n, m, qtd1=0;
    scanf("%d %d", &n, &m);
    int v[n], busca[m];
    for (int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    for (int i=0; i<m; i++){
        scanf("%d", &busca[i]);
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (v[j] == busca[i]){
                printf("%d ", j);
            } 
        }
        if (v[i]!= busca[i]){
            printf("-1");
        }
    }
}