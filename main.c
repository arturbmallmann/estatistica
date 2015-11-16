#include<stdio.h>
#include<math.h>
int main(int argc, char ** argv){
	int tam, i,intervalo=0;
	double media, cv;
			
			char resp=0;
			while(resp!='s'&&resp!='n'){
				printf("com intervalo?<s/n>\n");
				resp=getchar();
			}
			if(resp=='s'){
				printf("qual o intervalo");
				scanf("%d",&intervalo);
			}
			printf("Digite quantos dados são:\n");
			scanf("%d", &tam);
			printf("Valores:\n");
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
