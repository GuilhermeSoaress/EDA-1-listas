#include <stdio.h>

int main(){
    int n;
    int result = 0;
    int j;

    scanf("%d", &n);
    int soma [n];


    if (n > 50){
        printf("erro");
    }
    else{
        for (int i = 0; i < n; i++){
            scanf("%d", &soma[i]);
            result = result + soma[i];
            j = soma[i];
        }
        if(j>5000){
            printf("erro");
        }else{
        printf("%i\n", result);
        }
    }
}