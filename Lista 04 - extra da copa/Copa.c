#include <stdio.h>

int main(){
    int T, N, somapts =0, empates, pts, totalpts;
    char nomeTime[10];
    scanf("%d %d", &T, &N);
    
    while (T > 0){
        
        for (int i=0; i<T; i++){
            scanf("%s", nomeTime);
            scanf("%d", &pts);
            somapts += pts;
        }
        totalpts = 3 * N;
        empates = totalpts - somapts;
        printf("%d\n", empates);
        somapts = 0;
        scanf("%d %d", &T, &N);

    }
}