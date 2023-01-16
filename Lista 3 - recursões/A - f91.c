#include <stdio.h>

int f91(){
    int n, m;
    scanf("%d", &n);

    while (n!= 0){
        if (n > 100){
            m = n - 10;
            printf("f91(%d) = %d\n", n, m);
        } else{
            m = 91;
            printf("f91(%d) = %d\n", n, m);
        }
        scanf("%d", &n);
    }
}

int main(){
    f91();
}