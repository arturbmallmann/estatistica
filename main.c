#include<stdio.h>

int main(int argc, char ** argv){
	int tam, i;
	char response;
	while( 'q' != (response = getchar())){
			printf("Digite quantos dados são:");
			scanf("%d", &tam);

			double dados[tam], dtotal;
			
				for(i=0;i<tam;i++){
					scanf("%ls", &dados[i]);
					dtotal += dados[i];
				}
			}
	return 0;
}
