#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    int J;
    int Z;
    int cont=1;
    int result;

    scanf("%d", &N);
    while(N!=0){

        result = 0;

        if(N<0 || N>100){
            printf("erro\n");
            return 0;
        }
        printf("Teste %d\n", cont);
        cont++;
        for (int i=0; i<N; i++){
            scanf("%d %d", &J, &Z);
            if(J<0 || J>100){
                printf("erro\n");
                return 0;
            }
            if(Z<0 || Z>100){
                printf("erro\n");
                return 0;
            }
            result += J-Z;
            printf("%d\n", result);
        }
        printf("\n");
        scanf("%d", &N);
    }
    return 0;
}