#include <stdio.h>
#include <stdlib.h>

int le_tamanho (void){
	int n;
	printf ("\n\nDigite o tamanho do vetor: ");
	scanf ("%d", &n);
	return n;	
}

void inverte (int n, int *vet){
	int j = n - 1, temp, i;
	for (i = 0; i < n / 2; i++){
		temp = vet[i];
		vet[i] = vet[j];
		vet[j] = temp;
		j--;
	}
}

int* aloca_vetor (int n){
	int* vet = (int*)(malloc(n*sizeof(int)));
	if (vet == NULL){
		printf ("\nErro na alocacao de memoria\n");
		system("pause");
		exit(1);
	}	
	return vet;
}

void preenche_vetor (int n, int* vet){
	int i;
	for (i = 0; i < n; i++){
		printf ("Informe o vet[%d]: ",i);
		scanf ("%d", &vet[i]);
	}	
}

void imprime_vetor (int n, int* vet){
	int i;
	for (i = 0; i< n; i++)
		printf ("\nO vetor invertido eh vet[%d]: %d ",i, vet[i]);

}

int main(){
	int *vet, n, i;
	while (1)
	{
		n = le_tamanho ();
		vet = aloca_vetor (n);
		preenche_vetor (n, vet);
		inverte (n, vet);
		imprime_vetor (n, vet);
		free(vet);
	}
	system ("pause");
}
