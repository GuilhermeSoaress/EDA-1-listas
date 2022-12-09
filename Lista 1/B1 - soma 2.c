#include <stdio.h>

int main(){
    int n1;
    int n2;
    int soma;
    
    scanf("%d%d", &n1, &n2);

    if (n1 < 0 || n1 > 600000 || n2 < 0 || n2 > 600000){
        printf("erro");
    }
    else{
    soma = n1 + n2;
    printf("%d\n", soma);
    }
}