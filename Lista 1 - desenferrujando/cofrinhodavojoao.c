#include <stdio.h>
#include <stdlib.h>

int main(){
    int N=0, cont = 1;
    int J, Z, result;

        scanf("%d", &N);
        
    while(N!=0){

        result = 0;
        
        printf("Teste %d\n", cont);
        cont++;

        for(int i=0; i<N; i++){
            scanf("%d %d", &J, &Z);
            result += J-Z;
            printf("%d\n", result);
        }

        printf("\n");
        scanf("%d", &N);
    }
    return 0;
}