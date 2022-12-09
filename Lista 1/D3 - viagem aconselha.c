#include <stdio.h>

int main(){
    int r, nota, codigo, dia = 1, maiorNota, restauranteEscolhido;

    while (scanf("%d", &r) != EOF){
        scanf("%d %d", &restauranteEscolhido, &maiorNota);
        for (int i = 1; i <r; i++){

            scanf("%d %d", &codigo, &nota);
            if (nota>maiorNota ||
            (nota == maiorNota && codigo <restauranteEscolhido)){
                maiorNota = nota;
                restauranteEscolhido = codigo;
            }
          /*  if (nota > maiorNota){
                maiorNota = nota;
                restauranteEscolhido = codigo;
            }
            if (codigo < menorCodigo){
                menorCodigo = codigo; 
            }
            if (nota == maiorNota){
                restauranteEscolhido = menorCodigo;
            }
        }
        maiorNota=-1, menorCodigo=10000001; assim que eu tava fazendo */
        }
    printf("Dia %d\n%d\n\n", dia, restauranteEscolhido);
    dia++;;
    }
    return 0;
}