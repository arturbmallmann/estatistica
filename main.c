#include<stdio.h>
#include<math.h>
int main(int argc, char ** argv){
	int tam, i;
	double media, cv;
			printf("Digite quantos dados são:\n");
			scanf("%d", &tam);

			double dados[tam], dtotal=0,dpadrao=0;
			
				for(i=0;i<tam;i++){
					scanf("%ls", &dados[i]);
					dtotal += dados[i];
				}

				media = dtotal/tam;
				printf("Media: %.2ls\n", media);
				
				for(i=0;i<tam;i++){
					int valor = dados[i]-media;
					dpadrao += valor*valor;
				}
				printf("Desvio padrao: %.2ls\n", sqrt(dpadrao/tam));
				cv = (sqrt(dpadrao/tam)/media)*100;
				printf("Coeficiente de variaçao: %.2ls", cv);
			
	return 0;
}
