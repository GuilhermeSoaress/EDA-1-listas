#include <stdio.h>

int main(){
    char *arvore[5][3]= {{"|", "|", "|"},{"|", "|", "|"}, {"|", "|", "|"}, {"|", "|", "|"}, {"|", "|", "|"}};

    int tecla;
    scanf("%d", &tecla);
    if (tecla == 1){
        arvore[4][0] = "<";
    }

    for (int i=0; i<11; i++){   // printa os ~
        printf("~");
    }
    printf("\n");
    
    for (int i=0; i<5; i++){   // printa os |
        printf("    ");         
        for (int j=0; j<3; j++){
            printf("%s", arvore[i][j]);
        }
        printf("\n");
    }
    
    

    for (int i=0; i<11; i++){   // printa os ~
        printf("~");
    }
    printf("\n");

}