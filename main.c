#include<stdio.h>
#include<math.h>
int main(int argc, char ** argv){
	int tam, i;
	double media, cv;
			printf("Digite quantos dados são:\n");
			scanf("%d", &tam);

			double dados[tam], dtotal=0,dpadrao=0;
			
				for(i=0;i<tam;i++){
					scanf("%lf", &dados[i]);
					dtotal += dados[i];
				}

				media = dtotal/(double)tam;
				printf("Media: %.2lf\n", media);
							
				for(i=0;i<tam;i++){
					int valor = dados[i]-media;
					dpadrao += valor*valor;
				}
				printf("Desvio padrao: %.2lf\n", sqrt(dpadrao/tam));
				cv = (sqrt(dpadrao/tam)/media)*100;
				printf("Coeficiente de variaçao: %.2lf %%\n", cv);
			
	return 0;
}
