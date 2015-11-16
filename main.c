#include<stdio.h>
#include<math.h>
int askValor(char * texto){
	printf("%s\n",texto);
	int val;
	scanf("%d",&val);
	return val;
};
int calcComIntervalo(){
	int intervalo = askValor("Qual o intervalo");
	int menor = askValor("Qual o menor Valor?");
	int maior = askValor("Qual o maior Valor?");
	int tam=(maior-menor)/intervalo;
	int pesos[tam];
	int i,val;
	for(i=0;i<tam;i++){
		printf("Quantos valores entre %d e %d?",i*intervalo,(i+1)*intervalo);	
		pesos[i]=askValor("");	
	}
		
}
int calcSemIntervalo(){
	double cv,dpadrao=0,dtotal;
	int i,tam = askValor("Quantos valores serão inseridos?");
			
	double dados[tam]; 
		for(i=0;i<tam;i++){
			scanf("%lf", &dados[i]);
			dtotal += dados[i];
		}

		double media = dtotal/(double)tam;
		printf("Media: %.2lf\n", media);
					
		for(i=0;i<tam;i++){
			int valor = dados[i]-media;
			dpadrao += valor*valor;
		}
		dpadrao = sqrt(dpadrao/tam);
		printf("Desvio padrao: %.2lf\n",dpadrao);
		cv = (sqrt(dpadrao/tam)/media)*100;
		printf("Coeficiente de variaçao: %.2lf %%\n", cv);
}

int main(int argc, char ** argv){
	int tam,i,intervalo=0;
	double media, dtotal;
			
			char resp=0;
			while(resp!='s'&&resp!='n'){
				printf("com intervalo?<s/n>\n");
				resp=getchar();
			}
			if(resp=='n')
				calcSemIntervalo();
			else
				calcComIntervalo();
				
	return 0;
}
