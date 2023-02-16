#include <stdio.h>

int main(){
    int resultado[9];
    int resultado2[9];
    char winnerOitavas[9];
    int i;
    int letra=65;

    for(i=0;i<8;i++){
        scanf("%d%d",&resultado[i], &resultado2[i]);
        if(resultado[i]>resultado2[i]){
            winnerOitavas[i]=letra+i;
        }else winnerOitavas[i]=letra+i+1;

        letra++;
    }
    
    char winnerQuartas[5];
    int team1=0, team2=1;
    int win=1;
   for(i=0; i<4;i++){
        scanf("%d%d", &resultado[i],&resultado2[i]);
        if(resultado[i]>resultado2[i]){
            winnerQuartas[i]=winnerOitavas[team1];
        }else winnerQuartas[i]=winnerOitavas[team2];
        team1=win+i+1, team2=team1+1;
        win++;
   }
    char final[3];
    team1=0, team2=1;
    win=1;
    for(i=0;i<2;i++){
        scanf("%d%d", &resultado[i], &resultado2[i]);
        if(resultado[i]>resultado2[i]){
            final[i]=winnerQuartas[team1];
        }else final[i]=winnerQuartas[team2];
  
        team1=win+1+i, team2=team1+1;
        win++;
    }
    scanf("%d%d", &resultado[0], &resultado2[0]);
    if(resultado[0]>resultado2[0]){
        printf("%c\n", final[0]);

    }else printf("%c\n", final[1]);

}