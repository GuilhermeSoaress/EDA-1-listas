#include <stdio.h>

int main(){
    int n, gola=0, golb=0, pBatidos=0;
    scanf("%d", &n);
    char pta[n], ptb[n];
    scanf("%s %s", pta, ptb);

    for (int i=0; i<n; i++){
        if (pta[i] == 111){
            gola++;
        }
        if (ptb[i] == 111){
            golb++;
        }
    }

    printf("gola: %d\ngolb: %d", gola, golb);
}