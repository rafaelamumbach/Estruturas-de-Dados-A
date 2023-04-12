// Fazer um programa que leia dez números e escreva-os na ordem contrária à ordem de leitura. Exemplo:
// lê: 7 40 3 9 21 0 63 31 7 22
// escreve: 22 7 31 63 0 21 9 3 40 7
// Use alocação dinâmica. O programa deve ser estruturado nas seguintes funções:
// a. Main: aloca o vetor e faz a leitura do vetor
// b. Função 1: escreve o vetor na ordem contrária


#include <stdio.h>
#include <stdlib.h>

void escreve (int tamanho, int* vet);

int main(){
    int i, tamanho = 10;
    int* vet;
    vet = (int*)(malloc(tamanho*sizeof(int)));
    if (vet == NULL){
        printf("\nErro na alocacao de memoria\n");
        system("pause");
        exit(1);
    }

    //leitura do vetor, também na main:
    for ( i = 0; i < tamanho; i++){
        printf("\nInforme o valor do vetor[%d]\n", i);
        scanf("%d", &vet[i]);
    }

    escreve (tamanho, vet);
    free (vet);
    system ("pause");
}

void escreve (int tamanho, int* vet){
    int i;
    for (i = tamanho -1; i >= 0, i--;)
    printf("\nImprimindo valores invertidos: %d", vet[i]);
    }
