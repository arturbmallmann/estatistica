#include<stdio.h>
#include<math.h>
int main(int argc, char ** argv){
	int tam, i;
	char response;
	double media;
	while( 'q' != (response = getchar())){
			printf("Digite quantos dados são:");
			scanf("%d", &tam);

			double dados[tam], dtotal,dpadrao;
			
				for(i=0;i<tam;i++){
					scanf("%ls", &dados[i]);
					dtotal += dados[i];
				}

				media = dtotal/tam;
				printf("a media eh %.2ls", media);
				
				for(i=0;i<tam;i++){
					int valor = dados[i]-media;
					dpadrao = valor*valor;
				}
				printf("variancia: %.2ls", sqrt(dpadrao/tam));
			}
				media = dtotal/tam;
				printf("a media eh %ls", media);
				
			
	return 0;
}
