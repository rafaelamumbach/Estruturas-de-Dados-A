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
    for (i = 0; i < tamanho; i++) {
        printf("\nInforme o valor do vetor[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    escreve (tamanho, vet);
    free (vet);
    system ("pause");
}

void escreve (int tamanho, int* vet){
    int i;
    for (i = tamanho-1; i >= 0; i--)
    printf("\nImprimindo valores invertidos: %d\n", vet[i]);
    
}
