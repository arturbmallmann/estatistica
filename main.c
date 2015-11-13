#include<stdio.h>
#include<math.h>
int main(int argc, char ** argv){
	int tam, i;
	char response;
	double media, dpadrao = 0, dtotal = 0, cv;
	while( 'q' != (response = getchar())){
			printf("Digite quantos dados são:");
			scanf("%d", &tam);

			double dados[tam], dtotal,dpadrao;
			
				for(i=0;i<tam;i++){
					scanf("%ls", &dados[i]);
					dtotal += dados[i];
				}

				media = dtotal/tam;
				printf("Media: %.2ls", media);
				
				for(i=0;i<tam;i++){
					int valor = dados[i]-media;
					dpadrao += valor*valor;
				}
				printf("Desvio padrao: %.2ls", sqrt(dpadrao/tam));
				cv = (sqrt(dpadrao/tam)/media)*100;
				printf("Coeficiente de variaçao: %.2ls%", cv);
				
			}

				
			
	return 0;
}
