#include <stdio.h>

int main(){
    int n, golsa =0, golsb=0, penaltBatidos=0, penaltieDecisivo;
    scanf("%d", &n);
    char ptsa[n], ptsb[n];
    scanf("%s %s", ptsa, ptsb);

    for (int i=0; i<n; i++){
        if (ptsa[i] == 111){
            golsa++;
        }
        penaltBatidos++;

        if (golsa - golsb > n - penaltBatidos || golsb - golsa > n - penaltBatidos){
            penaltieDecisivo = penaltBatidos;
            break;
        } 

        if (ptsb[i] == 111){
            golsb++;
        }
        penaltBatidos++;

        printf("ptsa[i] = %d\n", ptsa[i]);
        printf("ptsb[i] = %d\n", ptsb[i]);

        
        if (golsa - golsb > n - penaltBatidos || golsb - golsa > n - penaltBatidos){
            penaltieDecisivo = penaltBatidos;
            break;
        } 
    }
    printf("gols a = %d gols b = %d\n", golsa, golsb);
    printf("%d", penaltieDecisivo);
}