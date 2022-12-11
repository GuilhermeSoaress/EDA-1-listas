#include <stdio.h>

int main(){
    int n, golsa =0, golsb=0, penaltBatidos=0;
    scanf("%d", &n);
    char ptsa[n], ptsb[n];
    scanf("%s %s", ptsa, ptsb);

    for (int i=0; i<n; i++){
        if (ptsa[i] == 111){
            golsa++;
        }
        penaltBatidos++;
        if (golsa - golsb > 2*n - penaltBatidos || golsb - golsa > n *2 - penaltBatidos){
            break;
        } 

        if (ptsb[i] == 111){
            golsb++;
        }
        penaltBatidos++;
        if (golsa - golsb > 2*n - penaltBatidos || golsb - golsa > n *2 - penaltBatidos-1){
            break;
        } 
    }
    printf("%d", penaltBatidos);
}