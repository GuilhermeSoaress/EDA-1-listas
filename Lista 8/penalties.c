#include <stdio.h>

int main(){
    int n, golsa=0, golsb=0, rodadas=0;
    scanf("%d", &n);
    char ptsa[n+1], ptsb[n+1];
    int penaltBatidosA=n, penaltBatidosB=n;
    scanf("%s %s", ptsa, ptsb);

    for (int i=0; i<n; i++){
        if (ptsa[i] == 'o'){
            golsa++;
        }
        penaltBatidosA--;
        rodadas++;
        if (golsa > golsb + penaltBatidosB || golsb > golsa + penaltBatidosA){
            break;
        } 

        if (ptsb[i] == 'o'){
            golsb++;
        }
        penaltBatidosB--;
        rodadas++;
        if (golsa > golsb + penaltBatidosB || golsb > golsa + penaltBatidosA){
            break;
        }
    }

    if (golsa == golsb){
        printf("Empate\n");
    } else{
        printf("%d\n", rodadas);
    }
}