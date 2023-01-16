#include <stdio.h>

int main(){
    int n, j, z, teste = 1, dif;
    scanf("%d", &n); // usuario escolhe n depósitos

    while(n > 0){

        dif = 0;

        if (n < 0 || n > 100){
            return 0;
        }       

        printf("Teste %d\n", teste);
        teste++;

        for (int i=0; i<n; i++){       //usuário coloca os valores do depósito do cofrinho de j e z e printa a diferença
            scanf("%d %d", &j, &z);
            if (j <0 || j > 100 || z < 0 || z > 100){
                return 0;
            }         
            dif += j - z;
            printf("%d\n", dif);
        }
        printf("\n");
        scanf("%d", &n);        //escolhe novamente o n de depositos
    }
    return 0;
}