#include<stdio.h>

int main(){
	int n, j, z, i, dif, teste = 1;
	scanf("%i", &n);
	
	while(n != 0){

		dif = 0;

		printf( "Teste %d\n", teste);
		teste++;
		
		for(i = 0; i < n; i++){
			scanf("%i %i", &j, &z);
			dif += j - z;
			printf("%i\n", dif);
		}
		printf("\n");
		scanf("%i", &n);
	}
	return 0;
}