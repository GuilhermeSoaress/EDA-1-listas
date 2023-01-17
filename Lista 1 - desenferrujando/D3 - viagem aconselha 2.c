#include <stdio.h>

int main(){
    int dia = 1, codigo, nota, r, maiorNota, restauranteEscolhido;

    while(scanf ("%d", &r) != EOF){
        scanf("%d %d", &restauranteEscolhido, &maiorNota);
        for(int i = 1; i < r; i++)
        {
            scanf("%d %d", &codigo, &nota);
            if(nota > maiorNota ||
            (nota == maiorNota && codigo < restauranteEscolhido)) 
            {
                maiorNota = nota;
                restauranteEscolhido = codigo;
            }
        }
        printf("Dia %d\n%d\n\n", dia, restauranteEscolhido);
        dia++;
    }
    return 0;
}