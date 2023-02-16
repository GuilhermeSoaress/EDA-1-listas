#include <stdio.h>
#include <string.h>

int main(){
    char str[30];
    int i = 0;
    int comparacao;
    while (scanf("%s", str) != EOF){

        comparacao = strcmp(str, "marte");
        if (comparacao == 0){
            i++;
        }
    }
    if (i>0){
        printf("Leonardo Cicero Marciano\n");
    }
    else{
        printf("none\n");
    }
}