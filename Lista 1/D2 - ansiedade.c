#include <stdio.h>
#include <string.h>

int main(){
    char str[3];
    int triagem = 0, i = 1, rodada = 0;

    while (scanf("%s", str) != EOF){
        
        if (strcmp(str, "sim") == 0){
            triagem++;
        }

        if (i == 10){
            i = 0; 
            rodada++;
        }

        if (i<=10){

        }

        i++;
    }
    if (triagem>=2){
        printf("%d", triagem);
    } else{
        printf("0");
    }
}