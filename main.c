#include<stdio.h>
#include<math.h>

#define coefvar(dpadrao,tam,media) ((sqrt(dpadrao/tam)/media) * 100) 
int askValor(char * texto){
	printf("%s\n",texto);
	int val;
	scanf("%d",&val);
	return val;
};
//double coeficienteVar(double media,double dp,
int calcComIntervalo(){
	int intervalo = askValor("Qual o intervalo?");
	int menor = askValor("Qual o menor Valor?");
	int maior = askValor("Qual o maior Valor?");
	int tam=(maior-menor)/intervalo;
	int pesos[tam];
	int i,amostras=0;
	double mediano,total=0,dpacumula=0;
	for(i=0;i<tam;i++){
		printf("Quantos valores para %d|--%d?",menor+i*intervalo,menor+(i+1)*intervalo);	
		pesos[i]=askValor("");	
		mediano=menor + i * intervalo + intervalo/2.0;
		total+=pesos[i]*mediano;
		amostras+=pesos[i];
	}
	double media=total/(double)amostras;
	for(i=0;i<tam;i++){
		mediano=menor + i * intervalo + intervalo/2.0;
		int aux = mediano - media;
		dpacumula+=aux*aux * pesos[i];
	}
	double dpadrao=sqrt(dpacumula/amostras);
	printf("A média é: %.2lf\n",total/(double)amostras);	
	printf("O desvio padrão é: %.2lf\n",dpadrao);
	printf("O Coeficiente de variação é: %.2lf\n",coefvar(dpadrao,amostras,media));
}
int calcSemIntervalo(){
	double cv,dpadrao=0,dtotal=0;
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
		cv = coefvar(dpadrao,tam,media);
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
