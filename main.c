#include<stdio.h>
#include<string.h>
#include<math.h>

double coefvar(double acumulado,int tam,double media) {return sqrt(acumulado/(double)tam)/media * 100;}
double desvpad(double acumulado,int amostras){return amostras==0 ? 0 : sqrt(acumulado/(double)amostras);};
int askValor(char * texto){
	printf("%s\n",texto);
	int val;
	scanf("%d",&val);
	return val;
};
int dadosBrutos(double * dados,int tam){
		int i,dtotal=0;
		printf("insira os valores:\n");
		for(i=0;i<tam;i++){
			scanf("%lf", &dados[i]);
			dtotal += dados[i];
		}
		return dtotal;
}
void  resultados(double dpadrao,double media,int amostras){
	printf("A média é: %.2lf\n",media);	
	printf("O desvio padrão é: %.2lf\n",dpadrao);
	printf("O Coeficiente de variação é: %.2lf %%\n",coefvar(dpadrao,amostras,media));
}
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
		double aux = mediano - media;
		dpacumula+=aux*aux * pesos[i];
	}
//	printf("amostras %d dpacumula %lf\n",amostras,dpacumula);
	double dpadrao=desvpad(dpacumula,amostras);
	resultados(dpadrao,media,amostras);
}
int calcSemIntervalo(){
	double cv,dpacumula=0;
	int i,tam = askValor("Quantos valores serão inseridos?");
	int pesos[tam];	
	double dados[tam]; 
	int dtotal=dadosBrutos(dados,tam);//retorna a soma e grava o vetor
	char resp=0;
		while(resp!='s'&&resp!='n'){
			printf("Com pesos?<s/n>\n");
			resp=getchar();
		}
	int peso=0,amostras=tam;
	if (resp=='s'){
			amostras=0;
			for(i=0;i<tam;i++){
				printf("Quantos  valores  %.2lf?",dados[i]);
				pesos[i]=askValor("");
				amostras+=pesos[i];	
			}
		peso=1;
    }
	double media = dtotal/(double)amostras;
		for(i=0;i<tam;i++){
			double valor = dados[i]-media;	
			dpacumula += valor*valor * peso==1?pesos[i]:1;
		}
	//printf("amostras %d dpacumula %lf\n",amostras,dpacumula);
	double dpadrao = desvpad(dpacumula,amostras);
	resultados(dpadrao,media,amostras);
}

int main(int argc, char ** argv){
	int tam,i,intervalo=0;
	double media, dtotal;
			
			char resp=0;
			while(resp!='s'&&resp!='n'){
				printf("Com intervalo?<s/n>\n");
				resp=getchar();
			}
			if(resp=='n')
				calcSemIntervalo();
			else
				calcComIntervalo();
				
	return 0;
}
