#include <stdio.h>

int main(){
    int n; 
    int j;
    int x = 0;
    int y = 0;
    scanf("%d", &n);
    int R[n];
    
    while (n > 0){

        x = 0, y = 0;

        for (int i=0; i<n; i++){
            scanf("%d", &R[i]);
            if (R[i] == 0){
                x += 1;
            }
            if (R[i] == 1){
                y += 1;
            }
        }
        printf("Alice ganhou %d e Beto ganhou %d\n", x, y);
        scanf("%d", &n);
    }
}