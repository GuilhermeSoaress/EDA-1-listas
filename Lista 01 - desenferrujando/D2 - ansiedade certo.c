#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char str[4];
    int qtd=0, cont=0, triagem=0, i=0;

    while(scanf("%s", str) != EOF){
        qtd++;
        if(strcmp(str, "sim") == 0){
            cont++;   
        }
        if(cont == 2 && i == 0){
            triagem++;
            i++;
        }
        if(qtd == 10){
            cont = 0;
            qtd = 0;
            i = 0;
        }
    }
    printf("%d\n", triagem);
}