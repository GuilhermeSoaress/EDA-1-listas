#include <stdio.h>
#include <stdlib.h>

int main (){
    int L,G,i,j,y=-1,t = 0,u=0,k=0,flagE=0,flagD=0,Glinha[1000];
    char Glado[1000],Lumber,C[2000],x = {'|'},z = {'|'};

        scanf("%d",&L);
        scanf("%d",&G);
        for(i=0;i<G;i++){
        scanf(" %c %d",&Glado[i],&Glinha[i]);}
        scanf(" %c",&Lumber);
        scanf("%s",&C); // inputs
       
do{
    
        char matriz[L][11]; 
   

        for(j= 0;j<L;j++){
        for (i= 0;i<11;i++){
        matriz[j][i]=' ';}}

        for (i=0;i<L;i++){
            matriz[i][4]= '|';
        }
        for (i=0;i<L;i++){
            matriz[i][5]='|';
        }
        for (i=0;i<L;i++){
            matriz[i][6]='|';
        } //cria a tronco e coloca espaço nos vetores vazios

       matriz[0][6] = x;
       matriz[0][4] = z;//salva o estado do tronco da versao anterior


 if (y>=0){
     
        if (C[y] == 'B'){
            // caso | vira > ou <    caso > ou < vira | 
            // flag informe se um galho foi acertado
            // u informa morte
            if(Lumber == 'D'){if(matriz[0][6]=='|'){x ='<';} else if(matriz[0][6]=='<'){if(flagD != 1 ){x='|';t++;}else u = 1 ;} }
        
        
        else if(Lumber == 'E'){if(matriz[0][4]=='|'){z='>';} else if(matriz[0][4]=='>') {if(flagE != 1){z='|';t++;} else u = 1 ;}}
        
        }
        
        }

        matriz[0][6] = x;
        matriz[0][4] = z;
        // coloca vazio no tronco destruido
        if (t>0){for(j = L-1 ; j>=L - t;j--){for(i=4;i<7;i++){matriz[j][i]=' ';}}}
       


        for(i=0;i<G;i++){
        
            if(Glado[i] == 'E'){ 
                for(j=1;j<4;j++){
                matriz[Glinha[i]-1-t][j] = '-';
                if(Glinha[i]-1-t==2){flagE = 1;} else flagE = 0;}
                

            }
            else if(Glado[i] == 'D'){ 
                for(j=7;j<10;j++){
                matriz[Glinha[i]-1-t][j] = '-';
                if(Glinha[i]-1-t==2){flagD = 1;} else flagD = 0;}// criação do galho e ativação da flag
        }}
        //troca o lado do lenhador caso n tenha galho do outro lado, k informa o beep
        if (y>=0){
    if(C[y] == 'T'){if(Lumber == 'D' && matriz[0][2] != '-' && matriz[1][2] != '-'){Lumber = 'E';} else if(Lumber == 'E' && matriz[0][8] != '-' && matriz[1][8] != '-'){Lumber = 'D';}else k = 1;}
        }
       
        if(Lumber == 'E'){ 
                matriz[0][2] = 'L';
                matriz[1][2] = 'L';

            }
            else if(Lumber == 'D'){ 
                matriz[0][8] = 'L';
                matriz[1][8] = 'L';//criação do lenhador
        }

   if(k == 0 && u == 0){
    printf("~~~~~~~~~~~\n");
    if(L>=5){
    for(j= 4 ;j>=0;j--){
        for (i= 0;i<11;i++){
        printf("%c",matriz[j][i]);}//outputs
        printf("\n");
        }}
        else {
    for(j= L-1 ;j>=0;j--){
        for (i= 0;i<11;i++){
        printf("%c",matriz[j][i]);}//outputs
        printf("\n");
        }}
      
        printf("~~~~~~~~~~~\n");}
        y++;//movimenta para a proxima letra da string 
      
        if(u == 1){ printf("**morreu**\n"); C[y] = 'h';}
        if(k==1){printf("**beep**\n");
        k=0;}}
   while( C[y] == 'T' || C[y] == 'B');//detecta o fim da string

}