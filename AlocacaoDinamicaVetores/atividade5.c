// Fazer um programa que leia n números reais, armazene-os num vetor e escreva o percentual de números
// que são maiores que a média dos mesmos. O programa deve ser estruturado nas seguintes funções:
// a. Main: lê o tamanho do vetor, chama as outras funções e mostra o percentual na tela
// b. Função 1: aloca o vetor
// c. Função 2: faz a leitura do vetor
// d. Função 3: faz o cálculo da média
// e. Função 4: verifica o percentual de números que são maiores que a média
// Use alocação dinâmica. Não se esqueça de desalocar o vetor tão logo seja possível.

#include <stdio.h>
#include <stdlib.h>

int le_tamanho (void){
	int tamanho;
	printf ("\nInforme o tamanho do vetor: ");
	scanf ("%d", &tamanho);
	return tamanho;
}

float* aloca_vetor (int tamanho){
	float* vet = (float*)(malloc(10*sizeof(float)));
	if (vet == NULL)
	{
		printf ("\nErro na alocacao de memoria\n");
		system("pause");
		exit(1);
	}
	return vet;
}

void le_vetor (int tamanho, float* vet){
	int i;
	for (i = 0; i < tamanho; i++)
	{
		printf ("\nInforme o vet[%d]: ", i);
		scanf ("%f", &vet[i]);
	}	
}

float calcula_media (int tamanho, float* vet){
	int i;
	float soma = 0;
	for (i = 0; i < tamanho; i++)
		soma += vet[i]; // atribuição
	return (soma / tamanho);
}

float calcula_perc (int tamanho, float* vet, float media){
	int i, cont = 0;
	for (i = 0; i < tamanho; i++)
		if (vet[i]> media)
			cont++;
	float perc = (float) cont*100 / tamanho;
	return perc;
}

int main(){
	int tamanho;
	float* vet;
	tamanho = le_tamanho ();
	vet = aloca_vetor (tamanho);
	le_vetor(tamanho, vet);
	float media = calcula_media (tamanho, vet);
	printf ("\nA media eh %.2f", media);
	float perc = calcula_perc(tamanho, vet, media);
	printf ("\nO percentual de numeros maiores que a media eh %.2f\n", perc);
	free(vet);
	system ("pause");
}
