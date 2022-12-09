#include <stdio.h>

int main(){
    char *matriz[1][3] = {{"a", "b", "c"}};

    for (int i=0; i<1; i++){
        for (int j=0; j<3; j++){
            printf("%s ", matriz[i][j]);
        }
    }
}