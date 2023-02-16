#include <stdio.h>

int main(){
    int n, t, sum = 0;
    scanf("%d", &n);
    int ci[n];

    for (int i=0; i<n; i++){
        scanf("%d", &ci[i]);
        sum+=ci[i];
    }
    
    scanf("%d", &t);

    if (t == sum){
        printf("Acertou\n");
    } else{
        printf("Errou\n");
    }
}