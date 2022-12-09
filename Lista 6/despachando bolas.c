#include <stdio.h>

int main(){
    int diametro, altura, largura, profundidade;
    scanf ("%d %d %d %d", &diametro, &altura, &largura, &profundidade);

    if (altura < diametro || largura < diametro || profundidade < diametro){
        printf("N");
    }
    else {
        printf("S");
    }
}